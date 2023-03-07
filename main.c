#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"set.h"

int main( int argc, char *argv[] ) {
    
    const int num1 = 1;
    const int num2 = 2;
    const int num3 = 3;
    const int num4 = 4;
    const int num5 = 5;


    Boolean test = false;
    int numberOfTests = 0;
    int successRate = 0;


    printf("Creating setA...\n");
    Set * const setA = newSet();
    printf("setA was successfully created\n");


    printf("\nTesting to see whether any set objects exist (there should be, setA that we just created)...\n");
    test = validateMemUse();
    numberOfTests++;
    if(test == false){
        successRate++;
        printf("A(n) set object(s) was successfully found to exist\n");
    } else{
        printf("THE METHOD validateMemUse failed!\n");
    }



    printf("\nCreating setB...\n");
    Set * const setB = newSet();
    printf("setB was successfully created\n");



    printf("\ninserting few different values into sets A and B...\n");

    printf("\nINSERTING num1 TO setA...\n");
    test = insertItem(setA, num1);
    numberOfTests++;
    if(test == true){
        successRate++;
        printf("num1 was successfully inserted in setA\n");
    } else{
        printf("FAILED TO INSERT num1 TO setA\n");
    }


    printf("\nINSERTING num2 TO setA...\n");
    test = insertItem(setA, num2);
    numberOfTests++;
    if(test == true){
        successRate++;
        printf("num2 was successfully inserted in setA\n");
    } else{
        printf("FAILED TO INSERT num2 TO setA\n");
    }


    printf("\nINSERTING num4 TO setA...\n");
    test = insertItem(setA, num4);
    numberOfTests++;
    if(test == true){
        successRate++;
        printf("num4 was successfully inserted in setA\n");
    } else{
        printf("FAILED TO INSERT num4 TO setA\n");
    }


    printf("\nINSERTING num5 TO setA...\n");
    test = insertItem(setA, num5);
    numberOfTests++;
    if(test == true){
        successRate++;
        printf("num5 was successfully inserted in setA\n");
    } else{
        printf("FAILED TO INSERT num5 TO setA\n");
    }





    printf("\nINSERTING num3 TO setB...\n");
    test = insertItem(setB, num3);
    numberOfTests++;
    if(test == true){
        successRate++;
        printf("num3 was successfully inserted in setB\n");
    } else{
        printf("FAILED TO INSERT num3 TO setB\n");
    }

    printf("\nINSERTING num4 TO setB...\n");
    test = insertItem(setB, num4);
    numberOfTests++;
    if(test == true){
        successRate++;
        printf("num4 was successfully inserted in setB\n");
    } else{
        printf("FAILED TO INSERT num4 TO setB\n");
    }


    printf("\nINSERTING num5 TO setB...\n");
    test = insertItem(setB, num5);
    numberOfTests++;
    if(test == true){
        successRate++;
        printf("num5 was successfully inserted in setB\n");
    } else{
        printf("FAILED TO INSERT num5 TO setB\n");
    }



    printf("\nTesting to see whether both sets contain the same items (they don't)...\n");
    test = areEqual(setA, setB);
    numberOfTests++;
    if(test == false){
        successRate++;
        printf("areEqual is successful: setA and setB don't contain same items.\n");
    } else{
        printf("THE METHOD areEqual FAILED FUNCTIONALITY\n");
    }


    printf("\nTesting to see if there are no common items between the two sets (there is)...\n");
    test = areDisjoint(setA, setB);
    numberOfTests++;
    if(test == false){
        successRate++;
        printf("areDisjoint is successful: there are no common items between setA and setB.\n");
    } else{
        printf("THE METHOD areDisjoint FAILED FUNCTIONALITY\n");
    }

    
    Set * const unionOfSet = newSet();
    insertItem(unionOfSet, num1);
    insertItem(unionOfSet, num2);
    insertItem(unionOfSet, num3);
    insertItem(unionOfSet, num4);
    insertItem(unionOfSet, num5);
    printf("\nMaking a unionOf setA and setB...\n");
    numberOfTests++;
    Set * const temp = (unionOf(setA, setB));
    test = areEqual(unionOfSet,temp);
    if(test==true) {
        successRate++;
        printf("unionOf is successful: a union of setA and setB is created.\n");
    } else {
        printf("THE METHOD unionOf FAILED FUNCTIONALITY\n");
    }


    
    Set * const symmetricDifferenceOfSet = newSet();
    insertItem(symmetricDifferenceOfSet, num1);
    insertItem(symmetricDifferenceOfSet, num2);
    insertItem(symmetricDifferenceOfSet, num3);
    printf("\nMaking a new set of the different items between setA and setB...\n");
    numberOfTests++;
    Set * const temp2 = (symmetricDifferenceOf(setA, setB));
    test = areEqual(symmetricDifferenceOfSet,temp2);
    if(test==true) {
        successRate++;
        printf("symmetricDifferenceOf is successful: a new set is made from different items between setA and setB.\n");
    } else{
        printf("THE METHOD symmetricDifferenceOf FAILED FUNCTIONALITY\n");
    }



    printf("\nDeleting setB...\n");
    Set * a = deleteSet(setB);
    numberOfTests++;
    if (a == NULL)
    {
        successRate++;
        printf("deleteSet is successful: setB was deleted.\n");
    } else{
        printf("THE METHOD deleteSet FAILED FUNCTIONALITY\n");
    }
    


    printf("\nRemoving num2 from setA...\n");
    test = removeItem(setA, num2);
    numberOfTests++;
    if(test == true){
        successRate++;
        printf("num2 was successfully removed from setA.\n");
    } else{
        printf("FAILED TO REMOVE num2 FROM setA\n");
    }

    int numFail = numberOfTests - successRate;
    printf("\nNumber of tests ran = %d\nNumber of tests succeeded = %d\nNumber of failed tests = %d\nEND OF TESTING ",numberOfTests,successRate,numFail);
    return( EXIT_SUCCESS );
}