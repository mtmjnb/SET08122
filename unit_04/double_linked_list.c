#include <stdio.h>
#include "linked_list.h"

struct node {
    int data;
    struct node *previous;
    struct node *next;
};

int main() {
    struct node *list;
    list = NULL;   

    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    append(&list, 14);
    append(&list, 30);
    append(&list, 25);
    append(&list, 42);
    append(&list, 17);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    prepend(&list, 999);
    prepend(&list, 888);
    prepend(&list, 777);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    insert_after(list, 1, 0);
    insert_after(list, 2, 1);
    insert_after(list, 5, 99);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    insert_after(list, 99, 10);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    delete(&list, 99);
    delete(&list, 1);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);

    delete(&list, 10);
    printf("No of elements in linked list = %d\n", count(list));
    display(list);
    
    return 0;
}

int count(struct node *list) {
    int count = 0;
    while (list != NULL) {
        list = list->next;
        count++;
    }
    return count;
}

void display(struct node *list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n\n");
}

void append(struct node **list, int num) {
    struct node *temp, *current = *list;
    if (*list == NULL) {
        *list = (struct node *) malloc(sizeof(struct node));
        (*list)->previous = NULL;
        (*list)->data = num;
        (*list)->next = NULL;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        temp = (struct node *) malloc(sizeof(struct node));
        temp->data = num;
        temp->next = NULL;
        temp->previous = current;
        current->next = temp;
    }
}

void prepend(struct node **list, int num) {
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->previous = NULL;
    temp->data = num;
    temp->next = *list;
    
    (*list)->previous = temp;
    *list = temp;
}

void insert_after(struct node *list, int location, int num) {
    struct node *temp;
    for (int i=0; i<location; i++) {
        list = list->next;
        if (list == NULL) {
            printf("Max index is %d but supplied location is %d\n", i, location);
            return;
        }
    }
    temp = (struct node *) malloc(sizeof(struct node));

    temp->data = num;
    temp->previous = list;
    temp->next = list->next;
    temp->next->previous = temp;
    list->next = temp;
}

void delete(struct node **list, int num) {
    struct node *temp = *list;
    while (temp != NULL) {
        if (temp->data == num) {
            if (temp == *list) {
                *list = (*list)->next;
                (*list)->previous = NULL;
            } else {
                if (temp->next == NULL) {
                    temp->previous->next = NULL;
                } else {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                }
                free(temp);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the supplied list\n", num);
}