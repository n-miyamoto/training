#include <bits/stdc++.h>

using namespace std;
#define BUF (300005)
#define ll long long 
#define INF ((ll)1000000005 * BUF)

int n;
vector<ll> A;
vector<ll> dp[4];

int main(void){
	//read input
	cin >> n;
	A.resize(n);
	for(int i = 0;i<n;i++){
		cin >> A[i];
	}

	// initialize dp
	for(int i=0;i<4;i++){
		dp[i].resize(n);
	}
	dp[0][0] = 0;
	dp[1][0] = INF;
	dp[2][0] = INF;
	dp[3][0] = A[0];

	// solve dp
	for(int i = 1;i<n;i++){
		dp[0][i] = dp[1][i-1];
		dp[1][i] = min(dp[0][i-1], dp[1][i-1]) + A[i];
		dp[2][i] =  dp[3][i-1];
		dp[3][i] = min(dp[2][i-1], dp[3][i-1]) + A[i];
	}

	//out answer
	ll ans = INF;
	for(int i=1;i<4;i++){
		ans = min(ans, dp[i][n-1]);
	}

	cout << ans << endl;
	return 0;
}
