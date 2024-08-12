#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n;
	cin >> n;
    std::vector<std::vector<std::vector<ll>>> a(n+1, std::vector<std::vector<ll>>(n+1, std::vector<ll>(n+1, 0)));
	for(ll x=1;x<=n;x++){
		for(ll y=1;y<=n;y++){
			for(ll z=1;z<=n;z++){
				cin >> a[z][y][x];
			}
		}
	}

    std::vector<std::vector<std::vector<ll>>> s(n+1, std::vector<std::vector<ll>>(n+1, std::vector<ll>(n+1, 0)));
	for(ll k=1;k<=n;k++){
		for(ll j=1;j<=n;j++){
			for(ll i=1;i<=n;i++){
				s[i][j][k] = a[i][j][k]
						   + s[i-1][j][k]
						   + s[i][j-1][k]
						   + s[i][j][k-1]
						   - s[i][j-1][k-1]
						   - s[i-1][j][k-1]
						   - s[i-1][j-1][k]
						   + s[i-1][j-1][k-1];

			}
		}
	}

	ll q;
	cin >> q;
	for(ll i=0;i<q;i++){
		ll lx, ly, lz, rx, ry, rz;
		cin >> lx >> rx >> ly >> ry >> lz >> rz;
		lx--, ly--, lz--;

		ll ans =  s[rz][ry][rx]
				- s[lz][ry][rx]
				- s[rz][ly][rx]
				- s[rz][ry][lx]
				+ s[rz][ly][lx]
				+ s[lz][ry][lx]
				+ s[lz][ly][rx]
				- s[lz][ly][lx];

		cout << ans << endl;
	}

	return 0;
}
