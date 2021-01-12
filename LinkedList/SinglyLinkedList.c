#include <stdio.h>

typedef struct {
	int data;
	struct Node* next;
}Node;

Node* head;

void AddFront(Node* _root, int _data) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = _data;
	newNode->next = _root->next;
	_root->next = newNode;
}

void RemoveFront(Node* _root) {
	Node* front = _root->next;
	_root->next = front->next;
	free(front);	
}

void showAll() {
	Node* cursor = head->next;
	while (cursor != NULL) {
		printf("%d ", cursor->data);
		cursor = cursor->next;
	}
	printf("\n");
}

int main() {

	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	AddFront(head, 1);
	AddFront(head, 3);
	AddFront(head, 4);
	AddFront(head, 2);
	AddFront(head, 6);
	AddFront(head, 10);
	showAll();
	RemoveFront(head);
	RemoveFront(head);
	showAll();
	AddFront(head, 9);
	showAll();



	return 0;
}