#include <stdio.h>

typedef struct {
	int data;
	Node *next;
	Node *prev;
}Node;

Node *head, *tail;

void Insert(Node *root, int _data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *cursor;
	newNode->data = _data;

	cursor = root->next;
	while (cursor)
	{

	}

}


int main()
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	
	head->next = tail;
	tail->next = NULL;
	tail->prev = head;
	head->prev = NULL;


	return 0;
}