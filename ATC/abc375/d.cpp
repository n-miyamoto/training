#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	string s;
	cin >> s;

	//init
	vector<ll> count('Z'+1, 0);
	vector<ll> psum('Z'+1, 0);
	count[s[0]]++; 
	
	ll ans = 0;
	for(int i=1;i<s.size();i++){
		ans += i*count[s[i]] - psum[s[i]] - count[s[i]];
		count[s[i]]++; 
		psum[s[i]]+=i; 
	}

	cout << ans << endl;

	return 0;
}
