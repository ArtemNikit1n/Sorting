#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "headerFile.h"

#define _CRT_SECURE_NO_WARNINGS

int findTheMostCommonElement(int array[], int arrayLength) {
    int maximumLineLength = 1;
    int currentLengthOfTheString = 1;
    int theMostCommonElement = -1;
    for (int i = 0; i + 1 < arrayLength; ++i) {
        int j = i + 1;
        while (array[i] == array[j]) {
            ++currentLengthOfTheString;
            ++j;
        }
        if (max(currentLengthOfTheString, maximumLineLength) != maximumLineLength) {
            theMostCommonElement = array[i];
        }
        maximumLineLength = max(currentLengthOfTheString, maximumLineLength);
        currentLengthOfTheString = 1;
        i = j;
    }
    return theMostCommonElement;
}

bool theMostCommonElementTask(void) {
    char* endptrArrayLength = NULL;
    char strArrayLength[6] = { 0 };

    int array[1000] = { 0 };
    int arrayLength = -1;
    bool errorCode = false;

    printf("Enter the array size:\n");
    scanf("%s", strArrayLength);
    arrayLength = (int)strtol(strArrayLength, &endptrArrayLength, 10);

    if (arrayLength > 1000 || arrayLength < 1) {
        printf("Invalid array value");
        errorCode = true;
        return errorCode;
    }

    srand(time(NULL));
    generatingRandomArrays(array, arrayLength);
    printf("Unsorted array: ");
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", array[i]);
    }

    smartQSort(array, 0, arrayLength - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", array[i]);
    }

    printf("\nThe most common element: %d", findTheMostCommonElement(array, arrayLength));
    return false;
}