#include <stdio.h>

struct exampleStruct {
    int integer;
    float decimal;
    char character;
};

int main(void) {
    struct exampleStruct s1;
    s1.integer = 666;
    s1.decimal = 6.9;
    s1.character = 'L';

    printf("Structure members are:\nInteger: %d\nFloat: %f\nCharacter: %c\n", s1.integer, s1.decimal, s1.character);

    return 0;
}
