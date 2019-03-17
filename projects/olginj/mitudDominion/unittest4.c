//
//  unittest4.c
//  
//
//  Created by John Olgin on 2/10/19.
//

#include <stdio.h>
#include "stdlib.h"
#include "dominion.h"
#include "dominion_helpers.h"
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

int main()
{
    printf("UNIT 4 TEST: Check supplyCount() function\n");
    int validationCheck = 0;
    
    // Tests that supplyCount works properly
    struct gameState game;
    
    // Test 5 different cards with various supply amounts
    printf("Testing copper, gold, smithy, adventurer and curse cards with various supply amounts \n");
    game.supplyCount[copper] = 5;
    game.supplyCount[gold] = 2;
    game.supplyCount[smithy] = 4;
    game.supplyCount[adventurer] = 6;
    game.supplyCount[curse] = 3;
    
    // Add assertion values up and ensure they're still 0
    validationCheck = validationCheck + validate(supplyCount(copper, &game) == 5);
    validationCheck = validationCheck + validate(supplyCount(gold, &game) == 2);
    validationCheck = validationCheck + validate(supplyCount(smithy, &game) == 4);
    validationCheck = validationCheck + validate(supplyCount(adventurer, &game) == 6);
    validationCheck = validationCheck + validate(supplyCount(curse, &game) == 3);
    
    
    // Test 5 different cards all with 0 supply
    printf("Testing copper, gold, smithy, adventurer and curse cards all with no supply \n");
    game.supplyCount[copper] = 0;
    game.supplyCount[gold] = 0;
    game.supplyCount[smithy] = 0;
    game.supplyCount[adventurer] = 0;
    game.supplyCount[curse] = 0;
    
    // Add assertion values up and ensure they're still 0
    validationCheck = validationCheck + validate(supplyCount(copper, &game) == 0);
    validationCheck = validationCheck + validate(supplyCount(gold, &game) == 0);
    validationCheck = validationCheck + validate(supplyCount(smithy, &game) == 0);
    validationCheck = validationCheck + validate(supplyCount(adventurer, &game) == 0);
    validationCheck = validationCheck + validate(supplyCount(curse, &game) == 0);
    
    
    // Pass the test if validate() function never returns 1
    if(validationCheck == 0){
        printf("UNIT TEST 4 PASSED \n\n");
    }
    else{
        printf("UNIT TEST 4 FAILED \n\n");
    }
    
    return 0;
}
