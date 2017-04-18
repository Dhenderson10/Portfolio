#include "linked_list.h"
#include <iostream>
#include <assert.h>
using namespace std;


Node* head = new Node;

void doubleAppend(Node *n)
{
	if(head->data == -1)
	{
		head->data = 0;
		head = n;
		head->nextNode = n;
		head->prevNode = n;
	}
	else
	{
		if(head->prevNode == NULL)
		{
			head->prevNode = n;
			head->nextNode = n;
			n->nextNode = head;
			n->prevNode = head;
		}
		else
		{
			printf("here\n");
			head->prevNode->nextNode = n;
			n->prevNode = head->prevNode;
			head->prevNode = n;
			n->nextNode = head;

		}
	}
}

void remove(Node* n)
{
	if(n->nextNode == NULL)
	{
		printf("return NULL");
	}
	else
	{

		Node* next_node = n->nextNode;
		n->prevNode->nextNode = n->nextNode;
		n->nextNode->prevNode = n->prevNode;
		n->nextNode = NULL;
		n->prevNode = NULL;

		/*if(next_node->nextNode == next_node)
		{
			next_node->nextNode = NULL;
			next_node->prevNode = NULL;

		}*/
	free(n);
	}

}

int main()
{
	//adding first node to double linked list
	Node* l1 = new Node;
	l1->nextNode = NULL;
	l1->prevNode = NULL;
	l1->data = 0;
	head->data = -1;
	assert(head->data == -1);
	doubleAppend(l1);
	assert(head->data == 0);
	assert(head->nextNode == l1);
	assert(l1->prevNode == head);
	
	//adding second node to double linked list
	Node* l2 = new Node;
	l2->nextNode = NULL;
	l2->prevNode = NULL;
	l2->data = 1;
		
	doubleAppend(l2);
	assert(head->data == 0);
	assert(head->nextNode == l2);
	assert(head->prevNode == l2);
	assert(l2->nextNode == head);
	assert(l2->prevNode == head);

	Node* l3 = new Node;
	l3->nextNode = NULL;
	l3->nextNode = NULL;
	l3->data = 2;

	doubleAppend(l3);
	assert(head == l1);
	assert(head->prevNode == l3);
	assert(head->nextNode == l2);
	assert(l3->nextNode == head);
	assert(l3->prevNode == l2);
	assert(l2->nextNode == l3);
	assert(l2->prevNode == head);
	
	remove(l3);
	assert(head->nextNode == l2);
	assert(head->prevNode == l2);
	assert(l2->nextNode == head);
	assert(l2->prevNode == head);

	remove(l2);
	assert(head == l1);
	assert(head->nextNode == l1);
	assert(head->prevNode == l1);
	
	remove(l1);
}

/*
int main()
{	//test init list
	linked_list test;
	test = initList();
	assert(test.head == NULL);


	//test appendToList 1 elem
	appendToList(&test, 1);
	assert(test.head != NULL);
	assert(test.head->data == 1);
	assert(test.head->nextNode == NULL);


	appendToList(&test, 2);
	assert(test.head->data == 1);
	assert(test.head->nextNode != NULL);
	assert(test.head->nextNode->data == 2);
	assert(test.head->nextNode->nextNode == NULL);

	appendToList(&test, 3);
	//1->2->3
	deleteNode(&test, 2);
	//1->3
	assert(test.head->data == 1);
	assert(test.head->nextNode != NULL);
	assert(test.head->nextNode->data == 3);
	assert(test.head->nextNode->nextNode == NULL);

	deleteNode(&test, 1);
	//3
	assert(test.head->data == 3);
	assert(test.head->nextNode == NULL);
	cout << "Testing complete\n";
}*/
