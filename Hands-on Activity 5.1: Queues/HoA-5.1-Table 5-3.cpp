#include <iostream>
using namespace std;

class Queue 
{
    private:
        int *arr;           
        int front;          
        int rear;           
        int capacity;       
        int size;          
    
    public:
        Queue(int cap) 
        {
            capacity = cap;
            arr = new int[capacity];
            front = 0;
            rear = -1;
            size = 0;
        }
    
        ~Queue() 
        {
            delete[] arr;
        }
    
        void enqueue(int element) 
        {
            if (isFull()) 
            {
                cout << "Queue is full! Cannot enqueue." << element << endl;
                return;
            }
    
            rear = (rear + 1) % capacity;
            arr[rear] = element;
            size++;
            cout << element << " added to the queue." << endl;
        }
    
       
        void dequeue() 
        {
            if (isEmpty()) 
            {
                cout << "Queue is empty! Cannot dequeue." << endl;
                return;
            }
    
            cout << arr[front] << " removed from the queue." << endl;
            front = (front + 1) % capacity;
            size--;
        }
    
       
        int peek() const 
        {
            if (isEmpty()) 
            {
                cout << "Queue is empty!" << endl;
                return -1;  
            }
            return arr[front];
        }
    
        
        bool isEmpty() const 
        {
            return size == 0;
        }
    
       
        bool isFull() const 
        {
            return size == capacity;
        }
    
       
        int getSize() const 
        {
            return size;
        }
    
       
        void display() const 
        {
            if (isEmpty()) 
            {
                cout << "Queue is empty!" << endl;
                return;
            }
    
            cout << "Queue elements: ";
            for (int i = 0; i < size; i++) 
            {
                cout << arr[(front + i) % capacity] << " ";
            }
            cout << endl;
        }
};

int main() 
{
    Queue test(5);  

    test.enqueue(10);
    test.enqueue(20);
    test.enqueue(30);
    test.enqueue(40);
    test.enqueue(50);

    cout << "Front element: " << test.peek() << endl;
    cout << "Current size: " << test.getSize() << endl;

    test.display();

    test.dequeue(); 
    test.dequeue();  

    cout << "Front element after two dequeues: " << test.peek() << endl;
    cout << "Current size after dequeues: " << test.getSize() << endl;

    test.display();

    test.enqueue(60); 
    cout << "Front element after adding 60: " << test.peek() << endl;

    test.display();

    return 0;
}
