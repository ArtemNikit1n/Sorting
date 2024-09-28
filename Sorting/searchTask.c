#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

void searchTask(void) {
    char strTotalNumbers[1000];
    char strRequiredNumbers[1000];
    char* endptrTotalNumbers;
    char* endptrRequiredNumbers;

    int totalNumbers = -1;
    int requiredNumbers = -1;

    printf("Enter a total number of numbers less than 1000");
    scanf("%s", strTotalNumbers);
    totalNumbers = strtol(strTotalNumbers, endptrTotalNumbers, 10);
    asert(totalNumbers > 0 && totalNumbers < 1000);

    printf("Enter the number of numbers less than 1000 you want to find:");
    scanf("%s", strRequiredNumbers);
    requiredNumbers = strtol(strRequiredNumbers, endptrRequiredNumbers, 10);
    asert(totalNumbers > 0 && totalNumbers < 1000);

}