#include <iostream>
#include <assert.h>
#include "linked_list.h"

using namespace std;



int main()
{
	linked_list l1 = initList();
	linked_list l2 = initList();
	appendToList(&l1, 7);	//A
	appendToList(&l1, 1);   //B
	appendToList(&l1, 6);   //C
	appendToList(&l1, 5);	//D
	appendToList(&l1, 9);	//E

	assert(l1.head->data == 7);						//A
	assert(l1.head->nextNode->data == 1);					//B
	assert(l1.head->nextNode->nextNode->data == 6);				//C
	assert(l1.head->nextNode->nextNode->nextNode->data == 5);		//D
	assert(l1.head->nextNode->nextNode->nextNode->nextNode->data == 9);	//E
	assert(l1.head->nextNode->nextNode->nextNode->nextNode->nextNode == NULL);
	
	l1.head->nextNode->nextNode->nextNode->nextNode->nextNode = l1.head->nextNode->nextNode;

	
	assert(l1.head->nextNode->nextNode->nextNode->nextNode->nextNode == l1.head->nextNode->nextNode);

	Node* n = find_bad_node(&l1);
	assert(n->data == 6);

	//returns the correct node
}
