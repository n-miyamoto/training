#include <stdio.h>

#define BUF (60)
int N;
char S1[BUF];
char S2[BUF];

void input(void){
	scanf("%d",&N);
	scanf("%s",S1);
	scanf("%s",S2);
}

void show(void){
	printf("%d\n%s\n%s\n",N,S1,S2);
}

int main(void){
	input();

	unsigned int ans = 1;
	int prev = 0; //0: x 1:| 2:-
	for(int i=0;i<N;i++){
		if(S1[i] ==S2[i]){
			if(prev == 0){
				ans*=3;
			}else if(prev == 1){
				ans*=2;
			}else if(prev == 2){
			}
			prev = 1;
		}else{
			if(prev==0){
				ans*=6;
			}else if(prev==1){
				ans*=2;
			}else if(prev==2){
				ans*=3;
			}
			i++;
			prev = 2;
		}
		
		if( ans>=1000000007){
			ans%=1000000007;
		}

	//		printf("%d %u\n",i,ans);
	}

	printf("%u\n",ans);

	return 0;
}
