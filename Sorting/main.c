#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "headerFile.h"

#define _CRT_SECURE_NO_WARNINGS

void startingTask(short taskNumber) {
    if (taskNumber == 1) {
        printf("Not ready\n");
        // theMostCommonElementTask();
    }
    else if (taskNumber == 2) {
        searchTask();
    }
    else if (taskNumber == 3) {
        printf("Not ready\n");
        // smartQSortTask();
    }
    else {
        printf("Incorrect task number\n");
    }
}

int main() {
    char strTaskNumber[2];
    char* endptrTaskNumber = NULL;
    short taskNumber = 0;

    printf("Enter the task number from 1 to 3:\n");
    if (fgets(strTaskNumber, sizeof(strTaskNumber), stdin) == NULL) {
        printf("Input error\n");
        return 1;
    }

    taskNumber = strtol(strTaskNumber, &endptrTaskNumber, 10);
    if (taskNumber <= 0 || taskNumber >= 4 || *endptrTaskNumber != '\0') {
        printf("Incorrect task number\n");
        return 1;
    }

    startingTask(taskNumber);
    return 0;
}