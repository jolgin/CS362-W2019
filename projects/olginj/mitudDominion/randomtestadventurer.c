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
    int endCoins = 0;
    int copperDiscarded = 0;
    int silverDiscarded = 0;
    int goldDiscarded = 0;
    int beginningCoins;
    int testsToRun = 100;
    int testsFailed = 0;
    int testsPassed = 0;
    
    
    srand(time(NULL));
    
    printf("***RANDOM TEST: ADVENTURER*** \n");
    
    for(int i = 0; i < testsToRun; i++) {
        initializeGame(numPlayers, kingdom, 100, &game);
        beginningCoins = 0;
        endCoins = 0;
        
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
        
        // Save the total number of beginningCoins before executing the adventurer card
        for(int j = 0; j < game.handCount[0]; j++) {
            if(game.hand[0][j] == copper || game.hand[0][j] == silver || game.hand[0][j] == gold){
                beginningCoins++;
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
        int getReturn = cardEffect(adventurer, 1, 1, 1, &game, handSize, NULL);
        
        // Save member variables after execution
        int endingDeckCount = game.deckCount[0];
        int endingDiscardCount = game.discardCount[0];
        int deckCountDifference = beginningDeckCount - endingDeckCount;
        int endingHandCount = game.handCount[0];
        
        
        // Save the total number of endCoins after executing the adventurer card
        for(int j = 0; j < game.handCount[0]; j++){
            if(game.hand[0][j] == copper || game.hand[0][j] == silver || game.hand[0][j] == gold){
                endCoins++;
            }
        }

        
        // Check if any coins were discarded
        for(int j = 0; j < game.discardCount[0]; j++){
            if(game.discard[0][j] == copper) {
                copperDiscarded++;
            } 
            else if(game.discard[0][j] == silver) {
                silverDiscarded++;
            } 
            else if(game.discard[0][j] == gold) {
                goldDiscarded++;
            }
        }


        
        int validationCheck = 0;
        
        /*** GAME STATE CHECKS ***/
        // validate the game returns correctly with no issues
        printf("Checking for correct returned value...\n");
        validationCheck = validationCheck + validate(getReturn == 0);
        // validate the number of actions are unchanged
        printf("Checking for unchanged number of actions...\n");
        validationCheck = validationCheck + validate(numActions == game.numActions);
        
        
        /*** PLAYER 1 CHECKS ***/
        // validate there are two more coins in the player's hand
        printf("Checking for two drawn treasure cards...\n");
        validationCheck = validationCheck + validate(endCoins == beginningCoins + 2);
        // validate the number of cards taken from deck equals the discard pile + 2 (2 coins into hand)
        printf("Checking for correct updated discard and deck counts...\n");
        validationCheck = validationCheck + validate(endingDiscardCount == deckCountDifference - 2);
        // validate the hand count after invoking adventurer is two more than before invoking adventurer
        printf("Checking for correct updated hand count...\n");
        validationCheck = validationCheck + validate(endingHandCount == beginningHandCount + 2);
        
        
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
   
    printf("Total Tests:  %d \n", testsToRun);
    printf("Tests Passed: %d \n", testsPassed);
    printf("Tests Failed: %d \n", testsFailed);
    
   return 0;
}
