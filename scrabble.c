#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    //if score 1 is greater than score 2 player 1 wins
    if (score1 > score2)
    {
        printf("Player 1 Wins! %i\n", score1);
    }
    //if score 2 is greater than score 1 player 2 wins
    else if (score1 < score2)
    {
        printf("Player 2 Wins! %i\n", score2);
    }
    //if both scores equal, tie
    else
    {
        printf("Tie! %i %i\n", score1, score2);
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int score = 0;
    int x = 0;


    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //Convert all letters to uppercase
        word[i] = toupper(word[i]);
        //Deduct 65 from int value of letter to correspond with alphabetical order
        x = word[i] - 65.0;
        //Exclude punctuation
        if (x >= 0 && x <= 25)
        {
            //Add to total score
            score = score + POINTS[x];
        }

    }

    return score;

}
//


