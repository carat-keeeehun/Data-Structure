// CSE221 Assignment 1
// unsit 20131218 parkkeehun

#ifndef LinkedList_h
#define LinkedList_h

#include <typeinfo>
#include <iostream>

using namespace std;

template <typename Type>
class Node
{
public:
	int item;
	Node<Type> *next;
};

/* Single Linked List */
template <typename Type>
class LinkedList
{
private:
	int length;
	Node<Type> *head;
public:
	// Constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Get the value located at index
	Type Get(const int index);

	// Add val at head
	void AddAtHead(const Type& val);

	// Add val at index
	void AddAtIndex(const int index, const Type& val);

	// Delete an element located at index
	void DeleteAtIndex(const int index);

	// Delete val in linked list
	void DeleteValue(const Type& val);

	// Move the first element of val to head
	void MoveToHead(const Type& val);

	// Rotate the linked list right by steps times
	void Rotate(const int steps);

	// Reduce value that repeats multiple times
	void Reduce();

	// Swap every two neighboring elements
	void Swap();

	// Return the number of elements in the linked list
	int Size();

	// Delete all elements from the linked list
	void CleanUp();
	
	// Print the list
	void Print();

};

/* Constructor */
template <typename Type>
LinkedList<Type>::LinkedList()
{
  this->length = 0;
  this->head = NULL;
}

/* Destructor */
template <typename Type>
LinkedList<Type>::~LinkedList()
{
  delete[] head;
}

/* Retrieve the value located at index-th element in linked list. */
template <typename Type>
Type LinkedList<Type>::Get(const int index)
{
  Node<Type> *A = new Node<Type>;
  int item_;
  A = this->head;

  // Invalid index
  if( index < 0 || index >= this->length )
    return -1;

  for(int i=0; i<index; i++)
    A = A->next;

  item_ = A->item;
  A = NULL;
  delete A;
  return item_;
}

/* Insert an element containing val at the head of the linked list. */
template <typename Type>
void LinkedList<Type>::AddAtHead(const Type& val)
{ 
  if(this->length==0)
  {
    Node<Type> *B = new Node<Type>;
    B->item = val;
    B->next = NULL;
    this->head = B;
    B = NULL;
    delete B;
  }
  else
  {
    Node<Type> *B = new Node<Type>;
    B->item = val;
    B->next = head;
    this->head = B;
    B = NULL;
    delete B;
  }
  this->length++;
}

/* Insert an element containing val to a specific location such that
 * after the insertion, the val is located at index. */
template <typename Type>
void LinkedList<Type>::AddAtIndex(const int index, const Type& val)
{
  if(index==0) 
    AddAtHead(val);

  else if(index > 0 && index <= this->length)
  {
    Node<Type> *C = new Node<Type>; // index
    Node<Type> *D = new Node<Type>; // input node
    C = this->head;
    D->item = val;

    if(index==this->length)
    {
      for(int i=0; i<index-1; i++)
      {
	C = C->next;
	if(i==index-2)
	{
	  C->next = D;
	  D->next = NULL;
	}
      }
    }
    else
    {
      for(int i=0; i<index; i++)
      {
        if(i==index-1)
        { 
          D->next = C->next;
          C->next = D;
	  break;
        }
        C = C->next;
      }
    }
    C = NULL;
    D = NULL;
    delete C;
    delete D;
    this->length++;
  }
  else cout << "Invalid index" << endl;
}

/* Delete an element located at index. */
template <typename Type>
void LinkedList<Type>::DeleteAtIndex(const int index)
{
  if(this->length==0)
    cout << "There is no Node" << endl;

  if(index>=0 && index < this->length)
  {
    Node<Type> *C = new Node<Type>; // index
    Node<Type> *temp = new Node<Type>;
    C = this->head;

    if(index==0)
    {
      temp = this->head;
      head = head->next;
      temp = NULL;
    }

    else
    {  
      for(int i=0; i<index; i++)
      {
        if(i==index-1)
        {
          temp = C->next;
          C->next = C->next->next;
          temp = NULL;
          break;
        }
        C = C->next;
      }
    }
    delete temp;
    C = NULL;
    delete C;
    this->length--;
  }
}

/* Delete an element that contains val. If list has multiple
 * elements, then delete the first encountered one only. */
template <typename Type>
void LinkedList<Type>::DeleteValue(const Type& val)
{
  int index_;
  Node<Type> *D = new Node<Type>;
  D = this->head;

  for(int i=0; i < this->length; i++)
  {
    if(D->item == val)
      {
	index_ = i;
	break;
      }
    D = D->next;
  }
  D = NULL;
  delete D;
  DeleteAtIndex(index_);
}

/* Move the first element containing val to the head of the list */
template <typename Type>
void LinkedList<Type>::MoveToHead(const Type& val)
{
  for(int i=0; i < this->length; i++)
  {
    if(val == Get(i))
    {
      DeleteAtIndex(i);
      AddAtHead(val);
      break;
    }
  }
}

/* Rotate the linked list right by steps times. */
template <typename Type>
void LinkedList<Type>::Rotate(const int steps)
{
  // Only consider positive steps.
  if(steps<0) return;

  int n = steps;
  int item_;

  while(n>0)
  {
    item_ = Get(this->length - 1);
    DeleteAtIndex(this->length - 1);
    AddAtHead(item_);
    n--;
  }
}

/* Delete all duplicates except only one element that you
 * encounter first */
template <typename Type>
void LinkedList<Type>::Reduce()
{
  for(int i=0; i< this->length-1; i++)
  {
    for(int j=i+1; j< this->length; j++)
      {
	if(Get(i)==Get(j))
	  DeleteAtIndex(j);
      }
  }
}

/* Swap every two neighboring elements */
template <typename Type>
void LinkedList<Type>::Swap()
{
  if(this->length %2 == 0) // even number of elements
  {
    int n;

    for(int i=0; i< this->length; i+=2)
    {
      n = Get(i+1);
      DeleteAtIndex(i+1);
      AddAtIndex(i,n);
    }
  }
  else if(this->length %2 == 1) // odd number of elements
  {
    int n;

    for(int i=0; i< this->length-1; i+=2)
    {
      n = Get(i+1);
      DeleteAtIndex(i+1);
      AddAtIndex(i,n);
    }
  }
}

/* Return the number of elements in the linked list. */
template <typename Type>
int LinkedList<Type>::Size()
{
  return this->length;
}

/* Delete all elements from the linked list. */
template <typename Type>
void LinkedList<Type>::CleanUp()
{
  int n = this->length;

  while(n>0)
  {
    DeleteAtIndex(0);
    n--;
  }
}

/* Print out all current elements in the linked list in order.
 * e.g)  (4,2,5,3,6,1,5,2) */
template <typename Type>
void LinkedList<Type>::Print()
{
  cout << "(";
  for(int i=0; i< this->length; i++)
    {
      cout << Get(i);
      if(i == this->length-1)
	cout << ")" << endl;
      else
	cout << ",";
    }
}


#endif
