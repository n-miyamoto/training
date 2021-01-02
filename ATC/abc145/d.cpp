#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 
#define MAX (1000001)
#define MOD (1000000007)
int x,y;

long long fac[MAX], finv[MAX], inv[MAX];

void combination_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long combination(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void){
	combination_init();

	cin >> x >> y;

	int A = 2*x -y;
	int B = 2*y -x;
	if( A<0 || B<0 || A%3!=0 || B%3!=0){
		cout << 0 << endl;
		return 0;
	} 

	A/=3;
	B/=3;

	int total = A+B;
	int mn = min(A,B);
	cout << combination(total,mn) << endl;
	return 0;
}
