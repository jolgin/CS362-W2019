//
//  cardtest3.c
//  
//
//  Created by John Olgin on 2/10/19.
//

#include <stdio.h>
#include "stdlib.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int validate(int valueCheck) {
    if(valueCheck) {
        printf("PASSED \n\n\n");
        return 0;
    }
    else {
        printf("FAILED \n\n\n");
        return -1;
    }
}


int main() {
    
    printf("CARD TEST 3: Testing the gardens card \n");
    struct gameState game;
    
    printf("Testing gardens with passing only 0 for all choices, handPos, and bonus to cardEffect \n");
    int bonus = 0;
    int check = cardEffect(gardens, 0, 0, 0, &game, 0, &bonus);
    printf("The value returned by gardens is: %d \n", check);
    int validCheck = validate(check == -1);
    
    printf("Testing gardens with passing only 1 for all choices, handPos, and bonus to cardEffect \n");
    bonus = 5;
    check = cardEffect(gardens, 1, 1, 1, &game, 1, &bonus);
    printf("The value returned by gardens is: %d \n", check);
    validCheck = validCheck + validate(check == -1);
    
    
    if (validCheck == 0){
        printf("CARD TEST 3 PASSED \n\n");
    }
    else {
        printf("CARD TEST 3 FAILED \n\n");
    }
    
    
    return 0;
}
