
template<class type>
Stack<type>::~Stack()
{
	delete [] array;
}

template<class type>
type& Stack<type>::Top()
{	
	if(top < 0) assert(false);
	return array[top];
}

template<class type>
void Stack<type>::Push(const type& item)
{
	if(top == capacity-1) // double capacity
	{
		type* temp = new type[capacity*2];
		
		for(int i=0; i<capacity; i++)
		{
			temp[i] = array[i];
		}
		
		type* ret = array;		
		array = temp;
		delete [] ret;
		
		capacity *= 2;
	}
	
	array[ ++top ] = item;
}

template<class type>
void Stack<type>::Pop()
{
	if(top >= 0) top--;
}

template<class type>
bool Stack<type>::IsEmpty() const
{
	if(top < 0) return true;
	else return false;	
}
