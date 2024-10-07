#include <iostream>
#include <utility>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head -> data << " ";
        head = head -> next;
    }
}

void enqueue(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode -> data = data;
    newNode -> next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node *temp = head;
    while (temp -> next != nullptr) {
        temp = temp -> next;
    }
    
    temp->next = newNode;
}


void dequeue(Node *&head, int data)
{
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    if (head -> data == data) {
        Node *temp = head;
        head = head -> next;
        delete temp;
        return;
    }
    
    Node *temp = head;
    while (temp -> next != nullptr) {
        if (temp -> next -> data == data) {
            Node *nodeDelete = temp -> next;
            temp -> next = temp -> next -> next;
            delete nodeDelete;
            return;
        }
        temp = temp -> next;
    }
}

int main()
{
    Node *head = NULL;
    
    enqueue(head, 10);
    enqueue(head, 20);
    enqueue(head, 30);
    enqueue(head, 40);
    enqueue(head, 50);
    
    display(head);
    cout << endl;
    
    dequeue(head, 10);
    dequeue(head, 20);
    dequeue(head, 30);
    
    display(head);
}
