#include <iostream>
#include <utility>
using namespace std;

class Node {
    public:
        char data;
        Node *next;
};

//add element in linked list
void insertElement(Node *&head, char data)
{
    //create new node
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

//Method for printing the list
void showList(Node* head)
{
    while (head != NULL)
    {
        cout << head -> data;
        head = head -> next;
    }
}

int main()
{
	//initialize first node of linked list
	Node *head = NULL;
	
	char element[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	
	for (int i = 0; i <= 5; i++)
	{
	    insertElement(head, element[i]);
	}
	
	showList(head);
	
	return 0;
}
