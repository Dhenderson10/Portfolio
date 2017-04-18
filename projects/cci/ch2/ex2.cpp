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

	Node* n = findElementK(&l1, 3);
	cout << n->data << "\n";
}

