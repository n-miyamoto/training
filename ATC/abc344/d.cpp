#include <bits/stdc++.h>

using namespace std;
#define INF (10000)
#define ll long long 


int main(void){
	string t;
	int n;
	cin >> t >> n;

	vector<vector<int>> dp(n+1);
	for(auto &v : dp){
		v.resize(t.size()+1);
	}


	//Initialize dp
	for(auto& v: dp){
		for(auto& x: v){
			x = INF;
		}
	}
	for(int i=0;i<=n;i++) dp[i][0] = 0;

	//dp
	for(int i=1;i<=n;i++){
		int a;
		cin >> a;
		vector<string> s(a);

		for(auto& x: s){
			cin >> x;
		}

		//cout << a << endl;
		//for(const auto& x: s){
		//	cout << x << " " ;
		//}
		//cout << endl;

		for(int j=0;j<=t.size();j++){
			dp[i][j] = dp[i-1][j];
		}

		for(int j=0;j<=t.size();j++){
			if( dp[i-1][j] < INF ){
				for(const auto& x: s){
					const auto l = x.size();
					const auto sub_str = t.substr(j, l);
					//cout << "--- : " << x << " " << sub_str << endl;
					if(sub_str == x){
						dp[i][j+l] = min(dp[i][j+l], dp[i-1][j] + 1);
					}
				}
			}
		}
	}

	//for(const auto& v: dp){
	//	for(const auto& x: v){
	//		cout << x ;
	//		cout << "\t";
	//	}
	//	cout << endl;
	//}

	if(dp[n][t.size()] < INF){
		cout << dp[n][t.size()] << endl;
	}else{
		cout << -1 << endl;
	}

	return 0;
}
