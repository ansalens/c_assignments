#include <stdio.h>
#include <stdlib.h>

/* Some fun stuff: https://stackoverflow.com/questions/38685724/difference-between-ms-and-s-scanf */

int main(void) {
    char *first_name;
    char *last_name;
    
    printf("Enter your first name: ");
    scanf("%ms", &first_name);

    printf("Enter your last name: ");
    scanf("%ms", &last_name);

    printf("Your name is %s %s!\n", first_name, last_name);

    free(first_name);
    free(last_name);

    return 0;
}
