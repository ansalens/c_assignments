#include <stdio.h>

int main(void) {
    int numerator = 0;
    int denominator = 0;

    printf("Enter a numerator: ");
    scanf("%d", &numerator);
    printf("Enter a denominator: ");
    scanf("%d", &denominator);

    if (numerator % denominator == 0)
        printf("There isn't a remainder!\n");
    else
        printf("There is a remainder!\n");

    return 0;
}
