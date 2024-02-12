#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(void){
	ll n;
	cin >> n;
	n--;

	vector<ll> ans;

	while(n!=0){
		ans.push_back(n%5);
		n /= 5;
	}

	if(ans.empty()){ 
		cout << 0 << endl;
		return 0;
	};

	std::reverse(ans.begin(), ans.end());
	for(const auto & x : ans) cout << 2*x;
	cout << endl;

	return 0;
}
