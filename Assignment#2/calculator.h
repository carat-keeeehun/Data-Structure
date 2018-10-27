#ifndef CALCULATOR_H
#define CALCULATOR_H

//
// Simple calculator using Stack
//
// CSE231 Fall 2018
//
#include "stack.h"
#include <cstring>
#include <iostream>
using namespace std;

int level(char k);
int typ(char k);
int pow(int a, int b);
double cal(double a, double b, char c);

double Eval(char* in)
{
  int sizei = strlen(in);

  char *p = new char[sizei*2];
  int i = 0;
  int count = 0;
  int f = 0;

  Stack<char> ss; // for conversion to postfix
  Stack<char> s;  // for calculator

  while(count<sizei)
  {
    if(*in=='('){
      ss.Push(*in);
      f = 1;
      in++;
    }
    else if(*in==')'){
	f = 0;
      while(ss.Top()!='('){      
	p[i++] = ss.Top();
	ss.Pop();
      }
      ss.Pop();
      in++;
    }
    else if(*in=='+'||*in=='-'||*in=='*'||*in=='/'){
      if((*in=='-'&&i==0)||(*in=='-'&&f==1)){
	p[i++] = 'm';
	f=0;
      }
      else if(ss.IsEmpty()){
	ss.Push(*in);
	f=0;
      }
      else if(level(ss.Top())<level(*in)){
	ss.Push(*in);
	f=0;
      }
      else{
	f=0;
	while(level(ss.Top())>=level(*in)){
	  p[i++] = ss.Top();
          ss.Pop();
	  if(ss.IsEmpty()) break;
	}
	ss.Push(*in);
      }      
      in++;
    }    
    else if(*in>='0' && *in<='9'){
	f=0;
      while(*in>='0' && *in<='9'){
	p[i++] = *in;
	in++;
      }
      p[i++]= ' ';
      // distinguish numbers in postfix
    }
    else in++;
    count++;	
  }
  while(ss.IsEmpty()==0){
    p[i++] = ss.Top();
    ss.Pop();
  }
  p[i] = '\0';

  i = 0;

  cout << "postfix of input" << endl;
  while(1){
    cout << p[i++];
    if(p[i]=='\0') break;}
  cout << endl;

  // so far, converse infix into postfix

  i--;
  int z = 0;
  int result = 0;
  int a = 0;
  double *A = new double[sizei];
  for(int j=0; j++; j<sizei) A[j]=0;
  int *flag = new int[sizei];
  for(int j=0; j++; j<sizei) flag[j]=-1;

  cout << endl;
  cout << "====================================" << endl;
  cout << endl;

  while(i>=-5)
  {
    while(a>1&&flag[a-1]==0&&flag[a-2]==0){
      a--;
      A[a-1] = cal(A[a],A[a-1],s.Top());
      A[a] = 0;
      flag[a] = -1;
      s.Pop();
      for(int j=0; j<a-1; j++)flag[j]--;
    }
    if(typ(p[i])==0){
      s.Push(p[i--]);
      for(int j=0; j<a; j++)flag[j]++;
    }
    else if(typ(p[i])==1){
      while(typ(p[i])==1){
	A[a] = A[a] + (p[i--]-'0')*pow(10,z);
	z++;
      }
      if(p[i]=='m'){
	A[a] = -A[a];
	i--;
      }
      flag[a] = 0;
      a++;
      z = 0;
    }
    
    else i--;
  }

  result = A[a-1];

  delete p;
  delete A;
  delete flag;

  return result;
}

// several functions

int level(char k){
  if(k=='('||k==')') return 0;
  else if(k=='+'||k=='-') return 1;
  else if(k=='*'||k=='/') return 2;
  else return -1;
}

int typ(char k){
  if(k=='+'||k=='-'||k=='*'||k=='/') return 0;
  else if (k>='0'&&k<='9') return 1;
  else return -1;
}

int pow(int a, int b){
  if(b==0) return 1;
  else return a*pow(a,b-1);
}

double cal(double a, double b, char c){
  switch(c){
    case '+' : return a+b;
    case '-' : return a-b;
    case '*' : return a*b;
    case '/' : return a/b;
  }
}


#endif
