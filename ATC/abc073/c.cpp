#include <stdio.h> 
#include <algorithm>

#define BUF 100005

int N;
long A[BUF];

void input(void){
	scanf("%d",&N);
	int i=0;
	for(i=0;i<N;i++){
		scanf("%ld",A+i);
	}
}



int main(void){
	int count=1,ptr=0,ans=0;
	input();	
	std::sort(A,A+N);
	while(ptr<N){
		int cn=A[ptr],f=0;
		while(cn==A[ptr]&&ptr<N){
			f++;
			ptr++;
		}
		ans+=f%2;
	}
	printf("%d\r\n",ans);
	return 0;
}