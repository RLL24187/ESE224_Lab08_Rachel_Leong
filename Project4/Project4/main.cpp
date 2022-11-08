/*lab8_4
*/
#include <stdio.h>
#include <iostream>
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))


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

// removes duplicates for a sorted list
template <typename Type>
Node<Type>* removeDuplicates(Node<Type>*& head)
{
	Node<Type>* noDupes = new Node<Type>(head->value);
	Node<Type>* noDupesHead = noDupes;
	while (head) {
		// since it's already sorted, if the current value doesn't equal the current value in dupes
		// then add the value to noDupes, otherwise keep moving
		if (noDupes->value != head->value) {
			noDupes->next = new Node<Type>(head->value);
			noDupes = noDupes->next;
		}
		head = head->next;
	}
	// head = noDupesHead;
	return noDupesHead;
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	int arr[] = { 0,1,3,3,4,4,5,6,6,6,6,6,6,7 };
	Node<int>* head = createLinkedList(arr, SIZE(arr));
	cout << "Original Linked List: ";
	printLinkedList(head);

	// TODO
	// you should remove the duplicate elements in the sorted linked list, then print it
	cout << "Linked list after removing Duplicates: ";
	head = removeDuplicates(head);
	printLinkedList(head);

	return 0;
}

