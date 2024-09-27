#include <iostream>
#include <utility>
using namespace std;

class Node {
    public:
        char data;
        Node *next;
};

void listTraversal (Node* head)
{
    while (head != NULL)
    {
        cout << head -> data;
        head = head -> next;
    }
}

void insertHead(Node *&head, char data)
{
    Node *newNode = new Node;
    newNode -> data = data;
    newNode -> next = head;
    head = newNode;
}

void insertList(Node *&head, char data, int position)
{
    Node *newNode = new Node;
    newNode -> data = data;
    
    if (position == 1) {
        newNode -> next = head;
        head = newNode;
        return;
    }
    
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp -> next;
    }
    
    if (temp == nullptr) {
        cout << "Error: Not in range." << endl;
        return;
    }
    
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void insertEnd(Node *&head, char data)
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

void deleteNode(Node *&head, char data)
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
    
    insertEnd(head, 'C');
    insertEnd(head, 'P');
    insertEnd(head, 'E');
    insertEnd(head, '1');
    insertEnd(head, '0');
    insertEnd(head, '1');
    
    cout << "Original Linked List, displayed using list traversal: ";
    listTraversal(head);
    cout << endl;
    
    /*
    // Table 3-3. Items A-E
    insertHead(head, 'Y');
    cout << "\nInserted a new node as head. Updated Linked List: ";
    listTraversal(head);
    cout << endl;
    
    insertList(head, 'T', 4);
    cout << "\nInserted a new item between the list. Updated Linked List: ";
    listTraversal(head);
    cout << endl;
    
    insertEnd(head, '2');
    cout << "\nInserted a new item the end of the list. Updated Linked List: ";
    listTraversal(head);
    cout << endl;
    
    deleteNode(head, '0');
    cout << "\nDeleted an item in the list. Updated Linked List: ";
    listTraversal(head);
    cout << endl;
    */
    

    // Table 3-3. Item F
    insertHead(head, 'G');
    cout << "\nInserted 'G' as new head node: ";
    listTraversal(head);
    cout << endl;
    
    insertList(head, 'E', 4);
    cout << "\nInserted 'E' within the list: ";
    listTraversal(head);
    cout << endl;
    
    deleteNode(head, 'C');
    deleteNode(head, 'P');
    cout << "\nDeleted items 'C' and 'P' from the list: ";
    listTraversal(head);
    cout << endl;


    return 0;
}
