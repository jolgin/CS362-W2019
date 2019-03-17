//
//  cardtest4.c
//  
//
//  Created by John Olgin on 2/08/19.
//

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "assert.h"

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

int main () {
    printf("CARD TEST 1: Testing smithy card function... \n");
    
    int p1DeckCount;
    int p1HandCount;
    int p2HandCount;
    int p2DeckCount;
    int getReturn;
    int numActions;
    int k[10] = {adventurer, smithy, treasure_map, baron, outpost, curse, salvager, mine, sea_hag, tribute};
    struct gameState game;
    initializeGame(2, k, 7, &game);
    
    game.whoseTurn = 1;
    game.hand[1][0] = smithy;
    game.deckCount[1] = 8;
    
    game.whoseTurn = 0;
    game.hand[0][0] = smithy;
    game.deckCount[0] = 5;
    
    
    numActions = game.numActions;
    p1DeckCount = game.deckCount[0];
    p1HandCount = game.handCount[0];
    p2DeckCount = game.deckCount[1];
    p2HandCount = game.handCount[1];
    int validCheck = 0;
    
    getReturn =  cardEffect(smithy, 1, 1, 1, &game, p1HandCount, NULL);
    
    // Check that the function returned successfully
    validCheck = validCheck + validate(getReturn == 0);
    // Check that actions weren't changed
    validCheck = validCheck + validate((numActions == game.numActions));
    
    
    // Player 1 checks
    // Check player 1 hand count (should be two more than beginning since drawing 3 and discarding 1)
    p1HandCount = p1HandCount + 2;
    validCheck = validCheck + validate((p1HandCount == game.handCount[0]));
    // Check that player 1's deck count is 3 less
    validCheck = validCheck + validate(p1DeckCount - 3 == game.deckCount[0]);
    
    
    // Player 2 checks
    // Check that player 2's hand count is unchanged
    validCheck = validCheck + validate(p2HandCount == game.handCount[1]);
    // Check that player 2's deck count is unchanged
    validCheck = validCheck + validate(p2DeckCount == game.deckCount[1]);
    
    
    
    
    // If everything occurred without error, then the test is passed
    if(validCheck == 0)
        printf("CARD TEST 1 PASSED \n");
    else
        printf("CARD TEST 1 FAILED\n");
    return 0;
}
