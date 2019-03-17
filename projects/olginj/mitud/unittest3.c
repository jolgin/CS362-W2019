//
//  unittest3.c
//  
//
//  Created by John Olgin on 2/10/19.
//

#include <stdio.h>
#include "stdlib.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"



int main() {
    struct gameState game;
    game.coins = 0;
    int check = 0;
    
    printf("UNIT TEST 3: Check the updateCoins() function \n");
    
    
    //Test with 5 copper coins
    game.handCount[0] = 5;
    printf("Test by inserting 5 copper coins:\n");
    game.hand[0][0] = copper;
    game.hand[0][1] = copper;
    game.hand[0][2] = copper;
    game.hand[0][3] = copper;
    game.hand[0][4] = copper;
    updateCoins(0,&game, 0);
    printf("Check for 5 coin \n");
    if(game.coins == 5){
        printf("%d coin \n", game.coins);
        printf("PASSED\n\n\n");
        check++;
    }
    else {
        printf("%d coin \n", game.coins);
        printf("FAILED \n\n\n");
    }
    
    //Test with 5 copper coins and 2 coin bonus
    printf("Test by inserting 5 copper coins with a 2 coin bonus:\n");
    updateCoins(0, &game, 2);
    printf("Check for 7 coin \n");
    if(game.coins == 7){
        printf("%d coin \n", game.coins);
        printf("PASSED\n\n\n");
        check++;
    }
    else {
        printf("%d coin \n", game.coins);
        printf("FAILED \n\n\n");
    }
    
    //Test with 5 silver coins
    printf("Test by inserting 5 silver coins:\n");
    game.hand[0][0] = silver;
    game.hand[0][1] = silver;
    game.hand[0][2] = silver;
    game.hand[0][3] = silver;
    game.hand[0][4] = silver;
    updateCoins(0,&game, 0);
    printf("Check for 10 coin \n");
    if(game.coins == 10){
        printf("%d coin \n", game.coins);
        printf("PASSED\n\n\n");
        check++;
    }
    else {
        printf("%d coin \n", game.coins);
        printf("FAILED\n\n\n");
    }
    
    //Test with 5 silver coins and 4 bonus coin
    printf("Test by inserting 5 silver coins with a 4 coin bonus:\n");
    updateCoins(0, &game, 4);
    printf("Check for 14 coin \n");
    if(game.coins == 14){
        printf("%d coin \n", game.coins);
        printf("PASSED\n\n\n");
        check++;
    }
    else {
        printf("%d coin \n", game.coins);
        printf("FAILED \n\n\n");
    }
    
    //Test with 5 gold coins
    printf("Test by inserting 5 gold coins:\n");
    game.hand[0][0] = gold;
    game.hand[0][1] = gold;
    game.hand[0][2] = gold;
    game.hand[0][3] = gold;
    game.hand[0][4] = gold;
    updateCoins(0,&game, 0);
    printf("Check for 15 coin \n");
    if(game.coins == 15){
        printf("%d coin \n", game.coins);
        printf("PASSED\n\n\n");
        check++;
    }
    else {
        printf("%d coin \n", game.coins);
        printf("FAILED\n\n\n");
    }
    
    //Test with no coins
    printf("Test by inserting no coins:\n");
    game.hand[0][0] = smithy;
    game.hand[0][1] = adventurer;
    game.hand[0][2] = curse;
    game.hand[0][3] = gardens;
    game.hand[0][4] = adventurer;
    updateCoins(0,&game, 0);
    printf("Check for 0 coin \n");
    if(game.coins == 0){
        printf("%d coin \n", game.coins);
        printf("PASSED\n\n\n");
        check++;
    }
    else {
        printf("%d coin \n", game.coins);
        printf("FAILED\n\n\n");
    }
    
    //Test with 1 copper, 2 silver and 2 gold coins
    printf("Test by inserting 1 copper, 2 silver and 2 gold coins:\n");
    game.hand[0][0] = copper;
    game.hand[0][1] = silver;
    game.hand[0][2] = silver;
    game.hand[0][3] = gold;
    game.hand[0][4] = gold;
    updateCoins(0,&game, 0);
    printf("Check for 11 total coin \n");
    if(game.coins == 11){
        printf("%d coin \n", game.coins);
        printf("PASSED\n\n\n");
        check++;
    }
    else {
        printf("%d coin \n", game.coins);
        printf("FAILED\n\n\n");
    }
    
    if (check == 7){
        printf("UNIT TEST 3 PASSED\n\n");
    }
    else {
        printf("UNIT TEST 3 FAILED\n\n");
    }
    
    return 0;
}
