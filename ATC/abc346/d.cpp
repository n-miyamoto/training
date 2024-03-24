#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int main(void){

	ll n;
	cin >> n;

	string s;
	cin >> s;

	vector<ll> costs(n);
	for(auto& c: costs){ cin >> c;}
	
    vector<ll> costToChangeTo0(n + 1, 0), costToChangeTo1(n + 1, 0);

    for (ll i = 0; i < n; ++i) {
        costToChangeTo0[i + 1] = costToChangeTo0[i] + (((s[i] == '0') != (i%2==0)) ? costs[i] : 0);
        costToChangeTo1[i + 1] = costToChangeTo1[i] + (((s[i] == '0') == (i%2==0)) ? costs[i] : 0);
    }

	ll ans = LLONG_MAX;
	for(ll i=0;i<n-1;i++){
		ll cost0 = costToChangeTo0[i+1] + (costToChangeTo1[n] - costToChangeTo1[i+1]);
		ll cost1 = costToChangeTo1[i+1] + (costToChangeTo0[n] - costToChangeTo0[i+1]);
		ans = min(ans, min(cost0, cost1));
	}

	cout << ans << endl;

	return 0;
}
