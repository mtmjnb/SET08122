#include <stdio.h>

int main() {
    int integer_variable;
    size_t size;

    size = sizeof(integer_variable);

    printf("Size of Integer Variable is %zu bytes\n", size);

    return 0;
}