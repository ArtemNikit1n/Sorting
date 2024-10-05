#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int compare(int* a, int* b) {
    if (*a < *b) {
        return -1;
    }
    else if (*a > *b) {
        return 1;
    }
    else {
        return 0;
    }
}

void generatingRandomArrays(int randomArray[], int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        randomArray[i] = rand() % 100;
    }
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

    qsort(array, arrayLength, sizeof(int), compare);

    printf("\nSorted array: ");
    for (size_t i = 0; i < arrayLength; i++) {
        printf("%d ", array[i]);
    }
    return false;
}