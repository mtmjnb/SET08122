#include <stdio.h>
#define SIZE 10

int main() {
    int array[SIZE] = {26, 34543, 17, 31, 13, 543, 456, 1, 0, 2};

    printf("Selection Sort\n");
    printf("Before Sorting:\n");
    for (int i=0; i<SIZE; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

    // The Selection Sort
    for (int i=0; i<SIZE-1; i++) {
        for (int target=i+1; target<SIZE; target++) {
            if (array[i] > array[target]) {
                int temp = array[i];
                array[i] = array[target];
                array[target] = temp;
            }
        }
    }
    printf("After Sorting:\n");
    for (int i=0; i<SIZE; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

    return 0;
}