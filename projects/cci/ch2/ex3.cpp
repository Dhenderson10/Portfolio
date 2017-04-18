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
	appendToList(&l1, 3);
	appendToList(&l1, 4);
	assert(l1.head->data == 1);
	assert(l1.head->nextNode->data == 2);
	assert(l1.head->nextNode->nextNode->data == 3);
	assert(l1.head->nextNode->nextNode->nextNode->data == 4);
	

	deleteGivenNode(l1.head->nextNode->nextNode);

	assert(l1.head->data == 1);
	assert(l1.head->nextNode->data == 2);
	assert(l1.head->nextNode->nextNode->data == 4);
	assert(l1.head->nextNode->nextNode->nextNode == NULL);	
	
}

