#include <stdio.h>
#include <math.h>

#define BUF 10000

int N,K;
float L[BUF];

void input(void){
	scanf("%d",&N);
	scanf("%d",&K);
	int i=0;
	for(i=0;i<N;i++){
		scanf("%f",&L[i]);
	}
}

void show(void){
	printf("%d %d\r\n",N,K);
	int i=0;
	for(i=0;i<N;i++){
		printf("%f\r\n",L[i]);
	}
}

int check(float a){
	int ret=0,i;
	for(i=0;i<N;i++){
		ret += (int)floor(L[i]/a);
	}
	return ret;
}


void solve(void){
	float lb=0;
	float ub=0;
	int i;
	for(i=0;i<N;i++){
		if(ub<L[i]) ub=L[i];
	}

	while(ub-lb>0.01){
		if(check((ub+lb)/2)<K){
			ub = (ub+lb)/2;
		}else{
			lb = (ub+lb)/2;
		}
	}
	printf("ans:%f, %d",lb,check(lb));
}

int main(void){
	input();
	show();
	solve();
	return 0;
}
