#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(auto& x: a) cin >> x;

	vector<ll> odd(n, 0), even(n, 0);
	odd[0] = a[0]; even[0] = 0;

	for(ll i=1;i<n;i++){
		odd[i] = max(odd[i-1], even[i-1] + a[i]);
		even[i] = max(even[i-1], odd[i-1] + 2*a[i]);
	}

	cout << max(odd[n-1], even[n-1]) << endl;
	
	return 0;
}
