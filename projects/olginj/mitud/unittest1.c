// John Olgin
// unittest1.c
#include "stdlib.h"
#include "stdio.h"
#include "dominion.h"
#include "dominion_helpers.h"

//This function will output whether each case has passed or failed for the user to see
int validate(int correctVal, char *card) {
    if (correctVal == 0) {
        printf ("Passed for: %s \n", card);
        return 0;
    }
    
    else {
        printf ("Failed for: %s \n", card);
        return 1;
    }
}




int main() {
    printf("Testing getCost function... \n");
    int checkValueArray[27];
    int correctNumbers[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};
    int cardArray[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
    
    
    char *cardStrings[27] = {"curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast", "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map"};
    
    //fill array with each card's value
    for (int i = 0; i < 27; i++) {
        checkValueArray[i] = getCost(cardArray[i]);
    }
    
    int checker = 0;
    int correctSum = 0;
    
    //compare each value with the known correct values of each card
    for (int i = 0; i < 27; i++) {
        int correct;
        
        if (checkValueArray[i] == correctNumbers[i]) {
            int correct = 0;
        }
        else {
            int correct = 1;
        }
        
        checker = validate(correct, cardStrings[i]);
        correctSum = correctSum + checker;
    }
    
    
    //check that getCost successfully returns -1 with an invalid card
    int invalidCard = getCost(30);
    
    int isCorrect;
    
    if (invalidCard == -1) {
        isCorrect = 0;
    }
    else {
        isCorrect = 1;
    }
    
    validate(isCorrect, "invalid card");
    
    
    //Determine if the entire unit test was passed or failed
    if (correctSum == 0 && isCorrect == 0) {
        printf("UNIT TEST 1 PASSED \n");
    }
    else {
        printf("UNIT TEST 1 FAILED \n");
    }
    
    return 0;
}
