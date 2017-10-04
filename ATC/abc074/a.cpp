#include <stdio.h>
#include <stdlib.h>

int N,A;

void input(void){
	scanf("%d",&N);
	scanf("%d",&A);
}

int main(void){
	input();
	printf("%d\n",N*N-A);
	return 0;
}
