using namespace std;

template <typename T>
class Node
{
    public:
        T data;
        Node *next;
};

template <typename T>
Node<T> *new_node(T newData)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

Node<char> *linearLS(Node<char> *head, char dataFind)
{
    Node<char> *current = head;
    int i = 0;
    while (current != nullptr)
    {
        i++;
        if (current->data == dataFind)
        {
            cout << "Searching is successful.";
            return current;
        }
        current = current -> next;
    }
    cout << "Searching is unsuccessful.";
    return nullptr;
}

Node<char>* getMid(Node<char>* start, Node<char>* end)
{
    if (!start) return nullptr;

    Node<char>* slow = start;
    Node<char>* fast = start;

    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node<char>* binaryLSearch(Node<char>* head, char item) {
    Node<char>* start = head;
    Node<char>* end = nullptr;

    while (start != end) {
        Node<char>* mid = getMid(start, end);

        if (!mid)
        {
            return 0;
        }

        if (mid->data == item) {
            cout << "Searching is successful.";
            return 0;
        } else if (mid->data < item) {
            start = mid->next; // Search in the right half
        } else {
            end = mid; // Search in the left half
        }
    }

    cout << "Searching is Unsuccessful.";
    
    return 0;
}