#include <stdio.h>
#define PI 3.14

int main(void) {
    float radius = 0;
    float area = 0;

    printf("Please enter radius: ");
    scanf("%f", &radius);

    area = radius * radius * PI;

    printf("Area of circle is: %.2f\n", area);

    
    return 0;
}
