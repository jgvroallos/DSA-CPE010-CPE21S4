#include <iostream>
#include <cstdlib>
#include <array>
using namespace std;

void shellSort(int arr[], int size)
{
    for (int i = size / 2; i > 0; i /= 2)
    {
        for (int j = i; j < size; j++)
        {
            int temp = arr[j];
            int k;
            for (k = j; k >= i && arr[k - i] > temp; k -= i)
            {
                arr[k] = arr[k - i];
            }
            arr[k] = temp;
        }
    }
}

void merge(int arr[], int left, int middle, int right) {
    int Half1 = middle - left +  1;
    int Half2 = right - middle;

    int leftArr[Half1], rightArr[Half2];

    for (int i = 0; i < Half1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < Half2; i++)
        rightArr[i] = arr[middle + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < Half1 && j < Half2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < Half1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < Half2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    return;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
    return;
}

int slice(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = low - 1; 
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; 
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]); 
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = slice(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
    return;
}
