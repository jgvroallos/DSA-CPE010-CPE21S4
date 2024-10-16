//#include "nodes.h"
#include <iostream>
using namespace std;

void linearSearch(int dataset[], int max_size, int item)
{
    int i = 0;
    while (i <= max_size)
    {
        if(dataset[i] == item)
        {
            cout << "Searching is successful.";
            return;
        }
        i++;
    }
    cout << "Searching is unsuccessful.";
    return;
}

void binarySearch(int dataset[], int max_size, int item)
{
    int bot = 0;
    int mid;
    int top = max_size - 1;
    
    while (bot <= top)
    {
        mid = (bot + top) / 2;
        
        if (dataset[mid] == item)
        {
            cout << "Search element is found!";
            return;
        }
        else if (item < dataset[mid])
        {
            top = mid - 1;
        }
        else
        {
            bot = mid + 1; 
        }
    }
    cout << "Search element is not found.";
}