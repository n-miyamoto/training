#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

ll n;
ll x,m;
ll used[BUF];
ll sum[BUF];



int main(void){
	cin >> n >> x >> m;
	used[x] = 1;
	sum[1] = x;

	ll cur = x;
	ll ans = x;
	for(int i=2; i<=n; i++){
		ll next = cur*cur%m;

		sum[i] = sum[i-1] + next;
		if(used[next]){
			ll head = used[next];
			ll t = i - head;
			ll k = (n - head)/t;
			ll tail = (n - head)%t;
			ans = sum[head] + k*(sum[i]-sum[head]) + sum[head + tail] - sum[head];
			break;
		}

		cur = next;
		used[cur] = i;
		ans = sum[i];
	}

	cout << ans << endl;

	return 0;
}
