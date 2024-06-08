#include <iostream>
#include <bit>
#include <vector>

using namespace std;
using ll = unsigned long long;

int main(void){
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<ll>> v_test(m);
	vector<char> test_res(m);

	for(ll i=0;i<m;i++){
		ll c;
		cin >> c;
		v_test[i].resize(c);
		for(auto &x: v_test[i]) cin >> x;
		cin >> test_res[i];
	}


	ll ans = 0;
	for(ll i=0;i< (1LL<<n); i++){
		bool valid = true;
		for(ll j=0;j<m;j++){
			ll flag=0;
			for(const auto & x : v_test[j]){
				flag |= 1<<(x-1);
			}

			ll tmp = i&flag;
			auto cnt = popcount(tmp);
			if((cnt < k && test_res[j]=='o') || (cnt >= k && test_res[j]=='x')){
				valid = false; 
				break;
			}
		}

		if(valid) ans++;
	}

	cout << ans << endl;
	
	return 0;
}
