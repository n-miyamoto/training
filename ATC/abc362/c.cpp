#include <bits/stdc++.h>

using namespace std;
using ll = long long ;

int main(void){
	ll n;
	cin >> n;

	vector<ll> r(n);
	vector<ll> l(n);

	for(int i=0;i<n;i++){
		cin >> l[i] >> r[i];
	}

	auto l_total = 0LL;
	auto r_total = 0LL;
	l_total = accumulate(l.begin(), l.end(), 0LL);
	r_total = accumulate(r.begin(), r.end(), 0LL);

	if(l_total > 0 || r_total < 0) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	auto total = -l_total;
	vector<ll> ans;
	for(int i=0;i<n;i++){
		if(total == 0) {
			ans.push_back(l[i]);
		}
		else if(total > (r[i] - l[i])){
			ans.push_back(r[i]);
			total -= (r[i]-l[i]);
		}else {
			ans.push_back(l[i] + total);
			total = 0;
		}
	}


	for(const auto& x : ans ) cout << x << " ";
	cout << endl;

	return 0;
}
