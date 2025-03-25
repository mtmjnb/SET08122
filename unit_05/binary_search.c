#include <stdio.h>

#define SIZE 10

int main() {
    int array[SIZE] = {1, 2, 3, 9, 11, 13, 17, 25, 57, 90};
    int lower = 0;
    int upper = SIZE - 1;
    int key;
    int found = 0;

    printf("Enter number to search for: ");
    scanf("%d", &key);

    for (int mid=(lower+upper)/2; lower <= upper; mid=(lower+upper)/2) {
        if (array[mid] == key) {
            printf("Your number us at position %d of our array\n", mid);
            found = 1;
            break;
        }
        if (array[mid] > key) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
    if (!found) {
        printf("%d is not in the array\n", key);
    }

    return 0;
}