#include "stack_q.h"
#include <iostream>
using namespace std;

class MyQueue
{
	//private is default
	Stack enStack;
	Stack deStack;
	public:
		void enqueue(int x);
		int dequeue();
	 	void switch_stacks(); 
		MyQueue();
		int isEmpty(Stack* s);
	//Stack enStack;
	//Stack deStack;
};

//gonna need a constructor!
//set the stack heights to 0

int MyQueue::isEmpty(Stack* s)
{
	int flag = peek(s);
	if(flag == 0)
	{	
		//true
		return 1;
	}
	else
	{
		return 0;
	}
}

void MyQueue::enqueue(int x)
{
	//are both stacks empty or
	//is the enqueue stack used and dequeue stack empty
	if((enStack._stack_height == 0 && deStack._stack_height == 0) 	   	
	|| (enStack._stack_height > 0 && deStack._stack_height == 0))
	{	
		pushy(x, &enStack);
		int n = peek(&enStack);
		cout << "inserted " << n << " into queue \n";
	}
	else
	{
		switch_stacks();
		pushy(x, &enStack);
		int n = peek(&enStack);
		cout << "switched & inserted " << n << " into queue \n";
	}
	
}

int MyQueue::dequeue()
{
	int element;
	if((deStack._stack_height == 0 && enStack._stack_height == 0)
	|| (deStack._stack_height > 0 && enStack._stack_height == 0))
	{
		element = pop(&deStack);
		cout << "removed " << element << " from queue \n";
		return element;
	}
	else
	{
		switch_stacks();
		element = pop(&deStack);
		cout << "switched & removed " << element << " from queue \n";
		return element;
	}
}

void MyQueue::switch_stacks()
{
	int element;
	if(enStack._stack_height == 0 && deStack._stack_height == 0)
	{
		return;
	}
	else if(enStack._stack_height > 0 && deStack._stack_height == 0)
	{
		while(enStack._stack_height > 0)
		{
			element = pop(&enStack);
			pushy(element, &deStack);
		}
	}
	else if(enStack._stack_height == 0 && deStack._stack_height > 0)
	{	
		while(deStack._stack_height > 0)
		{
			element = pop(&deStack);
			pushy(element, &enStack);
		}
	}

}

MyQueue::MyQueue() 
{
	enStack._stack_height = 0;
	deStack._stack_height = 0;
	
}

int main()
{
	MyQueue q;
	q.enqueue(4);
	q.dequeue();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();
	q.enqueue(69);
	q.dequeue();

}



//stack is empty if 0
//when enqueue, just push, 
//when dequeue, transfer original stack to a new stack
//when you need to enqueue, transfer
//


