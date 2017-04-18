#include <iostream>
#include <assert.h>
#include "linked_list.h"

using namespace std;



int main()
{
	linked_list l1 = initList();
	appendToList(&l1, 7);	
	appendToList(&l1, 1);   
	appendToList(&l1, 6);   
	appendToList(&l1, 6);
	appendToList(&l1, 1);	
	appendToList(&l1, 7);	

	
	int num	= isPalindrome(&l1);
	cout << num << "\n";


	//returns the correct node
}
