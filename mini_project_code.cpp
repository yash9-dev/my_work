 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    int candidateID;
    char name[20];
    int votes;
} Candidate;

typedef struct {
    char userID[10];
    int voted; // 0 if not voted, 1 if voted
} Voter;

void setupElection(Candidate candidates[], int *numCandidates) {
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", numCandidates);

    for (int i = 0; i < *numCandidates; ++i) {
        candidates[i].candidateID = i + 1;
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Election setup complete!\n");
}

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("\nCandidates:\n");
    for (int i = 0; i < numCandidates; ++i) {
        printf("%d. %s\n", candidates[i].candidateID, candidates[i].name);
    }
}

int authenticateAdmin() {
    char username[10], password[10];
    printf("Enter Admin username: ");
    scanf("%s", username);

    if (strcmp(username, "admin") != 0) {
        printf("Invalid username\n");
        return 0;
    }

    printf("Enter Admin password: ");
    scanf("%s", password);

    if (strcmp(password, "adminpass") != 0) {
        printf("Invalid password\n");
        return 0;
    }

    return 1;
}

void vote(Candidate candidates[], int numCandidates, Voter voters[], int *numVoters) {
    char userID[10];
    int candidateID;

    printf("Enter your user ID: ");
    scanf("%s", userID);

    for (int i = 0; i < *numVoters; ++i) {
        if (strcmp(userID, voters[i].userID) == 0) {
            if (voters[i].voted) {
                printf("You have already voted. One person, one vote!\n");
                return;
            }
        }
    }

    displayCandidates(candidates, numCandidates);
    printf("Enter the candidate ID you want to vote for: ");
    scanf("%d", &candidateID);

    if (candidateID < 1 || candidateID > numCandidates) {
        printf("Invalid candidate ID\n");
        return;
    }

    candidates[candidateID - 1].votes++;

    // Update voter status
    strcpy(voters[*numVoters].userID, userID);
    voters[*numVoters].voted = 1;
    (*numVoters)++;

    printf("Vote cast successfully!\n");
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; ++i) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates = 0;
    int numVoters = 0;

    int isAdmin = authenticateAdmin();

    if (!isAdmin) {
        printf("Authentication failed. Exiting...\n");
        return 1;
    }

    int choice;

    do {
        printf("\n*** Polling System Menu ***\n");
        printf("1. Setup Election\n");
        printf("2. Display Candidates\n");
        printf("3. Vote\n");
        printf("4. Display Results\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setupElection(candidates, &numCandidates);
                break;
            case 2:
                displayCandidates(candidates, numCandidates);
                break;
            case 3:
                vote(candidates, numCandidates, voters, &numVoters);
                break;
            case 4:
                displayResults(candidates, numCandidates);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

