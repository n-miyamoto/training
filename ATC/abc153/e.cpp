#include <bits/stdc++.h>

using namespace std;
#define BUF (10007)
#define ll long long 
#define INF (1000000000)

int n,h;

int dp[BUF];
int a[BUF];
int b[BUF];

int main(void){
	cin >> h >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}

	for(int i=1;i<=h;i++){
		if(dp[i]==0) dp[i] = INF;
		for(int j=1;j<=n;j++){
			int k = i - a[j];
			if(k<0) k=0;
			dp[i] = min(dp[i],dp[k]+b[j]);
		}
	}
	
	cout << dp[h] << endl; 
	return 0;
}
