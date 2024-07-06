#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void){
	int n, t;
	cin >> n >> t;

	string s;
	cin >> s;

	vector<ll> to_left, to_right;
	for(const auto &x : s){
		ll tmp;
		cin >> tmp;
		if(x=='0') to_left.push_back(tmp);
		else to_right.push_back(tmp);
	}

	sort(to_left.begin(), to_left.end());
	sort(to_right.begin(), to_right.end());

	ll ans = 0;
	for(const auto &x : to_right){
		auto lower = std::upper_bound(to_left.begin(), to_left.end(), x);
		auto upper = std::upper_bound(to_left.begin(), to_left.end(), x + 2*t);
		ans += std::distance(lower, upper);
	}

	cout << ans << endl;

	return 0;
}
