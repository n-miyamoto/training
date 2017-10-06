#include <stdio.h>
#include <algorithm>
#include <vector>


#define BUF (100)

int A[BUF],B[BUF],C[BUF],D[BUF];
int N;
int ans =0;
void input(void){
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
	for(i=0;i<N;i++){
		scanf("%d",&C[i]);
	}for(i=0;i<N;i++){
		scanf("%d",&D[i]);
	}
}

void show(void){
	printf("N:%d\r\n",N);
	int i;
	for(i=0;i<N;i++){
		printf("A,B,C,D:%d,%d,%d,%d\r\n",A[i],B[i],C[i],D[i]);
	}
}

void solve(void){
	int AB[BUF];
	int CD[BUF];
	std::vector<int> ab,cd;

	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			AB[i*N+j]=A[i]+B[j];
			ab.push_back(AB[i*N+j]);
			CD[i*N+j]=C[i]+D[j];
			cd.push_back(CD[i*N+j]);
		}
	}
	
	std::sort(ab.begin(), ab.end());
	std::sort(cd.begin(), cd.end());	

	for(i=0;i<N*N;i++){
		for(j=0;j<N*N;j++){
			if(0==ab[i]+cd[j]){
				ans++;
			}else if(ab[i]+cd[j]>0){
				break;
			}
		}
	}	
}

int main(void){
	input();
	show();
	solve();
	printf("answer: %d\r\n",ans);
	return 0;

}
