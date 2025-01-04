#include <bits/stdc++.h>

using namespace std;
using ll=unsigned long long;

char toggleCase(char c) {
	return islower(c) ? toupper(c) : tolower(c);
}

int main(void){
	string s;
	cin >> s;

	ll q;
	cin >> q;

	vector<ll> K(q);
	for(auto&& k: K) cin >> k;

	for(const auto& k: K){
		ll M=(k-1)/s.length();
		ll m=(k-1)%s.length();

		if(__builtin_popcountll(M)%2)
			cout << toggleCase(s[m]) << " ";
		else
			cout << s[m] << " ";
	}
	cout << endl;
	
	return 0;
}
