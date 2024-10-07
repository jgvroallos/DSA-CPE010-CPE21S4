#include <iostream>
#include <queue>
using namespace std;

//Display function
void display(queue<string> classRec)
{
    while (!classRec.empty()) 
    {
        cout << classRec.front() << endl;
        classRec.pop();
    }
}

int main() 
{
    queue<string> classRec;
    string students[] = {"Adia", "Bona", "Bonifacio", "Cabilan", "Carag"};

    //Pushing array contents to queue

    for (int i = 0; i < 5; i++)
    {
        classRec.push(students[i]);
        //cout << students[i] << endl;
    }
    
    //Display contents of the queue
    cout << "Current elements in the queue: " << endl;
    display(classRec);
    cout << endl;
    
    //Operations for queues
    cout << "classRec.empty() : " << classRec.empty() << "\n";
    cout << "classRec.size() : " << classRec.size() << "\n";
    cout << "classRec.front() : " << classRec.front() << "\n";
    cout << "classRec.back() : " << classRec.back() << "\n";
    cout << "classRec.pop() : ";
    classRec.pop();
    
    cout << "\n\n";
    display(classRec);

    return 0;
}
