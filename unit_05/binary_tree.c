#include <stdio.h>
#include "binary_tree.h"

#define TRUE 1
#define FALSE 0

struct BinaryTreeNode {
    struct BinaryTreeNode *left_child;
    struct BinaryTreeNode *right_child;
    int data;
};

int main() {
    struct BinaryTreeNode *root;
    int content[] = {11, 9, 13, 8, 10, 12, 14, 15, 7};
    root = NULL;

    for (int i=0; i<=8; i++) {
        insert(&root, content[i]);
    }

    traverse(root);
    printf("\n");

    delete(&root, 10);
    traverse(root);
    printf("\n");

    delete(&root, 14);
    traverse(root);
    printf("\n");

    delete(&root, 8);
    traverse(root);
    printf("\n");

    delete(&root, 13);
    traverse(root);
    printf("\n");

    return 0;
}

void insert(struct BinaryTreeNode **node, int num) {
    if (*node == NULL) {
        *node = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
        (*node)->left_child = NULL;
        (*node)->right_child = NULL;
        (*node)->data = num;
    } else {
        if (num < (*node)->data) {
            insert(&((*node)->left_child), num);
        } else {
            insert(&((*node)->right_child), num);
        }
    }
}  

void traverse(struct BinaryTreeNode *node) {
    if (node != NULL) {
        traverse(node->left_child);
        printf("%d\t", node->data);
        traverse(node->right_child);
    }
}

void search(struct BinaryTreeNode **root, int num, struct BinaryTreeNode **parent, struct BinaryTreeNode **found_node, int *found_status) {
    struct BinaryTreeNode *temp;
    temp = *root;
    *found_status = FALSE;
    *parent = NULL;

    while (temp != NULL) {
        if (temp->data == num) {
            *found_status = TRUE;
            *found_node = temp;
            return;
        }
        *parent = temp;
        if (temp->data > num) {
            temp = temp->left_child;
        } else {
            temp = temp->right_child;
        }
    }
}

void delete(struct BinaryTreeNode **root, int num) {
    int found;
    struct BinaryTreeNode *parent, *search_node, *next;

    if (*root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    parent = search_node = NULL;
    search(root, num, &parent, &search_node, &found);

    if (found == FALSE) {
        printf("Data not found\n");
        return;
    }

    if (search_node->left_child != NULL && search_node->right_child != NULL) {
        parent = search_node;
        next = search_node->right_child;
        while (next->left_child != NULL) {
            parent = next;
            next = next->left_child;
        }
        search_node->data = next->data;
        search_node = next;
    }

    if (search_node->left_child == NULL && search_node->right_child == NULL) {
        if (parent->right_child == search_node) {
            parent->right_child = NULL;
        } else {
            parent->left_child = NULL;
        }

        free(search_node);
        return;
    }

    if (search_node->left_child == NULL && search_node->right_child != NULL) {
        if (parent->left_child == search_node) {
            parent->left_child = search_node->right_child;
        } else {
            parent->right_child = search_node->right_child;
        }

        free(search_node);
        return;
    }

    if (search_node->left_child != NULL && search_node->right_child == NULL) {
        if (parent->left_child == search_node) {
            parent->left_child = search_node->left_child;
        } else {
            parent->right_child = search_node->left_child;
        }

        free(search_node);
        return;
    }
}