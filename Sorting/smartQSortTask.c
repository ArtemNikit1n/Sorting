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
    for (int i = start + 1; i <= stop; ++i) {
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
    int randomIndex = startArray + rand() % (endArray - startArray + 1);
    swap(&array[startArray], &array[randomIndex]);

    int supportingElement = array[startArray];
    int leftPart = startArray + 1;

    for (int rightPart = startArray + 1; rightPart <= endArray; ++rightPart) {
        if (array[rightPart] < supportingElement) {
            swap(&array[leftPart], &array[rightPart]);
            ++leftPart;
        }
    }
    swap(&array[startArray], &array[leftPart - 1]);
    return leftPart - 1;
}

void smartQSort(int array[], int start, int stop) {
    if (start < stop) {
        if (stop - start > 0) {
            int supportingIndex = halfQSort(array, start, stop);

            if (supportingIndex - 1 > start) {
                smartQSort(array, start, supportingIndex - 1);
            }
            if (supportingIndex + 1 < stop) {
                smartQSort(array, supportingIndex + 1, stop);
            }
        }
        if (stop - start <= 10) {
            insertionSort(array, start, stop);
        }
    }

}

void generatingRandomArrays(int randomArray[], int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        randomArray[i] = rand() % 100;
    }
}

bool testSmartQSort() {
    int testArray[21] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    smartQSort(testArray, 0, 20);
    for (int i = 0; i < 20; ++i) {
        if (testArray[i] > testArray[i + 1]) {
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

    if (!testSmartQSort()) {
        errorCode = true;
        printf("Test failed");
        return errorCode;
    }

    printf("Enter the array size:\n");
    scanf("%s", strArrayLength);
    arrayLength = (int)strtol(strArrayLength, &endptrArrayLength, 10);

    if (arrayLength > 1000 || arrayLength < 1 || *endptrArrayLength != '\0') {
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
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", array[i]);
    }
    return errorCode;
}