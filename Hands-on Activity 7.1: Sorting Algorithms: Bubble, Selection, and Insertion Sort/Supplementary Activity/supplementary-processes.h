#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int max_size = 100;
const int candidates = 5;

// random generation of vote counts
void voteGen(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % candidates + 1;
    }
}

//looping and printing items within the array
void outputLoop(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//total votes per candidate
void voteCount(int arr[], int size, int numVotes[])
{
    for (int i = 0; i < size; i++)
    {
        numVotes[arr[i] - 1]++;
    }
}

//tally of votes
int showResults(int numVotes[], int candidates)
{
    int maxVote = numVotes[0];
    int winner = 1;
    
    for (int i = 1; i < candidates; i++) 
    {
        if (numVotes[i] > maxVote) 
        {
            maxVote = numVotes[i];
            winner = i + 1;
        }
    }
    return winner;
}
