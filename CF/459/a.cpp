#include <bits/stdc++.h>
using namespace std;

#define BUF (1005)
#define INF (1000000005)
#define ll long long 


int n;

int dp[BUF];
int ans[BUF];

int main(void){
	cin >> n;

	//calc fib
	memset(dp,0,BUF);
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<=30;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}

	for(int i=1;i<=30;i++){
		if(dp[i]<=1001) ans[dp[i]]=1;
	//	cout << dp[i];
	}

//	cout << dp[30];
	for(int i=1;i<=n;i++){
		if(ans[i]==0) cout <<'o';
		else cout <<'O';
	}
	cout << endl;

	return 0;
}
