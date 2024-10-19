#include <bits/stdc++.h>

using namespace std;
using ll=long long;

bool is_kaibun(ll num){
	std::string str = std::to_string(num);

    std::string rev_str = str;
    std::reverse(rev_str.begin(), rev_str.end());

    return str == rev_str;
}

int main(void){
	ll n;
	cin >> n;

	ll ans = 1;
	ll i=1;
	while(i*i*i<=n){
		if(is_kaibun(i*i*i)) ans = i*i*i;
		i++;
	}

	cout << ans << endl;
	
	return 0;
}
