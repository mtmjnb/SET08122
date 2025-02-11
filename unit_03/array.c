#include <stdio.h>
#include "array.h"

#define MAX 5

int main() {
    int array[MAX];
    init(array);

    insert(array, 0, 10);
    insert(array, 1, 11);
    insert(array, 2, 12);
    insert(array, 3, 13);
    insert(array, 4, 14);

    printf("Array Contents:\n");
    display(array);

    delete(array, 4);
    delete(array, 1);

    printf("After Deletion:\n");
    display(array);

    insert(array, 1, 111);
    insert(array, 4, 444);

    printf("Array Insertion:\n");
    display(array);

    reverse(array);

    printf("After Reversal:\n");
    display(array);

    search(array, 111);
    search(array, 555);

    return 0;
}

void init(int *array) {
    for(int i=0; i<MAX; i++) {
        array[i] = 0;
    }
}

void insert(int *array, int pos, int num) {
    int i;
    for(i=MAX-1; i>pos; i--) {
        array[i] = array[i-1];
    }
    array[i] = num;
}

void delete(int *array, int pos) {
    int i;
    for(i=pos; i<MAX-1; i++) {
        array[i] = array[i+1];
    }
    array[i] = 0;
}

void reverse(int *array) {
    for(int i=0; i<MAX/2; i++) {
        int temp = array[i];
        array[i] = array[MAX-1-i];
        array[MAX-1-i] = temp;
    }
}

void search(int *array, int num) {
    int i;
    for(i=0; i<MAX; i++) {
        if(array[i] == num) {
            printf("%d found in position %d\n", num, i);
            return;
        }
    }
    if(i == MAX) {
        printf("%d not found in array\n", num);
    }
}

void display(int *array) {
    for(int i=0; i<MAX; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    for(int i=0; i<MAX; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}
