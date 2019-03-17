//
//  unittest2.c
//  
//
//  Created by John Olgin on 2/08/19.
//

#include <stdio.h>
#include "stdlib.h"
#include "dominion.h"
#include "dominion_helpers.h"

//This will test the whoseTurn function
int main ()    {
    struct gameState game;
    int check = 0;
    int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
    
    printf ("\n UNIT TEST 2: Testing the whoseTurn() function\n");
    
   
    //Set player turn to player 0 and verify with whoseTurn()
    game.whoseTurn = 0;
    if (whoseTurn(&game) == 0) {
        printf("Passed for Player 0's turn \n");
        check++;
    }
    else {
        printf("Failed for Player 0's turn \n");
    }
    
    
    //Set player turn to player 1 and verify with whoseTurn()
    game.whoseTurn = 1;
    if (whoseTurn(&game) == 1) {
        printf("Passed for Player 1's turn \n");
        check++;
    }
    else {
        printf("Failed for Player 1's turn \n");
    }
    
    //Set player turn to player 2 and verify with whoseTurn()
    game.whoseTurn = 2;
    if (whoseTurn(&game) == 2) {
        printf("Passed for Player 2's turn \n");
        check++;
    }
    else {
        printf("Failed for Player 2's turn \n");
    }
    
    //Set player turn to player 3 and verify with whoseTurn()
    game.whoseTurn = 3;
    if (whoseTurn(&game) == 3) {
        printf("Passed for Player 3's turn \n");
        check++;
    }
    else {
        printf("Failed for Player 3's turn \n");
    }
    
    //Check if all tests passed or not
    if (check == 4) {
        printf("UNIT TEST 2 PASSED \n");
    }
    else {
        printf("UNIT TEST 2 FAILED \n");
    }
    
    return 0;
}
