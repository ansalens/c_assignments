#include <stdio.h>

int main(void) {
    char first_name[100];
    char last_name[100];

    printf("* * * * Welcome * * * *\n");
    printf("Please enter your first name: ");
    scanf("%s", &first_name);
    printf("Please enter your last name: ");
    scanf("%s", &last_name);

    printf("Hello %s %s, how are you?\n", first_name, last_name);

    return 0;
}
