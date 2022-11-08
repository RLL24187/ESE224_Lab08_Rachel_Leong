/*lab8_3*/
#include <iostream>
#include <stdio.h>
using namespace std;

/* Link list node */
template <typename Type>
struct Node
{
	Type value;
	Node* next;

	Node() : next(nullptr) {}
	Node(Type x, Node* next = nullptr) : value(x), next(next) {}
	~Node() {}
};


/* Function to print linked list */
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

// judge if a linked list has a cycle and if yes, cut it and print out the linkedlist after cutting
template <typename Type>
bool judgeAndCut(Node<Type>*& head) {
	// list doesn't exist
	if (!head) return false;

	Node<Type>* slow = head;
	Node<Type>* fast = head; // create two references that both refer to start of list
	// iterate through the linked list
	while (1) {
		slow = slow->next;
		if (fast->next) {
			fast = fast->next->next;
		}
		else {
			return false; // hit a null, no loop
		}
		if (!slow || !fast) {
			return false; // one of the pts is null --> no loop
		}
		if (slow == fast) {
			// found a cycle, must cut the cycle
			slow->next = nullptr;
			printLinkedList(head);
			return true; // found a cycle
		}
	}
}

// Driver Code
int main()
{
	Node<int>* head = new Node<int>(50);
	head->next = new Node<int>(20);
	head->next->next = new Node<int>(15);
	head->next->next->next = new Node<int>(4);
	head->next->next->next->next = new Node<int>(10);
	head->next->next->next->next->next = new Node<int>(100);
	/* Create a cycle for testing */
	head->next->next->next->next->next->next = head->next->next;

	// TODO
	// you should judge if a linked list has a cycle, and cut the cycle if yes, then print it
	cout << "A linked list is created such that there is a cycle going from 100 to 15." <<
		"It was initialized as 50, 20, 15, 4, 10, 100. End result should be 50, 20, 15, 4, 10.\n" <<
		"After cutting: \n";
	judgeAndCut(head);
	return 0;
}
