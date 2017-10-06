#include <stdio.h>
#include <queue>

#define BUF (100)

using namespace std;

int N,L,P,A[BUF],B[BUF];


void input(void){
	printf("Read N,L & P\r\n");
	scanf("%d",&N);
	scanf("%d",&L);
	scanf("%d",&P);

	int i=0;
	int *p;
	p=A;
	for(i=0;i<N;i++){
		printf("Read A[%d]\r\n",i);
		scanf("%d",p++);		
	}
	p=B;
	for(i=0;i<N;i++){
		printf("Read B[%d]\r\n",i);
		scanf("%d",p++);		
	}
}

void show(void){
	printf("N;%d, L;%d, P;%d \r\n",N,L,P);
	int i;
	for(i=0;i<N;i++){
		printf("A[%d]:%d, B[%d]:%d \r\n",i,A[i],i,B[i]);
	}
}

int main(void){
	input();	
	show();
	int i;
	int a=0;
	int b=0;
	int p=P;
	int ret=0;

	priority_queue <int> pq;

	for(i=0;i<L;i++){
		if(A[a]==i){
			pq.push(B[a]);
			a++;
		}
		if(p==0){
			if(pq.size()!=0){
				p+=pq.top();
				pq.pop();
				ret++;
			}else{
				ret = -1;
				break;
			}
		}			
		p--;
	}

	printf("answer %d\r\n",ret);

	return 0;
}
