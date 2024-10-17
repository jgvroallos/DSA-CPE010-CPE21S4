#include <iostream>
using namespace std;

int recurBinary(int dataset[], int low, int high, int item) {
    if (low > high) {
        return -1; 
    }

    int mid = (low + high) / 2;

    if (dataset[mid] == item) {
        return mid;
    } 
    else if (dataset[mid] < item) 
    {
        return recurBinary(dataset, mid + 1, high, item); 
    } 
    else 
    {
        return recurBinary(dataset, low, mid - 1, item); 
    }
}

int main() 
{
    int dataset[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18}; 
    int max_size = sizeof(dataset) / sizeof(dataset[0]); 
    int item = 8; 

    int result = recurBinary(dataset, 0, max_size - 1, item); 

    if (result != -1) 
    {
        cout << "Element " << item << " found at index " << result << ".\n";
    } 
    else 
    {
        cout << "Element " << item << " not found in the array.\n";
    }

    return 0;
}
