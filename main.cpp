#include <iostream>
#include <cstdlib>
#include <time.h>
#include "searching.h"
#include "nodes.h"

using namespace std;

const int max_size = 50;

int dataset[max_size];

int main()
{
    srand(time(0));
    for (int i = 0; i < max_size; i++)
    {
        dataset[i] = rand();
    }
    /*
    for (int i = 0; i < max_size; i++)
    {
        cout << dataset[i] << " ";
    }
    */
    
    /*
    int item = rand();
    cout << "Randomized item to find in dataset: " << item << endl;
    
    linearSearch(dataset, max_size, item);
    */
    
    
    Node<char> *name1 = new_node('V');
    Node<char> *name2 = new_node('i');
    Node<char> *name3 = new_node('n');
    Node<char> *name4 = new_node('c');
    Node<char> *name5 = new_node('e');
    Node<char> *name6 = new_node('n');
    Node<char> *name7 = new_node('t');
    
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    name7->next = NULL;
    
    /*
    linearLS(name1, 'n');
    */
    
    //binarySearch(dataset, max_size, 5);
    
    binaryLSearch(name1, 'c');

    return 0;
}