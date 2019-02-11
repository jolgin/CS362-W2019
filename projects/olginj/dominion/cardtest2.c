//
//  cardtest2.c
//  
//
//  Created by John Olgin on 2/10/19.
//

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "assert.h"

int validate(int check) {
    if (check) {
        printf ("PASSED \n\n\n");
        return 1;
    }
    else{
        printf("FAILED \n\n\n");
        return 0;
    }
}

int main () {
    printf("CARD TEST 2: Testing adventurer card functionality...\n");
    
    int p1HandCount;
    int p1DeckCount;
    int p1DiscardCount;
    int p2HandCount;
    int p2DeckCount;
    int p2DiscardCount;
    int numActions;
    struct gameState game;
    int k[10] = {adventurer, smithy, treasure_map, baron, outpost, curse, salvager, mine, sea_hag, tribute};
    initializeGame(2, k, 7, &game);
    
    //Set and save gamestate of player 2 (to check against after the adventurer card has been played for any changes)
    game.discardCount[1] = 0;
    game.whoseTurn = 1;
    game.hand[1][0] = adventurer;
    game.deckCount[1] = 4;
    endTurn(&game);
    
    
    
    // Set player 1's hand
    game.whoseTurn = 0;
    game.hand[0][0] = adventurer;
    game.hand[0][1] = smithy;
    game.handCount[0] = 2;
    
    // Set P1 discard count
    game.discardCount[0] = 0;
    
    // Set player 1's deck
    game.deck[0][0] = copper;
    game.deck[0][1] = gardens;
    game.deck[0][2] = smithy;
    game.deck[0][3] = silver;
    game.deckCount[0] = 4;
    
    // Set deck and hand counts into variables
    numActions = game.numActions;
    p1DeckCount = game.deckCount[0];
    p1HandCount = game.handCount[0];
    p1DiscardCount = game.discardCount[0];
    p2DeckCount = game.deckCount[1];
    p2HandCount = game.handCount[1];
    p2DiscardCount = game.discardCount[1];
    
    
    // Invoke the adventurer function
    int getReturn = cardEffect(adventurer, 0, 0, 0, &game, 0, 0);
    int validationCheck = 0;
    
    // Check that the function returned successfully
    printf("Checking for correct returned value...\n");
    validationCheck = validationCheck + validate((getReturn == 0));
    // Check that number of actions is unchanged
    printf("Checking for unchanged number of actions...\n");
    validationCheck = validationCheck + validate(numActions == game.numActions);
    
    
    // Player 1 checks
    // Check that player 1's hand count goes up by 1 (receives two treasure cards and discards 1 card)
    printf("Checking for correct updated hand count\n");
    p1HandCount = p1HandCount + 2;
    validationCheck = validationCheck + validate((p1HandCount == game.handCount[0]));
    // Check that the deck decreases by 2 cards
    printf("Checking for correct updated deck count...\n");
    validationCheck = validationCheck + validate(p1DeckCount - 4 == fullDeckCount(0, 0, &game));
    // Check that two treasure cards were actually drawn
    printf("Checking for two drawn treasure cards...\n");
    validationCheck = validationCheck + validate((game.hand[0][2] == silver && game.hand[0][3] == copper));
    // Check that p1 discard pile increased by 3 (two deck cards and adventurer)
    printf("Checking for correct updated discard counts...\n");
    validationCheck = validationCheck + validate(p1DiscardCount + 2 == game.discardCount[0]);
    
    
    // Player 2 checks
    // Check that player 2's hand count is unchanged
    printf("Checking for unchanged hand count for player 2...\n");
    validationCheck = validationCheck + validate((p2HandCount == game.handCount[1]));
    // Check that player 2's deck count is unchanged
    printf("Checking for unchanged deck count for player 2...\n");
    validationCheck = validationCheck + validate((p2DeckCount == game.deckCount[1]));
    // Check that playr 2's discard count hasn't changed
    printf("Checking for unchanged discard count for player 2...\n");
    validationCheck = validationCheck + validate(p2DiscardCount == game.discardCount[1]);
    
    
   
    
    
    
    //if all of this was verified, print that this test was successful
    if(validationCheck  == 0)
        printf("CARD TEST 2 PASSED \n\n");
    //if a section could not be verified, print that this test was a faliure
    else
        printf("CARD TEST 2 FAILED \n\n");
    return 0;
}
