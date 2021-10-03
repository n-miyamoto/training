#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define N (300)
#define ll long long 

int n,x,y;
vector<pair<int,int>> v;

int dp[N+1][N+1];
int dp_prev[N+1][N+1];

// show dp table for debug
void show(){
	int K = 20;
	cout << "--- dp ---" << endl;
	for(int i=0;i<=K;i++){
		for(int j=0;j<=K;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void){
	//input 
	cin >> n;
	cin >> x >> y;
	for(int i=0;i<n;i++){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}

	//calc dp table
	for(int i=0;i<n;i++){
		dp[v[i].first][v[i].second] = 1;

		for(int j = 0;j<=N; j++){
			for(int k = 0;k<=N;k++){
				if(dp_prev[j][k]){
					int tx = min(N,j + v[i].first);
					int ty = min(N,k + v[i].second);
					if(dp[tx][ty]==0)  dp[tx][ty] = dp_prev[j][k]+1;
					else dp[tx][ty] = min(dp[tx][ty], dp_prev[j][k]+1);
				}
			}
		}

		for(int j = 0;j<=N; j++)
			for(int k = 0;k<=N;k++) 
				dp_prev[j][k] = dp[j][k];


	}

	// find answer
	int ans = -1;
	for(int i=x;i<=N;i++){
		for(int j=y;j<=N;j++){
			if(dp[i][j]){
				if(ans==-1) ans = dp[i][j];
				else ans = min(ans, dp[i][j]);
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}
