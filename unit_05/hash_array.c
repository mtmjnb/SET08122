#include <stdio.h>
#include "hash_array.h"

#define SIZE 10

struct DataItem {
    int data;
    int key;
};

struct DataItem *hash_array[SIZE];
struct DataItem *temp_item;
struct DataItem *item;

int main() {
    temp_item = (struct DataItem*)malloc(sizeof(struct DataItem));
    temp_item->data = -1;
    temp_item->key = -1;

    display();

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(37, 97);
    insert(10, 0);
    display();

    item = search(37);
    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }

    item = delete(item);
    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }
    display();

    item = search(37);
    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }
    display();

    return 0;
}

void display() {
    for (int i=0; i<SIZE; i++) {
        if (hash_array[i] != NULL) {
            printf(" (%d,%d)", hash_array[i]->key, hash_array[i]->data);
        } else {
            printf(" -,-");
        }
    }
    printf("\n");
}

int hash_code(int key) {
    return key % SIZE;
}

void insert(int key, int data) {
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    int hash_index = hash_code(key);
    while (hash_array[hash_index] != NULL && hash_array[hash_index]->key != -1) {
        hash_index++;
        hash_index %= SIZE;
    }
    hash_array[hash_index] = item;
}

struct DataItem *search(int key) {
    int hash_index = hash_code(key);
    while (hash_array[hash_index] != NULL) {
        if (hash_array[hash_index]->key == key) {
            return hash_array[hash_index];
        }
        hash_index++;
        hash_index %= SIZE;
    }

    return NULL;
}

struct DataItem *delete(struct DataItem *item) {
    int key = item->key;
    int hash_index = hash_code(key);

    while (hash_array[hash_index] != NULL) {
        if (hash_array[hash_index]->key == key) {
            struct DataItem *temp = hash_array[hash_index];
            hash_array[hash_index] = NULL;
            return temp;
        }
        hash_index++;
        hash_index %= SIZE;
    }
    return NULL;
}