#include <stdlib.h> //NULL is in here!
#include "stack_q.h"
//using namespace std;

int pop(Stack* s)
{
	if(s->_stack_height == 0)
	{
		return 0;
	}
	else
	{
		Node* popped = s->_top; //save top
		int popped_num = popped->_data;
		s->_top = s->_top->_next; //allocate new top
		//if you called new, call delete!
		//free is used if you call malloc
		delete(popped);
		s->_stack_height--;
		return popped_num; //return popped data
	}

}


void pushy(int d, Stack* s)
{
	Node* newItem = new Node;
	newItem->_data = d;
	newItem->_next = s->_top;
	s->_top = newItem;
	s->_stack_height++;
}

int peek(Stack* s)
{
	if(s->_stack_height == 0)
	{
		return 0;
	}
	return s->_top->_data;
}

void enqueue(int d, Queue* q)
{
	Item* newItem = new Item;
	newItem->_data = d;
	newItem->_next = NULL;
	newItem->_prev = NULL;
	if(q->_first == NULL)
	{
		q->_last = newItem;
		q->_first = newItem;
	}
	else
	{
		//last item prev pointer points to newItem
		q->_last->_prev = newItem;
		//newItem next pointer points to last item
		newItem->_next = q->_last;
		//newItem is pointed to by last pointer
		q->_last = newItem;
	}
	
}

int dequeue(Queue* q)
{
	if(q->_first == NULL)
	{
		return NULL;
	}
	else
	{
		Item* done = q->_first;
		int done_num = done->_data;
		q->_first = q->_first->_next;
		delete(done);
		return done_num;
	}
}
