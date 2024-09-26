#include <stdio.h>
#include <math.h>

/* compile with -lm flag included */

int main(void) {
    float a, b, c = 0;
    float x_plus, x_minus = 0;

    printf("Enter value of A: ");
    scanf("%f", &a);
    printf("Enter value of B: ");
    scanf("%f", &b);
    printf("Enter value of C: ");
    scanf("%f", &c);

    /* apply the formula in both cases */
    x_plus = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    x_minus = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

    if ((a * pow(x_plus, 2) + b * x_plus + c) == 0)
        printf("Plus solution is: %.2f\n", x_plus);
    else
        printf("Plus solution is: %.2f but verify just in case.\n", x_plus);
    
    if ((a * pow(x_minus, 2) + b * x_minus + c) == 0)
        printf("Minus solution is: %.2f\n", x_minus);
    else
        printf("Minus solution is: %.2f but verify just in case.\n", x_minus);

    return 0;
}
