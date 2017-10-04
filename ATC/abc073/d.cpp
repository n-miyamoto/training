#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define RBUF 10
#define MBUF (100000)
#define NBUF (205)
#define INF (1<<29)


int N, M, R;

int r[RBUF];

typedef struct
{
	int from;
	int to;
	int cost;
} SIDES;

SIDES sides[MBUF];

void input(void)
{
	scanf("%d %d %d", &N, &M, &R);	
	int i = 0;
	for(i=0;i<R;i++)scanf("%d",&r[i]);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &sides[i].from, &sides[i].to, &sides[i].cost);
	}
}

int dp[NBUF][NBUF];

int min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

void dp_init(void)
{
	
	//init
	int i = 0,j;
	for(i=0;i<NBUF;i++){
		for(j=0;j<NBUF;j++){
			dp[i][j] = INF;
		}		
	}
		
	for (i = 0; i < M; i++)
	{
		dp[sides[i].from][sides[i].to] = sides[i].cost;
		dp[sides[i].to][sides[i].from] = sides[i].cost;
	}
	for (i = 0; i < NBUF; i++)
	{
		dp[i][i] = 0;
	}
}

void solve_wf(void)
{
#ifdef DEBUG
	printf("%d,%d,%d",N,R,M);
	printf("%d,%d,%d",r[0],r[1],r[2]);
	int l=0;
	for(l=0;l<NBUF;l++){
		printf("dp%d: %d\r\n",l ,dp[l][l]);
	}
#endif
	int i, j, k;
	//solve
	for (k = 1; k < N+1; k++)
	{
		for (i = 1; i < N+1; i++)
		{
			for (j = 1; j < N+1; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}
void show_dp(void)
{
	int i, j;
	//solve
	for (i = 0; i < N+1; i++)
	{
		for (j = 0; j < N+1; j++)
		{
			printf("dp %d,%d : %d\r\n",i,j,dp[i][j]);
		}
	}
}
bool used[RBUF];
int res;

void dfs(int c, int las, int dist){
	if(c==R+1){
		if(res>dist)res = dist;
		return;
	}

	for(int i=0;i<=R;i++){
		if(!used[i]){
			used[i]= true;
			if(las==-1)dfs(c+1,i,0);
			else dfs(c+1,i,dist+dp[r[las]][r[i]]);
			used[i] = false;
		}
	}
}

int main(void)
{
	input();
	dp_init();
	solve_wf();
#ifdef DEBUG
	show_dp();
#endif
	int i=0;
	for(i=0;i<RBUF;i++){
		used[i]=false;
	}
	res = INF;
	dfs(1,-1,0);	
	printf("%d\n",res);
	return 0;
}