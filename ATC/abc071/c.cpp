#include <stdio.h>
#include <algorithm>

#define BUF (100005)

int N;
int A[BUF];
void input(void){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
	}
}

int main(void){
	input();
	
	std::sort(A+1,A+N+1);
	int tmp[BUF];
	int cnt=0;

	int i=0;
	while(1){
		i++;
		if(i>=N)break;
		if( A[i]==A[i+1] ){
			tmp[cnt] = A[i];
			i++;
			cnt++;
		} 
	}

	/*
	for(int j=0;j<cnt;j++){
		printf("%d\n",tmp[j]);
	}
	*/



	if(cnt<2){
		printf("0\n");
	}else{
		long ans =(long)tmp[cnt-1]*(long)tmp[cnt-2]; 
		printf("%ld\n",ans);
	}
	
	return 0;
}
