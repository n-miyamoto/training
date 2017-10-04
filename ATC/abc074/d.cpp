#include <stdio.h>
#include <stdint.h>

#define BUF (305)
#define INF (1000000003)

int N;
uint64_t A[BUF][BUF];

void input(void){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%llu",&A[i][j]);
		}
	}
}

uint64_t dp[BUF][BUF];
void wf_init(void){
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dp[i][j] = A[i][j];
		}
	}
}

void wf_init_(void){
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

	for (int k = 1; k <= N ; k++)
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

// 
int comp(void)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if(dp[i][j]!=A[i][j]) return -1;
		}
	}
	return 0;
}

uint64_t count = 0;
void solv_wf_(void)
{
	wf_init_();
	for (int i = 1; i <= N; i++)
	{
		for (int j = i+1; j <= N; j++)
		{	
			int flag = 0;
			for(int k=1;k<=N;k++){
				if(i==k || j==k){

				}
				else if (dp[i][k] + dp[k][j] == dp[i][j]){
					flag = 1;
					//printf("%d %d\n",i,j);
				}
			}
			if(!flag)
			{
				count += dp[i][j];
				//printf("%d\n",count);
			}
		}
	}
}

typedef struct {
	int from;
	int to;
	int cost;
}SIDE;

SIDE sides[BUF*BUF];

void mat2sides(void){
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			sides[cnt].from = i;
			sides[cnt].to = j;
			sides[cnt].cost = A[i][j];	
			cnt++;
		}
	}	
}

int mincost[BUF];
int used[BUF];
uint64_t total = 0;
void plim(void){
	for(int i=0;i<=N;i++){
		mincost[i] =INF;
		used[i] = false;
	}
	mincost[1]=0;

	while (1)
	{
		int	v=-1;
		for (int u = 1; u <= N; u++)
		{
			if(!used[u] && (v==-1||mincost[v]>mincost[u])){
				v = u;
			}
		}
		if(v==-1) break;

//		printf("%d,%d \n",v,total);
		used[v] = true;
		total += mincost[v];

		for (int i = 1; i <= N; i++)
		{
			mincost[i] = min(mincost[i], A[v][i]);
//			printf("mini %d",mincost[i]);
		}
	}
}

int main(void)
{
	input();
	solv_wf();
	int ret = comp();

	//No road composition.
	if(ret == -1){
		printf("%d\n",ret);
		return 0;
	}

	solv_wf_();
	//mat2sides();
	/*
	for (int i = 1; i <= N; i++)
	{
		for (int j = i+1; j <= N; j++)
		{
			int temp = A[i][j];
			A[i][j] = INF;
			solv_wf();
			if(dp[i][j]>temp) total+=temp;
			A[i][j] = temp;
		}
	}	
	*/
	printf("%llu\n",count);
	return 0;
}
