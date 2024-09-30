#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void swap(int* first, int* second) {
    if (*first == *second) {
        return;
    }
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}

int halfQSort(int array[], int startArray, int endArray) {
    int j = startArray + 1;
    while (startArray == j) {
        ++j;
    }
    startArray = (max(array[startArray], array[j]) == array[startArray]) ? startArray : j;
    int supportingElement = array[startArray];
    int indexSupportingElement = startArray;
    //int arrayLength = endArray - startArray + 1;
    for (int i = indexSupportingElement + 1; i < endArray; ++i) {
        if (supportingElement > array[i]) {
            swap(&array[i - 1], &array[i]);
            ++indexSupportingElement;
        }
        else {
            swap(&array[i], &array[endArray - 1]);
            --endArray;
            --i;
        }  
    }
    return indexSupportingElement;
}

void smartQSort(int array[], int arrayLength) {
    halfQSort(array, 5, arrayLength);
    //if (start < end) {
    //    int pivotIndex = halfQSort(array, start, end);
    //    quickSort(array, start, pivotIndex - 1);
    //    quickSort(array, pivotIndex + 1, end);
    //}
}

void generatingRandomArrays(int randomArray[], int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        randomArray[i] = rand() % 100;
    }
}

bool smartQSortTask(void) {
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

    smartQSort(array, arrayLength);
    printf("\nSorted array: ");
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", array[i]);
    }

    return errorCode;
}