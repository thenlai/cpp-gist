#include <stdlib.h>
#include <stdio.h>

const int SIZE = 10;

int main(void) {
    int *const p;
    p = calloc(SIZE, sizeof(int));

    printf("# calloc:\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d=%d;  ", i, *(p+i));
    }
    printf("\n");

    for(int i = 0; i < SIZE; i++) {
        *(p+i) = i % 3;
    }

    for(int i = 0; i < SIZE; i++) {
        printf("%d=%d;  ", i, *(p+i));
    }
    printf("\n");
    // free(p);

    // calloc 分配的内存是初始化了的，作为对比：
    printf("# malloc:\n");
    p = malloc(SIZE * sizeof(int));
    for(int i = 0; i < SIZE; i++) {
        printf("%d=%d;  ", i, *(p+i));
    }
    printf("\n");

    for(int i = 0; i < SIZE; i++) {
        int* temp = p + i;
        *temp = i % 3;
    }

    for(int i = 0; i < SIZE; i++) {
        int* temp = p + i;
        printf("%d=%d;  ", i, *temp);
    }
    free(p);
}