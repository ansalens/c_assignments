#include <stdio.h>

struct test {
    char character;
};

int main(void) {
    struct test *struct_pointer;
    struct test instance;

    struct_pointer = &instance;

    instance.character = 'A';
    printf("%c\n", instance.character);

    (*struct_pointer).character = 'B';
    printf("%c\n", instance.character);

    struct_pointer->character = 'C';
    printf("%c\n", instance.character);

    return 0;
}
