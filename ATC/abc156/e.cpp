#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 
#define MOD (1000000007)
#define MAX (210000)

long long fac[MAX], finv[MAX], inv[MAX];
ll n, k;

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// a^n mod を計算する
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main(void){
	COMinit();
	cin >> n >> k;
	ll ans = 0;
	for (int i = 0; i <= k; i++)
	{
		if(n==i) break;
		ll tmp = 1;
		tmp = COM(n,i);
		tmp %= MOD;
		tmp *= COM(n-1,i);
		tmp %= MOD;
		ans += tmp;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
