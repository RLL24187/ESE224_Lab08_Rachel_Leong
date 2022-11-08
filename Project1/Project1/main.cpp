#include <stdio.h>
#include <iostream>
using namespace std;

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

template <typename Type>
struct Node
{
	Type value;
	Node* next;

	Node() : next(nullptr) {}
	Node(Type x, Node* next = nullptr) : value(x), next(next) {}
	~Node() {}
};


template <typename Type>
Node<Type>* createLinkedList(Type* arr, int n)
{
	if (n <= 0)
	{
		cout << "please check your input!" << endl;
		return NULL;
	}

	Node<Type>* head = new Node<Type>(arr[0]);
	Node<Type>* tmp = head;

	for (int i = 1; i < n; i++)
	{
		tmp->next = new Node<Type>(arr[i]);
		tmp = tmp->next;
	}
	return head;
}


template <typename Type>
void printLinkedList(Node<Type>* head)
{
	while (head)
	{
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

template <typename Type>
void reverse(Node<Type>*&head) {
	Node<Type>* curr = head;
	Node<Type>* prev = nullptr;
	Node<Type>* nextNode;
	while (curr != nullptr) {
		// iterate nodes
		nextNode = curr->next;
		// set the current node's next as prev
		curr->next = prev;
		// set prev to curr
		prev = curr;
		// set curr to next node
		curr = nextNode;
	}
	// set prev to the new head
	head = prev;
}

int main() {

	int arr[] = { 1,2,3,4,5,6,7 };
	cout << "create linked list from array:" << endl;
	Node<int>* node = createLinkedList(arr, SIZE(arr));
	printLinkedList(node);

	cout << "reverse linked list:" << endl;
	// TODO
	// you should reverse linked list and print it
	reverse(node);
	printLinkedList(node);
	return 0;
}