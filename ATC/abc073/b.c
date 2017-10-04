#include <stdio.h> 
#define SEATS (100000)
int N;
int l[SEATS];
int r[SEATS];

void input(void){
	scanf("%d",&N);
	int i=0;
	for(i=0;i<N;i++){
		scanf("%d %d",l+i,r+i);
	}
}


int main(void){
	input();	
	int i=0;
	int sum = 0;
	for(i=0;i<N;i++){
		sum+=r[i]-l[i]+1;
	}
	printf("%d\r\n",sum);
	return 0;

}