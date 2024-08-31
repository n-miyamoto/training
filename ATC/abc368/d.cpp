#include <bits/stdc++.h>

using namespace std;
using ll=long long;


bool search(int node, vector<bool> &keep, vector<bool> &passed, const vector<vector<int>> &tree){
	//cout << "node : " << node << endl;
	passed[node] = true;

	bool ret = false;
	for(const auto next: tree[node]){
		if(!passed[next]){
			if(search(next, keep, passed, tree)) ret = true;
		}
	}

	passed[node] = false;
	if(!ret){
		return keep[node];
	}else{
		keep[node] = true;
		return true;
	}
}


int main(void){
	int n, k;
	cin >> n >> k;

	vector<vector<int>> v(n+1);

	for(int i=0;i<n-1;i++){
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<bool> keep(n+1, false);
	int root ;
	for(int i=0;i<k;i++){
		int a;
		cin >> a;
		keep[a]=true;
		root = a;
	}

	vector<bool> passed(n+1, false);
	search(root, keep, passed, v);

	auto ans = std::count(keep.begin(), keep.end(), true);
	
	cout << ans << endl;

	return 0;
}
