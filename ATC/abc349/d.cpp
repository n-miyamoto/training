#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

ll countTrailingZeros(ll value) {
    if (value == 0) return 63; // Special case for zero

    unsigned count = 0;
    while ((value & 1) == 0) {
        count++;
        value >>= 1;
    }
    return count;
}

int main(void){
	ll l, r;
	cin >> l >> r;
	
	ll cur = l;
	vector<pair<ll, ll>> ans;
	while(cur<r){

		auto ctz = countTrailingZeros(cur);
		ll i=ctz;
		while( ((cur>>i)+1)<<i > r){
			i--;
		}

		ans.push_back(make_pair(cur, ((cur>>i)+1)<<i ));
		cur = ((cur>>i)+1)<<i;
	}

	cout << ans.size() << endl;

	for(const auto [left, right] : ans){
		cout << left << " " << right << endl;
	}

	return 0;
}
