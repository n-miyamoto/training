#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n;
	cin >> n;
	vector<int> a(n);

	for(auto&& x : a)cin >> x;
	
	unordered_map<int, int> um;
	vector<int> b(n);
	for(int i=0;i<n;i++){
		if (um.find(a[i]) != um.end()) b[i] = um[a[i]];
		else b[i] = -1;

		um[a[i]] = i+1;
	}

	for(auto&& x : b)cout << x << " ";
	cout << endl;

	return 0;
}
