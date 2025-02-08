#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll findMax(ll K, ll initial) {
    ll left = 0, right = initial, ans = 0;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (mid * mid <= K) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(void){
	ll r;
	cin >> r;

	ll ans = 0LL;
	for(ll i=1LL; 2LL*i+1LL<= 2LL*r; i++){
		ll tmp = findMax(4LL*r*r - (2LL*i+1LL)*(2LL*i+1LL), 2*r + 5);
		ans += (tmp+1)/2;
	}

	ans*=4;
	ans+=1;

	cout << ans << endl;
	
	return 0;
}
