#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int main(void){
	string s;
	cin >> s;

	vector<ll> hist(26, 0);

	for(const auto & c : s) hist[c-'a']++;

	bool same_string=false;
	ll ans = 0;
	for (char ci='a'; ci<= 'z' ; ci++){
		for (char cj=ci; cj<= 'z' ; cj++){
			if(ci==cj){
				if(hist[ci-'a'] >=2) same_string=true;
			}else{
				ans += hist[ci-'a'] * hist[cj-'a'];
			}
		}
	}

	if(same_string) ans++;

	cout << ans << endl;

	return 0;
}
