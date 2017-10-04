#include <stdio.h>
#define BUF (101)

int N,K;
int x[BUF];
void input(void){
	scanf("%d",&N);
	scanf("%d",&K);
	x[0]=0; //dummy
	for(int i=1;i<=N;i++)scanf("%d",&x[i]);
}

int main(void){
	input();
	int dis=0;
	int k=K/2;
	for(int i=1;i<=N;i++){
		if(x[i]>k){
			 dis+=2*(K-x[i]);
		}else{
			dis+=2*x[i];
		}
	}

	printf("%d\n",dis);

	return 0;
}
