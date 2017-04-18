#include <math.h> //pow
#include <assert.h>
#include <iostream>
#include <stdlib.h> //strtol
#include "linked_list.h"
using namespace std;





linked_list initList()
{
	linked_list emptyList;
	emptyList.head = NULL;
	return emptyList;

}

void appendToList(linked_list* listy, int data)
{
	Node* tmp = new Node;
	Node* currentNode;
	tmp->data = data;
	tmp->nextNode = NULL;

	if(listy->head == NULL)
	{
		listy->head = tmp;
	}
	else
	{
		currentNode = listy->head;
		while(currentNode->nextNode) //was trying to access out of reach shit
		{			    //with currentNode->next != NULL
			currentNode = currentNode->nextNode;
		}
		currentNode->nextNode = tmp;
	}
}

void deleteNode(linked_list* listy, int badData)
{
	Node* currentNode = listy->head;
	Node* prevNode;

	//check head
	if(listy->head->data == badData)
	{
		listy->head = currentNode->nextNode;
		currentNode->nextNode = NULL;
		free(currentNode);
	}
	while( currentNode->nextNode)
	{	
		prevNode = currentNode;
		currentNode = currentNode->nextNode;
		if(currentNode->data == badData)
		{	
			//fix pointers
			prevNode->nextNode = currentNode->nextNode;
			//deallocate Node
			currentNode->nextNode = NULL;
			free(currentNode);
		}
	}
	//node not found
}

void removeDuplicates(linked_list* listy) //head should be passed, then next node
{
	Node* currentNode = listy->head;
	Node* prevNode = listy->head;
	Node* i = currentNode->nextNode;

	while(currentNode->nextNode)
	{

		if(currentNode->data == i->data )
		{
			currentNode->nextNode = i->nextNode;
			i->nextNode = NULL;
			free(i);
			i = currentNode->nextNode; 
		}
			while(prevNode->nextNode)
			{
				if(i->data == currentNode->data)
				{
					if(i->nextNode == NULL)
					{
						cout << "a\n";
						prevNode->nextNode = NULL;
						free(i);
						i = currentNode;

					}
					else
					{
						prevNode->nextNode = i->nextNode;
						i->nextNode = NULL;
						//free i?
						i = prevNode->nextNode;
					}
				}
				else
				{
					prevNode = i;
					if(i->nextNode != NULL)
					{
						i = i->nextNode;
					}
	
				}
			}
		currentNode = currentNode->nextNode;
		prevNode = currentNode->nextNode;
		i = currentNode->nextNode;
	}	
}




Node* findElementK(linked_list* listy, int elem) //pass 1 for last element of list
{
	Node* currentNode = listy->head;
	int count = 1;
	int i = 1;
	while(currentNode->nextNode)
	{
		count++;
		currentNode = currentNode->nextNode;
	}
	
	//check if asking for head
	if(count == elem)
	{
		return listy->head;
	}
	//check if asking for last
	else if(elem == 1)
	{
		return currentNode;
	}
	else
	{
		currentNode = listy->head;
		int k = count - (elem - 1);
		while(i != k)
		{
			i++;
			currentNode = currentNode->nextNode;


		}
		return currentNode;
	}
}

void deleteGivenNode(Node* n)
{

	if(n->nextNode == NULL)
	{
		cout << "ERROR: function cannot delete last node\n";	
	}
	else
	{
		Node* afterN = n->nextNode;
	
		n->data = afterN->data;
		n->nextNode = afterN->nextNode;
		afterN->nextNode = NULL;
		free(afterN);
	}
}



linked_list addLists(linked_list* l1, linked_list* l2)
{
	linked_list l3 = initList();

	int num = list_to_num(l1) + list_to_num(l2);
	
	//get integer length
	int numCount = num;
	int digit = 0;
	int numToInsert = 0;
	int i = 0;
	while(numCount)
	{
		numCount /= 10;
		digit++;

	}
	
	printf("%d\n", num);
	//we have digit amount of digits 
	while(digit > 0)
	{
		digit--;
		numToInsert = (num / (int)pow(10, i)) % 10;
		appendToList(&l3, numToInsert);
		i++;
	}

	return l3;
}

int list_to_num(linked_list* listy)
{
	Node* currentNode = listy->head;
	int* numArray = new int[20];
	int i = 0;
	int num = 0;
	while(currentNode->nextNode)
	{
		numArray[i] = currentNode->data;
		currentNode = currentNode->nextNode;
		i++;
	}

	numArray[i] = currentNode->data;
	while(i >= 0)
	{
		num = num + (numArray[i] * pow(10, i));
		i--;
	}
	return num;
}

Node* find_bad_node(linked_list* listy)
{
	Node* currentNode = listy->head;
	Node** nodeArray = new Node*[20];
	int i = 0;
	int array_length = 0;
	int counter = 0;

	while(counter != 1)
	{
		counter = 0;
		nodeArray[i] = currentNode;
		currentNode = currentNode->nextNode;
		i++;
		array_length++;
		for(int j = 0; j < array_length; j++)
		{
			if(currentNode == nodeArray[j])
			{
				counter++;
			}
		}
	}
	return currentNode;
}

int isPalindrome(linked_list* listy)
{
	Node* currentNode = listy->head;
	int* nums = new int[20]; //list size constant or could have it passed
	int i = 0;

	while(currentNode->nextNode)
	{
		nums[i] = currentNode->data;
		currentNode = currentNode->nextNode;
		i++;
	}
	nums[i] = currentNode->data;

	for(int j = 0; i > 0; i--, j++)
	{
		if(nums[i] != nums[j])
		{
			return 0;
		}
	}
	return 1;
}
