#include <bits/stdc++.h>
using namespace std;
#define BUF (1000)
#define MOD (1000000007)


long long  n,m,k;

long long power(long long a , long long b){
	long long t=1;
	while(b!=0){
		if(b%2==1)t=t*a%MOD;
		a=a*a%MOD;
		b/=2LL;
	}
	return t;
}

int main(void){
	cin >> n >> m >> k;

	if((n+m)%2==1 && k==-1){
		cout << 0 << endl;
		return 0;
	}

	//2^(n-1)(m-1)
	long long T = power(2,n-1);
	T = power(T,m-1);
	cout << T << endl;

	return 0;
}
