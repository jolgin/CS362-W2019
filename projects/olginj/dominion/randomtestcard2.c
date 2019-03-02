//
//  randomtestcard2.c
//  
//
//  Created by John Olgin on 2/27/19.
//

#include <time.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"



int validate(int check) {
    if (check) {
        printf ("PASSED \n");
        return 0;
    }
    else{
        printf("FAILED \n");
        return 1;
    }
}


int main() {
    struct gameState game;
    int numPlayers;
    int kingdom[10] = {adventurer, smithy, treasure_map, baron, outpost, curse, salvager, mine, sea_hag, tribute};
    int deckSize;
    int handSize;
    int generalRandomCard;
    int randomKingdomCard;
    int testsToRun = 100;
    int testsFailed = 0;
    int testsPassed = 0;
    
    
    srand(time(NULL));
    
    printf("***RANDOM TEST 2: SMITHY*** \n");
    
    
    clock_t start, end;
    double duration;
    
    start = clock();
    for(int i = 0; i < testsToRun; i++) {
        initializeGame(numPlayers, kingdom, 100, &game);
        
        // Deck size logically needs to be between the max deck size and 1
        deckSize = rand() % (MAX_DECK + 1);
        
        // Generate random number of players
        // Choosing between two and four players since the game was designed for this number of players
        numPlayers = rand() % 4 + 2;
        
        if(numPlayers == 5) {
            numPlayers = 4;
        }
        
        
        // set a random hand size
        // Allowing the players to have a hand size between 1 and the deck size. Doesn't make sense for the players to be able to have a hand size bigger than deck size
        handSize = rand() % (deckSize + 1);
        
        
        // set the starting deck count for player 1
        game.deckCount[0] = deckSize - handSize;
        game.handCount[0] = handSize;
        
        // set a starting deck and hand count for all other players
        for(int j = 1; j < numPlayers; j++) {
            game.deckCount[j] = deckSize - handSize;
            game.handCount[j] = handSize;
        }
        
        
        // Fill each player's decks with random cards
        for (int j = 0; j < numPlayers; j++) {
            for(int k = 0; k < game.deckCount[j]; k++) {
                generalRandomCard = rand() % (20 + 1);
                randomKingdomCard = rand() % (10);
                if(generalRandomCard == 1){
                    game.deck[j][k] = copper;
                }
                else if(generalRandomCard == 2){
                    game.deck[j][k] = silver;
                }
                else if(generalRandomCard == 3){
                    game.deck[j][k] = gold;
                }
                else {
                    game.deck[j][k] = kingdom[randomKingdomCard];
                }
            }
        }
        
        // Fill array with other players' beginning hand counts, deck counts and discard counts
        int playerHandCounts[numPlayers - 1];
        int playerDeckCounts[numPlayers - 1];
        int playerDiscardCounts[numPlayers - 1];
        for (int j = 1; j < numPlayers; j++) {
            playerHandCounts[j-1] = game.handCount[j];
            playerDeckCounts[j-1] = game.deckCount[j];
            playerDiscardCounts[j-1] = game.discardCount[j];
        }
        
        
        // Save first player discard count and hand count before invoking adventurer card
        int beginningDiscardCount = game.discardCount[0];
        int beginningHandCount = game.handCount[0];
        int beginningDeckCount = game.deckCount[0];
        
        // save number of actions to check game state
        int numActions = game.numActions;
        
        
        // Invoke adventurer card function
        int getReturn = cardEffect(smithy, 1, 1, 1, &game, handSize, NULL);
        
        // Save member variables after execution
        int endingDeckCount = game.deckCount[0];
        int endingDiscardCount = game.discardCount[0];
        int endingHandCount = game.handCount[0];
        
        //printf("Beginning Hand Count:  %d   Ending Hand Count:  %d \n", beginningHandCount, endingHandCount);
        //printf("Beginning Deck Count:  %d   Ending Deck Count:  %d \n", beginningDeckCount, endingDeckCount);
        //printf("Beginning Discard Count:  %d   Ending Discard Count:  %d \n", beginningDiscardCount, endingDiscardCount);
        
        int validationCheck = 0;
        
        /*** GAME STATE CHECKS ***/
        // validate the game returns correctly with no issues
        printf("Checking for correct returned value...\n");
        validationCheck = validationCheck + validate(getReturn == 0);
        // validate the number of actions are unchanged
        printf("Checking for unchanged number of actions...\n");
        validationCheck = validationCheck + validate(numActions == game.numActions);
        
        
        /*** PLAYER 1 CHECKS ***/
        // validate player 1's hand count increased by 2
        printf("Checking that player 1's hand count increased by 2... \n");
        validationCheck = validationCheck + validate(beginningHandCount == endingHandCount - 2);
        // validate player 1's deck count decreased by 3
        printf("Checking that player 1's deck count decreased by 3... \n");
        validationCheck = validationCheck + validate(beginningDeckCount == endingDeckCount + 3);
        // validate player 1's discard count increased by 1
        printf("Checking that player 1's discard count increased by 1... \n");
        validationCheck = validationCheck + validate(beginningDiscardCount == endingDiscardCount);
        
        
        /*** OTHER PLAYER CHECKS ***/
        // Check that other players' hand counts, deck counts, and discard counts are unchanged
        for (int j = 1; j < numPlayers; j++) {
            printf("Checking for unchanged hand count for player %d \n", j+1);
            validationCheck = validationCheck + validate(playerHandCounts[j-1] == game.handCount[j]);
            printf("Checking for unchanged deck count for player %d \n", j+1);
            validationCheck = validationCheck + validate(playerDeckCounts[j-1] == game.deckCount[j]);
            printf("Checking for unchanged discard count for player %d \n", j+1);
            validationCheck = validationCheck + validate(playerDiscardCounts[j-1] == game.discardCount[j]);
        }
        
        // validation if the entire test is passed
        if(validationCheck == 0) {
            testsPassed++;
            printf("***TEST PASSED*** \n\n");
        }
        else {
            testsFailed++;
            printf("***TEST FAILED*** \n\n");
        }
    }
    
    end = clock();
    
    duration = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Took %f seconds to execute \n", duration);
    printf("Total Tests:  %d \n", testsToRun);
    printf("Tests Passed: %d \n", testsPassed);
    printf("Tests Failed: %d \n", testsFailed);
    
    return 0;
}

