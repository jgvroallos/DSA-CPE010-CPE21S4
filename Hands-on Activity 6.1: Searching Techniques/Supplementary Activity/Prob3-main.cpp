#include <iostream>
using namespace std;

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

int main() 
{
    int dataset[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18}; 
    int max_size = sizeof(dataset) / sizeof(dataset[0]);
    int item = 8; 

    binarySearch(dataset, max_size, item); 

    return 0;
}
