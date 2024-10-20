#include <bits/stdc++.h>

using namespace std;
using ll=long long;

struct status{
	int node;
	int depth;
};

int main(void){
	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);

	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		g[a-1].push_back(b-1);
	}


	vector<bool> passed(n, false);
	passed[0] = true;
	queue<status> q;
	q.push({0, 1});

	while(!q.empty()){
		status s = q.front();
		q.pop();

		for(const auto x : g[s.node]){
			if(x==0){
				cout << s.depth << endl;
				return 0;
			}
			if(!passed[x]){
				passed[x] = true;
				status next = {x, s.depth+1};
				q.push(next);
			}
		}
	}

	cout << -1 << endl;
	
	return 0;
}
