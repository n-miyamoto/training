#include <bits/stdc++.h>
#include <omp.h> 

using namespace std;
#define BUF (150005)
#define ll long long 
#define MOD (998244353)


int N, M, K;
ll S[5005];
ll S_prev[5005];

int main(void){
	cin >> N >> M >> K;


	for(int m=1;m<=M;m++) S[m] = 1;


	for(int n=2; n<=N; n++){
		for(int m=1;m<=M;m++) S_prev[m] = S[m];

		// calc S[1]
		S[1] = 0;
		for(int m=1+K;m<=M;m++){
			S[1] += S_prev[m]%MOD;
		}

		// calc S[2~M]
		for(int m=2;m<=M;m++){
			S[m] = S[m-1];

			if(m+K-1<=M){
				S[m] += MOD;
				S[m] -= S_prev[m+K-1];
				S[m] %=MOD;
			}

			if(m-K>=1){
				S[m] += S_prev[m-K];
				S[m] %=MOD;
			}
		}
	}


	ll ans = 0;
	for(int m=1;m<=M;m++){
		ans += S[m];
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}
