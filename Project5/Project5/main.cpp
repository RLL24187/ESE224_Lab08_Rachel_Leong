/*lab8_5
*/
#include <iostream>
#include <stdio.h>
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

// merges 2 sorted lists
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

// sort list using mergeSort and recursion by changing ptrs
template <typename Type>
void mergeSort(Node<Type>*& head)
{
    Node<Type>* left;
    Node<Type>* right;

    // Base case: if head has length 0 or 1 it's already sorted
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // split list into a left and right half
    split(head, &left, &right);

    // use recursion to sort halves
    mergeSort(left);
    mergeSort(right);

    // merge the sorted lists together
    head = merge(left, right);
}

template <typename Type>
Node<Type>* merge(Node<Type>*& left, Node<Type>*& right)
{
    Node<Type>* result = new Node<Type>();

    // base cases: if either are null then return the other one
    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }

    // if left data is less than right data, recursively call merge on left->next
    if (left->value <= right->value) {
        result = left;
        result->next = merge(left->next, right);
    }
    else { // otherwise on right->next
        result = right;
        result->next = merge(left, right->next);
    }
    return (result);
}

// split nodes into left and right halves using fast/slow pointer strat
// if length odd, extra node goes in left list
template <typename Type>
void split(Node<Type>* head, Node<Type>** left, Node<Type>** right)
{
    Node<Type>* fast = head -> next;
    Node<Type>* slow = head;

    // fast goes ahead 2 nodes, slow goes ahead 1
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // slow will be at the midpoint or right before the midpoint in the list, when fast is null
    // because fast goes twice as fast
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

template <typename Type>
Node<Type>* merge3Lists(Node<Type>* list1, Node<Type>* list2, Node<Type>* list3) {
    Node<Type>* newList = new Node<Type>();
    // run mergeSort on all lists
    mergeSort(list1);
    mergeSort(list2);
    mergeSort(list3);
    // call mergeSortedList from lab 2 on list1 and list2, then call it again on the result and list3
    newList = mergeSortedList(list1, list2);
    newList = mergeSortedList(newList, list3);
    // result is the merged 3
    return newList;
}

// Driver program to test
// above functions
int main()
{

    int arr1[] = { 2,4,6,8 };
    int arr2[] = { 0, 1, 3, 5, 7, 9 };
    int arr3[] = { -2, -1, 10, 11, 14, 20 };

    Node<int>* list1 = createLinkedList(arr1, SIZE(arr1));
    Node<int>* list2 = createLinkedList(arr2, SIZE(arr2));
    Node<int>* list3 = createLinkedList(arr3, SIZE(arr3));

    cout << "First linked list is:" << endl;
    printLinkedList(list1);
    cout << "Second linked list is:" << endl;
    printLinkedList(list2);
    cout << "Third linked list is:" << endl;
    printLinkedList(list3);
    // Merge all lists
    Node<int>* merged = merge3Lists(list1, list2, list3);

    // TODO
    // you should merge three sorted linked list, then print it
    cout << "Merged linked list: \n";
    printLinkedList(merged);

    return 0;
}