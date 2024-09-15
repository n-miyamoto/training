#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n;
	cin >> n;

	vector<vector<ll>> G(n+1, vector<ll>(n+1,0));
	ll mg;
	cin >> mg;
	for(ll i=0;i<mg;i++){
		ll u, v;
		cin >> u >> v;

		G[u][v] = 1;
		G[v][u] = 1;
	}

	vector<vector<ll>> H(n+1, vector<ll>(n+1,0));
	ll mh;
	cin >> mh;
	for(ll i=0;i<mh;i++){
		ll u, v;
		cin >> u >> v;

		H[u][v] = 1;
		H[v][u] = 1;
	}

	vector<vector<ll>> A(n+1, vector<ll>(n+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			ll x; cin >> x;
			A[i][j] = x;
			A[j][i] = x;
		}
	}

	vector<ll> perm(n);
	std::iota(perm.begin(), perm.end(), 1);
	//for(const auto &x : perm) cout << x << " ";


	ll ans = numeric_limits<long long>::max();
	do{
		ll cost = 0;
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				if(G[i][j]!=H[perm[i-1]][perm[j-1]]){
					cost += A[perm[i-1]][perm[j-1]];
				}
			}
		}

		ans = min(ans, cost);
        
    }while(next_permutation(perm.begin(),perm.end()));

	cout << ans << endl;
	
	return 0;
}
