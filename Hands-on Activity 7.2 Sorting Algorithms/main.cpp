#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting-algo.h"
using namespace std;

const int max_size = 100;
int dataset[max_size];

int main()
{
    srand(time(0));
    for (int i = 0; i < max_size; i++)
    {
        dataset[i] = rand() % 100;
    }
    
    for (int i = 0; i < max_size; i++)
    {
        cout << dataset[i] << " ";
    }
    
    shellSort(dataset, max_size);
    //mergeSort(dataset, 0, max_size - 1);
    //quickSort(dataset, 0, max_size - 1);
    
    size_t arrSize = sizeof(dataset) / sizeof(dataset[0]);
    
    cout << "\n\nSorted: " << endl;
    for (size_t i = 0; i < arrSize; i++)
    {
        cout << dataset[i] << " ";
    }
    
    return 0;
}
