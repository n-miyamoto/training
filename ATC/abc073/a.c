#include <stdio.h> 


int N;

int main(void){
	scanf("%d",&N);

	if(N/10==9){
		printf("Yes\r\n");
		return 0;
	}

	if(N%10==9){
		printf("Yes\r\n");
		return 0;
	}

	printf("No\r\n");

	return 0;
}