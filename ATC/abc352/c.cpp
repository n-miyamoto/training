#include <bits/stdc++.h>

using namespace std;
using ll = long long ;

int main(void){
	ll n;
	cin >> n;

	vector<ll> a(n), b(n);

	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}

	auto sum = accumulate(a.begin(), a.end(), 0LL);

	ll ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans, sum-a[i]+b[i]);
	}

	cout << ans << endl;
	
	return 0;
}
