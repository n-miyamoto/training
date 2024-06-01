#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using range = pair<ll, ll>;

int main(void){
	ll n;
	cin >> n;

	vector<range> v(n);
	for(auto &rg: v) cin >> rg.first >> rg.second;

	sort(v.begin(), v.end(), [](const range& a, const range& b) { 
		return a.first < b.first;
    });

	ll ans = 0;
	std::priority_queue<ll, std::vector<ll>, std::greater<ll>> min_pq;
	for(const auto rg: v){
		while(!min_pq.empty() && min_pq.top() < rg.first) min_pq.pop();
		ans += min_pq.size();
		min_pq.push(rg.second);
	}

	cout << ans << endl;
	
	return 0;
}
