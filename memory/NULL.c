#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // NULL is not real `null`, it is 0

    int *p = NULL;
    if (p==0) {
        printf("NULL is 0\n");
    }

    return 0;
}