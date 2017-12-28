#include <bits/stdc++.h>
using namespace std;

#define BUF (5010)
#define INF (1000000005)
#define ll long long 
#define MOD (1000000007)

int n;
char s[BUF];
ll dp[BUF][BUF];

ll dfs(int i,int j){
	if(dp[i][j]!=-1) return dp[i][j];
	//cout << i << " " << j << "\n";
	if(j==n-1){
		 dp[i][j] = 1;
		return 1;
	}

	if(s[j]=='f'){
		dp[i][j] = dfs(i+1,j+1)%MOD;
	}
	else{
		ll L=0;
		for(int k=0;k<=i;k++)L+=dfs(k,j+1)%MOD;
		dp[i][j]= L;
	}

	return dp[i][j];
}

int main(void){
	for(int i=0;i<BUF;i++)for(int j=0;j<BUF;j++){
		dp[i][j]=-1;
	}
	cin >> n;
	for(int i=0;i<n;i++) cin >> s[i];

	for(int i=0;i<n;i++) dp[i][n-1] = 1;

	for(int i=n-2;i>=0;i--){
		if(s[i]=='f'){
			for(int j=0;j<n-1;j++){
				dp[j][i]=dp[j+1][i+1]%MOD;
			}
		}else{
			dp[0][i]=dp[0][i+1];
			for(int j=1;j<=i;j++){
				dp[j][i]=dp[j-1][i]%MOD+dp[j][i+1]%MOD;
			}
		}
	}

	cout <<  dp[0][0] << endl;

/*  solve with dfs
	int cur = 0;

	cout << dfs(0,0) << endl;
*/
	return 0;
}
