#include <iostream>
#include <queue>
using namespace std;

//Display function
void display(queue<string> pl)
{
    while (!pl.empty()) 
    {
        cout << pl.front() << endl;
        pl.pop();
    }
}

int main() 
{
    queue<string> pl;
    const int maxSize = 3;

    cout << "Pushing elements into queue: " << endl;

    // Array of languages to add to the queue
    string languages[] = {"C++", "Java", "Python", "JavaScript"};

    //Loop for pushing elements in the queue
    for (int i = 0; i < 4; i++)
    {
        if (pl.size() < maxSize)
        {
            pl.push(languages[i]);
            cout << languages[i] << endl;
        } 
        else 
        {
            cout << "Queue is full." << endl;
        }
    }

    cout << "\nCurrent elements in the queue:" << endl;
    display(pl);

    return 0;
}
