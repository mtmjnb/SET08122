#include <stdio.h>
#define SIZE 10

int main() {
    int array[SIZE] = {26, 34543, 17, 31, 13, 543, 456, 1, 0, 2};

    printf("Insertion Sort\n");
    printf("Before Sorting:\n");
    for (int i=0; i<SIZE; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

    // The Insertion Sort
    for (int cmp=0; cmp<SIZE; cmp++) {
        for (int i=0; i<cmp; i++) {
            if (array[i] > array[cmp]) {
                int temp = array[i];
                array[i] = array[cmp];
                int shift;
                for (shift=cmp; shift>i; shift--) {
                    array[shift] = array[shift-1];
                }
                array[shift+1] = temp;
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