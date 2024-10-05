#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "headerFile.h"

#define _CRT_SECURE_NO_WARNINGS

int calculatingTheMiddle(start, stop) {
    return (int)((start - stop) / 2);
}

int search(int searchArea[], int desiredNumbersArray[], int searchAreaLength, int desiredNumbers) {
    smartQSort(searchArea, 0, searchAreaLength - 1);

    int averageIndex = (int)((searchAreaLength - 1) / 2);
    int previousIndex = -1;
    int theNumberOfElementsContainedInTheArray = 0;
    int i = 0; 
    while (averageIndex >= 0 && averageIndex < searchAreaLength && i < desiredNumbers) {
        if (searchArea[averageIndex] == desiredNumbersArray[i]) {
            ++theNumberOfElementsContainedInTheArray;
            int j = 1;
            while (searchArea[averageIndex + j] == desiredNumbersArray[i]) {
                ++j;
                ++theNumberOfElementsContainedInTheArray;
            }
            j = -1;
            while (searchArea[averageIndex + j] == desiredNumbersArray[i]) {
                --j;
                ++theNumberOfElementsContainedInTheArray;
            }
            ++i;
        }
        else if (searchArea[averageIndex] < desiredNumbersArray[i]) {
            if (previousIndex < averageIndex) {
                previousIndex = averageIndex;
                averageIndex = calculatingTheMiddle(averageIndex, searchAreaLength);
            }
            else {
                averageIndex = calculatingTheMiddle(averageIndex, previousIndex);
            }
        } else {
            if (previousIndex > averageIndex) {
                previousIndex = averageIndex;
                averageIndex = calculatingTheMiddle(averageIndex, 0);
            } else {
                averageIndex = calculatingTheMiddle(averageIndex, previousIndex);
            }
        } 
    }
    return theNumberOfElementsContainedInTheArray;
}

bool testSearch() {
    int testSearchArea[9] = { 1, 2, 3, 3, 3, 4, 5, 5, 6 };
    int test1DesiredNumbersArray[2] = { 1, 6 };
    int test2DesiredNumbersArray[2] = { 4, 3 };
    return (search(testSearchArea, test1DesiredNumbersArray, 9, 2) == 2 && search(testSearchArea, test2DesiredNumbersArray, 9, 2) == 4);
}

bool searchTask(void) {
    char strSearchArea[10];
    char strDesiredNumbers[10];
    char *endptrSearchArea = NULL;
    char *endptrRequiredNumbers = NULL;

    int searchAreaLength = -1;
    int desiredNumbers = -1;
    int searchArea[1000] = { 0 };
    int desiredNumbersArray[1000] = { 0 };
    bool errorCode = false;

    if (!testSearch()) {
        printf("Test failed\n");
        errorCode = true;
        //return errorCode;
    }

    printf("Enter a total number of numbers less than 1000:\n");
    scanf("%s", strSearchArea);
    searchAreaLength = strtol(strSearchArea, &endptrSearchArea, 10);
    if (searchAreaLength <= 0 && searchAreaLength >= 1000) {
        printf("Input error");
        errorCode = true;
        return errorCode;
    }

    printf("Enter the number of numbers less than 1000 you want to find:\n");
    scanf("%s", strDesiredNumbers);
    desiredNumbers = strtol(strDesiredNumbers, &endptrRequiredNumbers, 10);
    if (desiredNumbers <= 0 && desiredNumbers >= 1000) {
        printf("Input error");
        errorCode = true;
        return errorCode;
    }

    if (*endptrRequiredNumbers != '\0' || *endptrSearchArea != '\0') {
        printf("Input error");
        errorCode = true;
        return errorCode;
    }

    srand(time(NULL));
    generatingRandomArrays(searchArea, searchAreaLength);
    generatingRandomArrays(desiredNumbersArray, desiredNumbers);
    printf("The number of numbers in the array: %d", search(searchArea, desiredNumbersArray, searchAreaLength, desiredNumbers));

    printf("\nSorted search area: ");
    for (int i = 0; i < searchAreaLength; ++i) {
        printf("%d ", searchArea[i]);
    }
    printf("\nArray of the desired numbers: ");
    for (int i = 0; i < desiredNumbers; ++i) {
        printf("%d ", desiredNumbersArray[i]);
    }
}