#include <stdio.h>

int main(void) {
    int var = 29;
    int *pvar = &var;

    printf("pvar points to %d\n", *pvar);
    printf("pvar's address is %p\n", pvar);

    return 0;
}
