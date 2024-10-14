#include <bits/stdc++.h>

using namespace std;
using ull= unsigned long long;

const ull MOD = 998244353ULL; 

ull modular_pow(ull base, ull exp, const ull mod) {
    ull result = 1;
    base = base % mod;  // もしbaseがmodより大きければmodで割った余りにする

    while (exp > 0) {
        // expが奇数なら、結果にbaseを掛ける
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }

        // expを半分にする
        exp = exp >> 1;  // expを2で割る
        base = (base * base) % mod;  // baseを自乗してmodを取る
    }

    return result%mod;
}


ull f(const ull n, const ull i, const ull k){
	ull ret;
	if(i==1) ret = n%MOD;
	else if(i%2==0){
		ull tmp = f(n, i/2, k);
		ret = (tmp * modular_pow(10, k*(i/2), MOD))%MOD;
		ret = (ret + tmp)%MOD;
	}else{
		ret = (f(n, i-1, k) * modular_pow(10, k, MOD))%MOD;
		ret = (ret + n%MOD)%MOD;
	}

	return ret%MOD;
}

int main(void){
	string N;
	cin >> N;

	ull k=N.size();
	ull n=stoll(N);

	cout << f(n,n,k) << endl;

	return 0;
}
