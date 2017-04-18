#ifndef STACK_Q_H
#define STACK_Q_H
//added stack count
//need this in case stack is null
//CHANGES
//added _stack_height, you need it in case the stack is empty
//was implemented for exercise 3_4
//have not implemented for test or any exercises before


struct Node
{
	Node* _next;
	int _data;
};

struct Stack
{
	Node* _top;
	int _stack_height;
};

struct Item
{
	Item* _next;
	Item* _prev;
	int _data;
};

struct Queue
{
	Item* _first;
	Item* _last;
};

//Stack
int pop(Stack* s);
void pushy(int d, Stack* s);
int peek(Stack* s);

//Queue
void enqueue(int d, Queue* q);
int dequeue(Queue* q);

#endif
