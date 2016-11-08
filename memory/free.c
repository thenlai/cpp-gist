#include <stdlib.h>

int main(void) {
	int *p1 = malloc(10 * sizeof *p1);
	free(p1);

	int *p2 = calloc(10, sizeof *p2);

	int *p3 = realloc(p2, 100*sizeof *p2);
	if(p3) {
		free(p3);
	} else {
		free(p2);
	}

	return 0;
}