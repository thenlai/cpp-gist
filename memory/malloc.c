#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int **c, a, b, i, j;
	scanf("%d %d", &a, &b);

	c=(int**)malloc(a * a * sizeof(int));
	for(i=0; i<a; i++) {
		c[i]=(int*)malloc(a*sizeof(int));
	}
	for(i=0;i<a;i++) {
		for(j=0;j<a;j++) {
			c[i][j]=0;
		}
	}

	for(i=0;i<a;i++) {
		for(j=0;j<a;j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	
	//orientation, 0,2 horizontal, 1,3 vertical
	int o=0;
	int h=a, v=a;
	int step=0;
	int index=0;
	int total = a*a;
	int x=0;
	int y=0;
	while(index<16) {
		if(o==0) {
			while(y<h) {
			      printf("%d %d\n", x, y);
			      c[x][y]=index++;
			      y++;

			}
			o=1;
			v--;
		} else if(o==1) {
			while(x<v-1) {
				printf("%d %d\n", x, y);
				c[x][y]=index++;
			}
			o=2;
			h--;
		} else if(o==2) {
			while(y>step) {
				printf("%d %d\n", x, y);			
				c[x][y]=index++;
			}
			o=3;
			//v--;
		} else if(o==3) {
			while(x>step) {
				printf("%d %d\n", x, y);
				c[x][y]=index++;
			}
			o=0;
			step++;
			//h--;
		}
		printf("h=%d, v=%d\n", h, v);
	}
	
	for(i=0;i<a;i++) {
		for(j=0;j<a;j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

// 4
// 0 1 2 3
//
