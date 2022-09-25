#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {   // if name entered matches candidate name, add vote
        if(strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }

    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Sort candidates so that the highest number of votes is in the first position in the array
    for (int i = 0; i < candidate_count; i++)
    {
        int winner = i;
        for (int j = winner + 1; j < candidate_count; j++)
        {
            if(candidates[winner].votes < candidates[j].votes)
            winner = j;
        }
        if (winner != i)
        {
        string temp = candidates[i].name;
        candidates[i].name = candidates[winner].name;
        candidates[winner].name = temp;

        int tempi = candidates[i].votes;
        candidates[i].votes = candidates[winner].votes;
        candidates[winner].votes = tempi;
        }

    }

    //print candidate in first postion
    printf("%s\n", candidates[0].name);
    
    //check if other candidates have same score, if so print
    for (int i = 1; i < candidate_count; i++)
    {
    if (candidates[i].votes == candidates[0].votes)
    printf("%s\n", candidates[i].name);
    }
    return;
}