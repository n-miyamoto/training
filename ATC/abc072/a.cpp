#include <stdio.h>


int X,t;
void input(void){
	scanf("%d %d",&X,&t);
}

int main(void){
	input();
	int ret;
	if(t>X) ret = 0;
	else ret = X-t;

	printf("%d\n",ret);
	return 0;
}