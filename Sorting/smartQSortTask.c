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

void insertionSort(int array[], int start, int stop) {
    for (int i = start + 1; i < stop; ++i) {
        int indexSave = i;
        int insertableElement = array[i];
        while (array[i] < array[i - 1] && start < i) {
            swap(&array[i], &array[i - 1]);
            --i;
        }
        i = indexSave;
    }
}

int halfQSort(int array[], int startArray, int endArray) {
    //int j = startArray + 1;
    //while (startArray == j) {
    //    ++j;
    //}
    //startArray = (max(array[startArray], array[j]) == array[startArray]) ? startArray : j;
    int supportingElement = array[startArray];
    int indexSupportingElement = startArray;
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

void smartQSort(int array[], int start, int stop) {
    if (start < stop) {
        if (stop - start > 10) {
            int supportingIndex = halfQSort(array, start, stop);
            smartQSort(array, start, supportingIndex - 1);
            smartQSort(array, supportingIndex + 1, stop);
        }
        else {
            insertionSort(array, start, stop);
        }
    }
}

void generatingRandomArrays(int randomArray[], int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        randomArray[i] = rand() % 100;
    }
}

bool testSmartQSort(int array[], int start, int stop) {
    for (int i = start; i < stop - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
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

    smartQSort(array, 0, arrayLength);
    printf("\nSorted array: ");
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", array[i]);
    }
    printf("\nTest result: %d", testSmartQSort(array, 0, arrayLength));
    return errorCode;
}