#include <iostream>
#include <string>
using namespace std;

class Job 
{
    private:
        int id;
        string username;
        int pages;
    
    public:
        Job(int id, string username, int pages) 
        {
            this->id = id;
            this->username = username;
            this->pages = pages;
        }
    
        int getId() 
        {
            return id;
        }
    
        string getUserName() 
        {
            return username;
        }
    
        int getPages() 
        {
            return pages;
        }
};

class Printer 
{
    private:
        Job** queue;
        int capacity;
        int size;
        int front;
        int rear;
    
    public:
        Printer(int capacity) 
        {
            this->capacity = capacity;
            this->size = 0;
            this->front = 0;
            this->rear = 0;
            queue = new Job*[capacity];
        }
    
        ~Printer() 
        {
            for (int i = 0; i < size; i++) 
            {
                delete queue[(front + i) % capacity];
            }
            delete[] queue;
        }
    
        void addJob(int id, string username, int pages) 
        {
            if (size == capacity) 
            {
                cout << "Printer queue is full.\n";
                return;
            }
            queue[rear] = new Job(id, username, pages);
            rear = (rear + 1) % capacity;
            size++;
        }
    
        void processJobs() 
        {
            if (size == 0) 
            {
                cout << "No jobs to process.\n";
                return;
            }
            for (int i = 0; i < size; i++) 
            {
                Job* job = queue[(front + i) % capacity];
                cout << "Processing job " << job->getId()
                     << " for " << job->getPages()
                     << " pages by " << job->getUserName() << ".\n";
            }
            for (int i = 0; i < size; i++) 
            {
                delete queue[(front + i) % capacity];
            }
            size = 0;
            front = 0;
            rear = 0;
        }
};

int main() 
{
    Printer printer(5);

    printer.addJob(1, "Grace", 5);
    printer.addJob(2, "Stacey", 3);
    printer.addJob(3, "Lance", 2);
    printer.addJob(4, "Vincent", 4);
    printer.addJob(5, "Dorothy", 1);

    printer.processJobs();

    return 0;
}
