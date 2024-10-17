#include <iostream>
using namespace std;

int seqArray(int arr[], int size, int item)
{
    int count = 0;
    for (int i = 0; i < size; i++) 
    {
        count++;
        if (arr[i] == item) 
        {
            return count;
        }
    }
    return count;
}

struct Node 
{
    int data;
    Node* next;
};

Node* new_node(int data) 
{
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

int seqList(Node* head, int item)
{
    int count = 0;
    Node* current = head;
    while (current != nullptr) 
    {
        count++;
        if (current->data == item) 
        {
            return count;
        }
        current = current->next;
    }
    return count;
}

int main() 
{
    // Array
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int item = 18;

    int countInArray = seqArray(arr, size, item);
    cout << "Number of item/s in the array: " << comparisonsArray << endl;

    // Linked List
    Node* head = new_node(15);
    head->next = new_node(18);
    head->next->next = new_node(2);
    head->next->next->next = new_node(19);
    head->next->next->next->next = new_node(18);
    head->next->next->next->next->next = new_node(0);
    head->next->next->next->next->next->next = new_node(8);
    head->next->next->next->next->next->next->next = new_node(14);
    head->next->next->next->next->next->next->next->next = new_node(19);
    head->next->next->next->next->next->next->next->next->next = new_node(14);

    int countInList = seqList(head, item);
    cout << "Number of item/s in the linked list: " << comparisonsList << endl;

    return 0;
}
