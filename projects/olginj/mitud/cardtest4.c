//
//  cardtest4.c
//  
//
//  Created by John Olgin on 2/08/19.
//
#include "stdlib.h"
#include "stdio.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int validate(int check) {
    if (check) {
        printf ("PASSED \n\n\n");
        return 0;
    }
    else{
        printf("FAILED \n\n\n");
        return 1;
    }
}

int main () {
    printf("CARD TEST 4: Testing outpost functionality\n");
    
    int p1HandCount;
    int p1DeckCount;
    int p1Outposts;
    int p2HandCount;
    int p2DeckCount;
    int numActions;
    int numBuys;
    struct gameState game;
    int k[10] = {adventurer, smithy, treasure_map, baron, outpost, curse, salvager, mine, sea_hag, tribute};
    initializeGame(2, k, 7, &game);
    
    // set p2's hand and deck count
    game.whoseTurn = 1;
    game.handCount[1] = 3;
    game.deckCount[1] = 3;
    
    
    game.whoseTurn = 0;
    game.hand[0][0] = outpost;
    game.hand[0][1] = smithy;
    game.hand[0][2] = curse;
    game.handCount[0] = 3;
    
    
    // Set deck count and deck content for player 1
    game.deckCount[0] = 3;
    game.deck[0][0] = gold;
    game.deck[0][1] = gardens;
    game.deck[0][2] = adventurer;

    game.numBuys = 1;
   
    // Save players' hand and deck counts
    p1DeckCount = game.deckCount[0];
    p1HandCount = game.handCount[0];
    p1Outposts = game.outpostPlayed;
    p2HandCount = game.handCount[1];
    p2DeckCount = game.deckCount[1];
    
    
    
    numActions = game.numActions;
    numBuys = game.numBuys;
    
    // Invoke outpost card and function
    int getReturn = cardEffect(outpost, 0, 0, 0, &game, 0, 0);
    int validCheck = 0;
    
    
    
    // check the function returned successfully
    printf("Check the function returned succesfully...\n");
    validCheck = validCheck + validate(getReturn == 0);
    // check that number of actions is unchanged
    printf("Checking that number of actions are unchanged...\n");
    validCheck = validCheck + validate(numActions == game.numActions);
    
    
    // Player 1 checks
    // Check that p1's hand count decreased by 2
    printf("Checking p1's hand count decreased by 2...\n");
    validCheck = validCheck + validate((p1HandCount - 2  == game.handCount[0]));
    
    // Check that p1's deck decreased by 3
    printf("Checking that p1's deck count decreased by 3...\n");
    validCheck = validCheck + validate(p1DeckCount == game.deckCount[0]);

    // Check that number of buys increases by 1
    printf("Check that number of buys increases by 1...\n");
    validCheck = validCheck + validate(numBuys + 1 == game.numBuys);
    
    // Check that outpostPlayed is incremented
    printf("Checking that outposts played is incremented\n");
    validCheck = validCheck + validate(p1Outposts + 1 == game.outpostPlayed);
    
    
    
    // Player 2 checks
    // Check that player 2's hand count wasn't changed
    printf("Checking that p2's hand count is unchanged...\n");
    validCheck = validCheck + validate((p2HandCount == game.handCount[1]));
    // Check that player 2's deck count wasn't changed
    printf("Checking that p2's deck count is unchanged...\n");
    validCheck = validCheck + validate((p2DeckCount == game.deckCount[1]));
    
    
    
    
    // Add up verifications and pass if still 0
    if(validCheck == 0)
        printf("CARD TEST 4 PASSED\n");
    else
        printf("CARD TEST 4 FAILED\n");
    return 0;
}
