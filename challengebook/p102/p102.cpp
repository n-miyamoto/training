#include <stdio.h>

#define BUF (305)
#define INF (10000000000)

int N;
int A[BUF][BUF];

void input(void){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&A[i][j]);
		}
	}
}

int dp[BUF][BUF];
void wf_init(void){
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dp[i][j] = A[i][j];
		}
	}
}

int min(int a, int b){
	if(a>b) return b;
	return a;
}

void solv_wf(void)
{
	wf_init();

	for (int k = 1; k <= N : k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j] );
			}
		}
	}
}

int main(void)
{
	input();
	solv_wf();
	
	return 0;
}
