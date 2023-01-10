#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll n;

vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;

    for (ll p = 2; p * p <= N; ++p) {
        if (N % p != 0) {
            continue;
        }

        ll e = 0;
        while (N % p == 0) {
            ++e;

            N /= p;
        }

        res.emplace_back(p, e);
    }

    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}

int main(void){
	cin >> n;
	auto v = prime_factorize(n);

	ll ans = 1;
	ll max_prime = 1;
	for(auto x : v){
		ll tmp = 0;
		if(x.first < 10){
			int i=0;
			while(x.second>0){
				i++;
				int k=0;
				int l=i*x.first;
				while(l%x.first==0){
					k++;
					l/=x.first;
				}
				x.second-= k;
			}
			tmp = i*x.first;
		}else{
			tmp = x.first*x.second;
		}

		if(ans < tmp){
			ans = tmp;
		}
	}

	cout << ans << endl;
	return 0;
}
