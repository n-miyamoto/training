#include <bits/stdc++.h>

using namespace std;
#define BUF (150005)
#define ll long long 

int n, m, q;

vector<int> v[4][BUF];

int main(void){
	cin >> n >> m;

	for(int i=1;i<=n ;i++){
		v[0][i].push_back(i);
	}

	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		v[1][a].push_back(b);
		v[1][b].push_back(a);
	}

	for(int i=1;i<=n ;i++){
		for(auto x: v[1][i]){
			for(auto y: v[1][x]){
				v[2][i].push_back(y);
			}
		}
	}

	for(int i=1;i<=n ;i++){
		for(auto x: v[2][i]){
			for(auto y: v[1][x]){
				v[3][i].push_back(y);
			}
		}
	}

	cin >> q;

	for(int i=0;i<q;i++){
		int x, k;
		cin >> x >> k;
		set<int> s;
		for(int j=0;j<=k;j++){
			for(auto y: v[j][x]){
				s.insert(y);
			}
		}

		int ans = 0;
		for(auto x : s){
			ans += x;
			//cout << x;
		}

		cout << ans << endl;
	}
	return 0;
}
