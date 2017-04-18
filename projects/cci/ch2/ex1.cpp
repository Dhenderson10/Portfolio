#include <iostream>
#include <assert.h>
#include "linked_list.h"

using namespace std;

int main()
{
	//init list
	linked_list l1 = initList();

	//make a 1-2-2 list
	appendToList(&l1, 1);
	appendToList(&l1, 2);
	appendToList(&l1, 1);
	appendToList(&l1, 1);

	assert(l1.head->data == 1);
	assert(l1.head->nextNode->data == 2);
	assert(l1.head->nextNode->nextNode->data == 1);
	
	//test remove
	removeDuplicates(&l1);
	assert(l1.head->data == 1);
	assert(l1.head->nextNode->data == 2);
	assert(l1.head->nextNode->nextNode->data == 1);
	assert(l1.head->nextNode->nextNode->nextNode == NULL);


	//cases it doesn't work for
	//2-1-1-2
	//2-1-1-1
}
