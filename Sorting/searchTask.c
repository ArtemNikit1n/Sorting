#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "headerFile.h"

#define _CRT_SECURE_NO_WARNINGS

int calculatingTheMean(int length) {
    if (length % 2 == 0) {
        return length / 2;
    } else {
        return (int)(length / 2);
    }
}

int search(int totalNumbersArray[], int requiredNumbersArray[], int totalNumbers, int requiredNumbers) {
    return;
}

void searchTask(void) {
    char strTotalNumbers[10];
    char strRequiredNumbers[10];
    char *endptrTotalNumbers = NULL;
    char *endptrRequiredNumbers = NULL;

    int totalNumbers = -1;
    int requiredNumbers = -1;
    int totalNumbersArray[1000] = { 0 };
    int requiredNumbersArray[1000] = { 0 };
    bool errorCode = false;

    printf("Enter a total number of numbers less than 1000:\n");
    scanf("%s", strTotalNumbers);
    totalNumbers = strtol(strTotalNumbers, &endptrTotalNumbers, 10);
    if (totalNumbers <= 0 && totalNumbers >= 1000) {
        printf("Input error");
        errorCode = true;
        return errorCode;
    }

    printf("Enter the number of numbers less than 1000 you want to find:\n");
    scanf("%s", strRequiredNumbers);
    requiredNumbers = strtol(strRequiredNumbers, &endptrRequiredNumbers, 10);
    if (requiredNumbers <= 0 && requiredNumbers >= 1000) {
        printf("Input error");
        errorCode = true;
        return errorCode;
    }

    if (*endptrRequiredNumbers != '\0' || *endptrTotalNumbers != '\0') {
        printf("Input error");
        errorCode = true;
        return errorCode;
    }

    srand(time(NULL));
    generatingRandomArrays(totalNumbersArray, totalNumbers);
    generatingRandomArrays(requiredNumbersArray, requiredNumbers);
}