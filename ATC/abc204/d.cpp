#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;
vector<int> t;
vector<int> sum;

int dp[102][100005];

int main(void){
	cin >> n;
	t.resize(n);
	sum.resize(n);

	for(auto &x : t) cin >> x;


	//init
	sum[0] = t[0];
	dp[0][sum[0]] = 1;

	//dp
	for(int i=1;i<n;i++){
		sum[i] = sum[i-1] + t[i];
		for(int j=0;j<= sum[i-1];j++){
			if(dp[i-1][j]){
				// j, sum[i-1]-j
				dp[i][max(j +  0  ,sum[i-1]-j + t[i])] = 1;
				dp[i][max(j + t[i],sum[i-1]-j +  0  )] = 1;
			}
		}
	}
	
	//output answer
	for(int i=0;i<=sum[n-1];i++){
		if(dp[n-1][i]){
			 cout << i << endl;
			 return 0;
		}
	}

	return 0;
}
