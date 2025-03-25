#include <stdio.h>
#define SIZE 10

int main() {
    int array[SIZE] = {26, 34543, 17, 31, 13, 543, 456, 1, 0, 2};

    printf("Bubble Sort\n");
    printf("Before Sorting:\n");
    for (int i=0; i<SIZE; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

    // The Bubble Sort
    for (int i=0; i<SIZE-1; i++) {
        for (int target=0; target<(SIZE-1)-i; target++) {
            if (array[target] > array[target+1]) {
                int temp = array[target];
                array[target] = array[target+1];
                array[target+1] = temp;
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