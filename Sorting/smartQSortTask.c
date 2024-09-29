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

int halfQsort(int array[], int startArray, int endArray) {
    int firstElement = array[startArray];
    int indexFirstElement = 0;
    int arrayLength = endArray - startArray;
    for (int i = 1; i < arrayLength; ++i) {
        if (firstElement > array[i]) {
            swap(&array[i - 1], &array[i]);
            ++indexFirstElement;
        }
        else {
            if (array[i] == array[arrayLength - 1]) {
                --arrayLength;
                --i;
                continue;
            }
            swap(&array[i], &array[arrayLength - 1]);
            --arrayLength;
            --i;
        }
    }
    return indexFirstElement;
}

void smartQSort(int array[], int arrayLength) {
    int start = 0;
    int stop = halfQsort(array, start, arrayLength);
    while (start + 1 != stop) {
        stop = halfQsort(array, start, stop);
    }

}

void generatingRandomArrays(int randomArray[], int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        randomArray[i] = rand() % 100;
    }
}

void smartQSortTask(void) {
    char* endptrArrayLength = NULL;
    char strArrayLength[6] = { 0 };

    int array[1000] = { 0 };
    int arrayLength = -1;

    printf("Enter the array size:\n");
    scanf("%s", strArrayLength);
    arrayLength = (int)strtol(strArrayLength, &endptrArrayLength, 10);

    if (arrayLength > 1000 || arrayLength < 1) {
        printf("Invalid array value");
        return;
    }

    srand(time(NULL));
    generatingRandomArrays(array, arrayLength);
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", array[i]);
    }


    smartQSort(array, arrayLength);
    printf("\n");
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", array[i]);
    }
}