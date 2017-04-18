//improvmenets
//should move globals to struct
//should add extra layer of overhead, and seperate ints
//would be good to go through this again
//implement pop_at when this code is fixed
#include "stack_q.h"
#include <iostream>
#include <assert.h>
using namespace std;
//linked list of stacks
//this is like a linked list head
struct stack_set
{
	Stack s;
	stack_set* next_s;
	stack_set* prev_s;
	int stack_push_loc;
	int stack_pop_loc;
};

struct SetOfStacks
{
	stack_set* stacks;  
	int amount_of_stacks;
};

//here are the rest

//Gloabl
//this is the amount of stacks you can have before 
//a new one is made
int STACK_LIMIT = 3;
//this is the counter, it keeps track when a new stack
//needs to be made in the stack
int STACK_COUNT = 0;

//create a stack
SetOfStacks init_stack()
{
	SetOfStacks new_s;
	new_s.amount_of_stacks = 0;
	new_s.stacks->s._top = NULL;
	//new_s.stacks->next_s = NULL;
	//new_s.stacks->prev_s = NULL;
	return new_s;
}

void s_push(stack_set* s, int d)
{
	int _count = s->stack_push_loc;
	stack_set* stack_section = s;
	if(s->stack_push_loc == (s->stack_pop_loc + 1) && STACK_COUNT >= 0)
	{
		//pushing on next stack, make sure pop knows
		printf("here");
		s->stack_pop_loc++;
		
	}
	while(_count > 0)
	{
		stack_section = stack_section->next_s;
		_count--;
	}
	Stack* newest_stack = &stack_section->s;
	pushy(d, newest_stack);
	STACK_COUNT++;
	if(STACK_COUNT >= STACK_LIMIT)
	{
		stack_section->next_s = new stack_set;
		STACK_COUNT = 0;
		s->stack_push_loc++;
		s->stack_pop_loc++;
	}
}

int s_pop(stack_set* s)
{
	//int _count = s->stack_pop_loc;
	stack_set* stack_section = s;
	if(STACK_COUNT <= 0)
	{
		STACK_COUNT = STACK_LIMIT + 0;
		s->stack_pop_loc--;
		s->stack_push_loc--;
	}
	int _count = s->stack_pop_loc;
	while(_count != 0)
	{
		stack_section = stack_section->next_s;	
		_count--;
	}
	Stack* newest_stack = &stack_section->s;
	int n = pop(newest_stack);
	STACK_COUNT--;
	return n;
}

//this implementation is done without rolling over,
//i.e. its okay to have some empty stacks

int pop_at(stack_set* s, index)
{
}

int main()
{
	//s_pop(), s_push(), init_stack()
	//SetOfStacks sos = init_stack();
	//test init function
	stack_set sos;
	sos.s._top = NULL;
	sos.stack_pop_loc = 0;
	sos.stack_push_loc = 0;
	
	s_push(&sos, 1);
	printf("push stack count %d\n", STACK_COUNT);
	s_push(&sos, 2);
	printf("push stack count %d\n", STACK_COUNT);
	s_push(&sos, 3);
	printf("push stack count %d\n", STACK_COUNT);
	s_push(&sos, 4);
	printf("push stack count %d\n", STACK_COUNT);
	s_push(&sos, 5);
	printf("push stack count %d\n", STACK_COUNT);
	s_push(&sos, 6);
	printf("push stack count %d\n", STACK_COUNT);
	printf("Initial STACK_COUNT %d\n", STACK_COUNT);
	int k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	k =  s_pop(&sos);	
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	s_push(&sos, 6);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	s_push(&sos, 5);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	s_push(&sos, 4);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	s_push(&sos, 3);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	s_push(&sos, 2);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	s_push(&sos, 1);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	s_push(&sos, 1);
	s_push(&sos, 6);
	s_push(&sos, 3);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	s_push(&sos, 2);
	s_push(&sos, 3);
	s_push(&sos, 4);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	s_push(&sos, 4);
	s_push(&sos, 4);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	k =  s_pop(&sos);
	printf("%d STACK_COUNT %d\n", k, STACK_COUNT);
	
}
