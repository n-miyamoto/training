#include <bits/stdc++.h>

using namespace std;
#define BUF (10005)
#define ll long long 

int n, m;
int A[10];
int dp[BUF];
int num[10] = {0,2,5,5,4,5,6,3,7,6};
vector<int> v;
int main(void){
	cin >> n >> m;
	for(int i=0;i<m;i++) cin >> A[i];
	sort(A, A+m);

	for(int i=0;i<=n;i++) dp[i] = -1;
	dp[0] = 0;

	for(int i=1;i<=n;i++){
		int tmp=-1;
		for(int j=0;j<m;j++){
			int k = i-num[A[j]];
			if(k>=0 && dp[k]>=0){
				tmp = max(tmp, dp[k]+1);
			} 
		}
		dp[i] = tmp;
	}
	
	int i = n;
	while(1){
		if(i<=0) break;
		for(int j=m-1;j>=0;j--){
			int tmp = i-num[A[j]];
			if(tmp>=0 && (dp[tmp]==(dp[i]-1)) ){
				v.push_back(A[j]);
				i=tmp;
				break;
			}
		}
	}

	for(auto x : v) cout << x;
	cout << endl;
	return 0;
}
