#include <stdio.h>
#include <queue>
#include <string.h>

#define BUF (100)

using namespace std;

int N;
int A[BUF][BUF];


void input(void){
	printf("Read N\r\n");
	scanf("%d",&N);

	int i,j;
	char str[BUF];
	printf("Read A\r\n");
	for(i=0;i<N;i++){
		scanf("%s",str);	
		for(j=0;j<N;j++){
			A[i][j]=str[j]-0x30;
		}		
	}
}

void show(void){
	printf("N;%d\r\n",N);
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("A[%d][%d]=%d ,",i,j,A[i][j]);
		}
		printf("\r\n");
	}		
}

void swap(int *l, int a,int b){
	int temp = l[a];
	l[a] = l[b];
	l[b] = temp;
}

void printl(int *l){
	int i=0;
	for(i=0;i<N;i++){
		printf("%d \r\n",l[i]);
	}
}


int main(void){
	input();	
	show();
	int ret=0;

	int l[BUF];
	memset(l,0,sizeof(l));

	int i,j,k;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){	
			if(A[i][N-1-j]==1){
				l[i]=N-j;
				break;	
			}
		}
	}

	//printl(l);

	for(i=0;i<N;i++){

		for(j=i;j<N;j++){
			if(l[j]<=i+1){
				for(k=0;k<j-i;k++){
					ret++;
					swap(l,j-k,j-k-1);
				}
				break;
			}
		}
	}

	printf("answer %d\r\n",ret);

	return 0;
}
