#include <bits/stdc++.h>

using namespace std;
using ll=long long;


void solve(int i, const vector<int>& r, vector<int>& s, const int k, const int n){
	if(i==n){
		auto sum = accumulate(s.begin(), s.end(), 0);
		if(sum%k==0) {
			for(const auto& x : s) cout << x << " ";
			cout << endl;
		}
		return;
	}

	for(int j=1;j<=r[i];j++){
		s[i] = j;
		solve(i+1, r, s, k, n);
	}
	return ;
} 

int main(void){
	int n, k;
	cin >> n >> k;
	vector<int> r(n);
	for(auto& x: r) cin >> x;

	vector<int> s(n);
	solve(0, r, s, k, n);
	
	return 0;
}
