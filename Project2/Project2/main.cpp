/*lab8_2*/
#include <iostream>
#include <stdio.h>

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
Node<Type>* mergeSortedList(Node<Type>* list1, Node<Type>* list2) {
    Node<Type>* newNode = new Node<Type>();
    Node<Type>* curr = newNode;
    Node<Type>* prev = nullptr;
    Node<Type>* iterator1 = list1;
    Node<Type>* iterator2 = list2;

    while (iterator1 && iterator2) {
        prev = curr;
        if (iterator1->value <= iterator2->value) {
            curr->value = iterator1->value;
            curr->next = new Node<Type>();
            iterator1 = iterator1->next;
        }
        else {
            curr->value = iterator2->value;
            curr->next = new Node<Type>();
            iterator2 = iterator2->next;
        }
        curr = curr->next;
    }
    // add in leftover list1 if any
    while (iterator1) {
        prev = curr;
        curr->value = iterator1->value;
        curr->next = new Node<Type>();
        iterator1 = iterator1->next;
        curr = curr->next;
    }
    // add in leftover list2 if any
    while (iterator2) {
        prev = curr;
        curr->value = iterator2->value;
        curr->next = new Node<Type>();
        iterator2 = iterator2->next;
        curr = curr->next;
    }
    prev->next = nullptr;
    // return head of new list
    return newNode;
}


int main() {
    int arr1[] = { 3, 4, 7, 9 };
    int arr2[] = { 2, 4, 6, 12, 14 };
    Node<int>* list1 = createLinkedList(arr1, SIZE(arr1));
    Node<int>* list2 = createLinkedList(arr2, SIZE(arr2));
    cout << "First sorted List: " << endl;
    printLinkedList(list1);
    cout << "Second sorted list: " << endl;
    printLinkedList(list2);

    // TODO
    // you should merge two sorted linked list and print it
    Node<int>* mergedList = mergeSortedList(list1, list2);
    cout << "Third sorted list: " << endl;
    printLinkedList(mergedList);

    return 0;
}