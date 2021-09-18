#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
vector<int> c;
vector<int> v[BUF];
int used_color[BUF];
int used_node[BUF];
vector<int> ans;

void solve(int n){
	used_node[n]=1;
	if(used_color[c[n]]==0)
		ans.push_back(n);	
	used_color[c[n]]++;

	for(auto x : v[n]){
		if(used_node[x]==0){
			//cout << x << endl;
			solve(x);
		}
	}
	used_node[n] = 0;
	used_color[c[n]]--;
}

int main(void){
	cin >> n;
	c.push_back(0);
	for (int i=0; i<n; i++){
		int color;
		cin >> color;
		c.push_back(color);
	}
	
	for (int i=0; i<n-1; i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve(1);
	
	sort(ans.begin(), ans.end());
	for (auto x : ans){
		cout << x << endl;
	}

		
	return 0;
}
