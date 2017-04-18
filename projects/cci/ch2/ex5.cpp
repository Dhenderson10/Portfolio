#include <iostream>
#include <assert.h>
#include "linked_list.h"

using namespace std;



int main()
{
	linked_list l1 = initList();
	linked_list l2 = initList();
	appendToList(&l1, 7);	
	appendToList(&l1, 1);
	appendToList(&l1, 6);
	
	appendToList(&l2, 5);	
	appendToList(&l2, 9);	
	appendToList(&l2, 2);

	linked_list l3 = addLists(&l1, &l2);
	assert(l3.head->data == 2);
	assert(l3.head->nextNode->data == 1);
	assert(l3.head->nextNode->nextNode->data == 9);
	assert(l3.head->nextNode->nextNode->nextNode == NULL);
}	



