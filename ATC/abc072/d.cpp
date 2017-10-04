#include <stdio.h>
#include <stdlib.h>
#define BUF (100005)

int N;
int a[BUF];


void input(void){
	scanf("%d",&N);
	a[0] = 0; //dummy
	for(int i=1;i<=N;i++) scanf("%d",&a[i]);
}


void show_arr(int *arr, int size){
#ifdef DEBUG
	for(int i=1;i<=size;i++) printf("%d ",arr[i]);
	printf("\n");
#endif
}


int srch_nearest_index(int i){
	int cnt=1;
	while(1){
		if( i-cnt>0   && a[i-cnt]!=i) return i-cnt;
		if( i+cnt<N+1 && a[i+cnt]!=i) return i+cnt;
		cnt++;
	}
}

int main(void){
	input();

	int chk[BUF];
	chk[0]=0; //dummy
	for(int i=1;i<=N;i++)
	{
		chk[i]=1;
		if(a[i]==i)chk[i]=0;
	}

	int cnt = 0;
	for(int i=1;i<N;i++){
		if(!chk[i] && !chk[i+1]){
			//both i & i+1 is false.
			int temp = a[i];
			//a[i] = a[i+1];
			//a[i+1] = temp;
			chk[i] = true;
			chk[i+1]= true;
			cnt++;
		}
	}

	for(int i=1;i<=N;i++){
		if(!chk[i]){
			int ptr = srch_nearest_index(i);
			cnt+=abs(i-ptr);
			chk[i] = true;				
		}
	}

	show_arr(a,N);
	show_arr(chk,N);

	printf("%d\n",cnt);

	return 0;
}
