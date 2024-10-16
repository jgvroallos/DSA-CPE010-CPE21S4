#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"
#include "supplementary-processes.h"
using namespace std;

int main()
{
    int arr[max_size];
    int numVotes[candidates] = {};
    
    voteGen(arr, max_size);
    
    cout << "Unsorted array of votes: \n";
    outputLoop(arr, max_size);
    
    insertionSort(arr, max_size);
    
    cout << "\n Sorted array of votes: \n";
    outputLoop(arr, max_size);
    
    voteCount(arr, max_size, numVotes);
    
    cout << "Vote Tally: \n";
    for (int i = 0; i < candidates; i++)
    {
        cout << "Candidate #" << i + 1 << ": " << numVotes[i] << " votes" << endl;
    }
    
    int winner = showResults(numVotes, candidates);
    cout << "Winning candidate: Candidate #" << winner;
    
    return 0;
}
