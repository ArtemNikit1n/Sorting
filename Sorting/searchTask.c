#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

void searchTask(void) {
    char strTotalNumbers[10] = {'\n'};
    char strRequiredNumbers[10];
    char *endptrTotalNumbers = NULL;
    char *endptrRequiredNumbers = NULL;

    int totalNumbers = -1;
    int requiredNumbers = -1;

    printf("Enter a total number of numbers less than 1000");
    scanf("%s", strTotalNumbers);
    totalNumbers = strtol(strTotalNumbers, endptrTotalNumbers, 10);
    assert(totalNumbers > 0 && totalNumbers < 1000);

    printf("Enter the number of numbers less than 1000 you want to find:");
    if (fgets(strRequiredNumbers, sizeof(strRequiredNumbers), stdin) == NULL) {
        printf("Input error\n");
        return;
    }
    requiredNumbers = strtol(strRequiredNumbers, endptrRequiredNumbers, 10);
    assert(requiredNumbers > 0 && requiredNumbers < 1000);

    if (*endptrRequiredNumbers != '\0' || *endptrTotalNumbers != '\0') {
        printf("Input error");
        return;
    }
}