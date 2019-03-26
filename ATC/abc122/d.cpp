#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 
#define MOD 1000000007
int n;


char str[105];
char A=1;
char C=2;
char G=3;
char T=4;

ll dp[5][5][5][105];

ll dfs(int k){
	//printf("%d, %d\r\n", k, str[k]);

	if(k==n) return 1;
	ll ret = 0;

	if(k>1 && dp[str[k-2]][str[k-1]][str[k]][k]!=0){
		return dp[str[k-2]][str[k-1]][str[k]][k];
	}

	str[k+1] = A;
	ret += dfs(k+1)%MOD;

	str[k+1] = C;
	if(k>0 && str[k-1]==A && str[k]==G ){ //AGC
		ret += 0;
	}else if(k>0 && str[k-1]==G && str[k]==A ){ //GAC
		ret += 0;
	}else if(k>1 && str[k-2]==A && str[k-1]==G ){ //AGxC
		ret += 0;
	}else if(k>1 && str[k-2]==A && str[k]==G ){ //AGxC
		ret += 0;
	}else{
		ret += dfs(k+1)%MOD;
	}

	str[k+1] = G;
	if(k>0 && str[k-1]==A && str[k]==C ){ //ACG
		ret += 0;
	}else{
		ret += dfs(k+1)%MOD;
	}

	str[k+1] = T;
	ret += dfs(k+1)%MOD;

	if(k>1 && dp[str[k-2]][str[k-1]][str[k]][k]==0){
		dp[str[k-2]][str[k-1]][str[k]][k] = ret%MOD;
	}
	return ret%MOD;
}

int main(void){
	cin >> n;
	cout << dfs(0) << endl;	
	return 0;
}
