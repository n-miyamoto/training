#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll n, m, k;
	cin >> n >> m >> k;


	//Guarantee n < m by swapping
	if(n>m){
		const auto tmp = n;
		n=m;
		m=tmp;
	}


	const auto l = lcm(n, m);
	const auto count_n = l/n-1;
	const auto count_m = l/m-1;
	const auto count_nm= count_n+count_m;

	//cout << n << m << l << endl;
	//cout << "n m nm " << count_n << count_m << count_nm << endl;

	const auto block_num = (k+count_nm-1)/count_nm;
	const auto k_mod = (k+count_nm-1)%count_nm + 1;
	//cout << "block mod "  << block_num << k_mod << endl;

	for(int i=1,j=1,count = 1; i <= count_n ; i++, count++){
		auto cur = n*i;
		//cout << "count cur " << count << cur << endl;

		if(count==k_mod){
			cout << (block_num-1) * l + cur << endl;
			return 0;
		}

		
		if(cur < j*m && j*m < (cur+n)){
			count++;
			cur = m*j;
			j++;
		}
		if(count==k_mod){
			cout << (block_num-1) * l + cur << endl;
			return 0;
		}
	}

    return 0;
}