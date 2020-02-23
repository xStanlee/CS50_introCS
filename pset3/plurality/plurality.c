#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates shouldn't use
#define MAX 9

// Candidates have name and vote count new struct
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


        for (int i = 0; i < voter_count; i++)
            {
                    string name = get_string("Vote: ");


                // Check for invalid vote
                if (vote(name))
                {
                    printf("Vote for: %s\n", name);
                }else{
                    printf("Invalid vote.\n");
                }
            }
    //printf("Checking how manny votes in index 2" %i", candidates[2].votes);
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    bool is_vote = false;
        for(int i = 0; i < candidate_count; i++){ //(strcmp(s1, s2) == 0)
            if(strcmp(candidates[i].name,  name) == 0){
            candidates[i].votes++;
            is_vote = true;
            break;
        }
        else{
            is_vote = false;
        }
}
            return is_vote;
}
// Print the winner (or winners) of the election
void print_winner(void)
{
    int winner = 0;
    string winnerOne;
    for (int i = 0; i < candidate_count; i++){
        for (int j = 1; j < candidate_count; j++ ){
            if(candidates[i].votes > candidates[j].votes){
                winner = candidates[i].votes;
                winnerOne = candidates[i].name;
            }
            else if(candidates[i].votes < candidates[j].votes){
                winner = candidates[j].votes;
                winnerOne = candidates[j].name;
            }
        }
    }
    printf("The winner is %s and he/she've %i votes", winnerOne, winner);
}
