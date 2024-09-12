#include <stdio.h>

int main(void) {
    int user_number = 0;

    printf("Enter a number between 1 and 500: ");
    scanf("%d", &user_number);

    if (user_number >= 1 && user_number < 100)
        printf("Your number is between 1 and 100\n");
    else if (user_number > 100 && user_number < 200)
        printf("Your number is between 100 and 200\n");
    else if (user_number > 200 && user_number < 300)
        printf("Your number is between 200 and 300\n");
    else if (user_number > 300 && user_number < 400)
        printf("Your number is between 300 and 400\n");
    else if (user_number > 400 && user_number < 500)
        printf("Your number is between 400 and 500\n");
    else
        switch (user_number) {
            case 100:
                printf("Your number is 100\n");
                break;
            case 200:
                printf("Your number is 200\n");
                break;
            case 300:
                printf("Your number is 300\n");
                break;
            case 400:
                printf("Your number is 400\n");
                break;
            case 500:
                printf("Your number is 500\n");
                break;
            default:
                printf("Your number doesn't belong to specified range\n");
                break;
        }

    return 0;
}
