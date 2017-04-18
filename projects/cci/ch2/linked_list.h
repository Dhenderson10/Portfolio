#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node
{
	Node* nextNode;
	Node* prevNode;
	int data;
};


struct linked_list
{
	Node *head;
};

void doubleAppend(Node* n);



int isPalindrome(linked_list* listy);
Node* find_bad_node(linked_list* listy);
int list_to_num(linked_list* listy);
linked_list initList();
void appendToList(linked_list* listy, int data);
void deleteNode(linked_list* listy, int badData);
void removeDuplicates(linked_list *listy);
Node* findElementK(linked_list* listy, int elem);
void deleteGivenNode(Node* n);
linked_list addLists(linked_list* l1, linked_list* l2);
#endif
