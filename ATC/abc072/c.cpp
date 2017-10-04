#include <stdio.h>
#include <algorithm>

#define NBUF (100005)
int N;
int a[NBUF];

void input(void){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&a[i]);
}

int main(void){
	input();
	std::sort(a,a+N);
	//for(int i=0;i<N;i++)printf("%d ",a[i]);
		
	int max=0;
//	int X=-1;
	int lower;
	int upper;
	for(int i=0;i<N;i++){
		lower = i;
		upper = N;
		int index;
		while(1){
			index = (lower+upper)/2;
			//printf("i %d index %d",i,index);
			if(a[index]-a[i]<3){
				if(index==N-1)break; 
				if(a[index+1]-a[i]>2)break;
				lower = index;	
			}else
			{
				upper = index;
			}
		}
		int cnt = index-i+1;
		if(max<cnt){
			max = cnt;
			if(cnt>N-i) break;
			//X=a[i]+1;
		}
	}

	printf("%d\n",max);
	return 0;
}
