#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n, k;
long long a[BUF];
const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k)
{
	if (n < k)
		return 0;
	if (n < 0 || k < 0)
		return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void){
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	COMinit(); //init table

	sort(a+1,a+n+1);
	long long ans = 0;

	//calc max
	for(int i=n;i>=k;i--){
		ans = ans + a[i]*COM(i-1, k-1)%MOD;
	}

	//calc min
	for(int i=1;i<=n-k+1;i++){
		ans = ans - a[i]*COM(n-i, k-1)%MOD;
	}

	cout << (ans+MOD)%MOD << endl;
	return 0;
}
