#include <stdio.h>
#include <stdlib.h>

int x,a,b;

void input(void){
	scanf("%d %d %d",&x,&a,&b);
}

int main(void){
	input();
	if(abs(x-a)>abs(x-b)){
		printf("B\n");
	}else{
		printf("A\n");
	}

	return 0;
}
