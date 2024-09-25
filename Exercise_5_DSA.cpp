#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int const maxSize = 4;

void display (queue <string> pl)
{
    while (true)
    {
        if(!pl.empty())
        {
            cout << pl.front() << endl;
            pl.pop();
        }
        
        else
        {
            cout << "\nStack is empty." << endl;
            break;
        }
    }
}

int main()
{
    queue <string> pl;
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    
    display(pl);
    
    pl.push("HTML");

    return 0;
}
