#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n, k;
	cin >> n >> k;
	set<ll> a;
	for(int i=0;i<n;i++){
		ll tmp;
		cin >> tmp;
		if(tmp <= k) a.insert(tmp);
	}
	cout << (1+k)*k/2 - accumulate(a.begin(), a.end(), 0LL) << endl;
	
	return 0;
}
