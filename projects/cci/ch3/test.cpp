#include "stack_q.h"
#include <assert.h>
#include <iostream> //printf
using namespace std;


int main()
{
	//STACK TESTING
	//create a stack
	//s1._top should be set to Null
	Stack s1;
	s1._top = NULL;

	//make sure it is empty
	assert(s1._top == NULL);
	//push 2 down onto the stack
	pushy(2, &s1);
	//test to see that the stack is not NULL
	assert(s1._top != NULL);
	//test to seet that the stack holds 2
	assert(s1._top->_data == 2);

	//push 3 onto the stack
	pushy(3, &s1);
	assert(s1._top->_data == 3);
	assert(s1._top->_next->_data == 2);

	//pop 3 off the stack
	int n = pop(&s1);
	//make sure that 2 is now the top
	assert(s1._top->_data == 2);
	//check the popped node
	assert(n == 3);
	//test peek function, peek at s1
	int dat = peek(&s1);
	assert(dat == 2);
	//pop again
	pop(&s1);
	assert(s1._top == NULL);
	cout << dat <<"\n";


	//QUEUE
	Queue q1;
	q1._first = NULL;
	q1._last = NULL;

	enqueue(1, &q1);
	assert(q1._first == q1._last);
	assert(q1._first->_data == 1);
	assert(q1._last->_data == 1);

	enqueue(2, &q1);
	assert(q1._first != q1._last);
	assert(q1._last->_data == 2);
	assert(q1._first->_data == 1);

	
	enqueue(3, &q1);
	assert(q1._first != q1._last);
	assert(q1._last->_data == 3);
	assert(q1._first->_data == 1);
	assert(q1._first->_next == NULL);
	assert(q1._first->_prev->_data == 2);
	assert(q1._last->_next->_data == 2);
	assert(q1._last->_prev == NULL);
	printf("Testing Complete!\n");


}
