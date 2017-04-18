//This exercise required modifying the original functions
//and I wanted to keep everything seperate for later
//review, so the theory and implmentation is all here
//and its quite simple, thanks to the clever use of 
//structures


#include "stack_q.h"
#include <assert.h>
#include <iostream>
//global min_stack
Stack min_stack;

int min(Stack* s)
{
	if(min_stack._top != NULL)
	{
		return peek(&min_stack);
	}
	else
	{
		printf("no stacks!");
		return -1;
	}
}

int main()
{
	//we will implement outside
	//function, for simplicity
	//this implmentation requires
	//modifying the original push/pop functions
	Stack s1;
	s1._top = NULL;
	//keep a min_stack
	min_stack._top = NULL;

	//we add an element
	pushy(4, &s1);
	//since min_stack is empty, it gets the same element
	if(min_stack._top == NULL)
	{
		pushy(4, &min_stack);
	}

	//now we add a smaller element
	pushy(3, &s1);
	if(peek(&s1) < peek(&min_stack))
	{
		pushy(3, &min_stack);
	}
	
	assert(peek(&s1) == 3);
	assert(peek(&min_stack) == 3);
	
	//now we add a bigger element then the current min
	//which is the top of min_stack
	
	push(5, &s1);
	//since the if statement will turnout to be false
	//we don't add 5, and remember how a stack works
	//you can only pop off the top elements
	//so the stack can never be alone with 5
	//and the min stack will always have the lowest value
	if(peek(&s1) < peek(&min_stack))
	{
		pushy(5, &min_stack);
	}

	//pop works in a similar way
	//the test cases would take a sec to write
	//out, but lets just explain
	//
	//
	//we pop off an element, and we save its data,
	//we then compare that saved data to the return
	//value of a peek call on the min stack
	//if they are equal, we call pop on the min_stack
	//now the min_stack is accurat relative to the
	//regular stack
}


