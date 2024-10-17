#include <iostream>
using namespace std;

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

int countArray(int arr[], int size, int item) 
{
    int count = 0;
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == item) 
        {
            count++;
        }
    }
    return count;
}

int countList(Node* head, int item) 
{
    int count = 0;
    Node* current = head;
    while (current != nullptr) 
    {
        if (current->data == item) 
        {
            count++;
        }
        current = current->next;
    }
    return count;
}

int main() 
{

    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int item = 18; 


    int occurArray = countArray(arr, size, item);
    cout << "Occurrences of " << item << " within the array: " << occurArray << endl;


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


    int occurList = countList(head, item);
    cout << "Occurrences of " << item << " within the linked list: " << occurList << endl;


    Node* current = head;
    while (current != nullptr) 
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
