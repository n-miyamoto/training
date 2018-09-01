#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


ll n;
float snk(ll a){
	ll tmp=0;
	ll a_ = a;
	for(ll i=1;i<16;i++){
		tmp+=a_%10;
		a_/=10;
	}
	return (float)a/tmp;
}

int main(void){
	cin >> n;

	ll i=1;
	while(n){
		ll b = 10;
		float ans = snk(i);
		ll tmp=i;
		for(ll k=1;k<16;k++){
			if(ans>snk(i/b*b+b-1)){
				tmp = i/b*b+b-1;
				ans = snk(i/b*b+b-1);
			}
			b*=10;
		}
		cout << tmp << "\n";
		i=tmp+1;
		n--;
	}


	return 0;
}


