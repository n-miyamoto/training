#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n;
	cin >> n;

	ll t=0;
	for(int i=0;i<n;i++){
		ll x;
		cin >> x;


		t+= (x/5)*3;
		x %= 5;
		
        while ( x > 0) {
            ++t;
            if (t % 3 == 0) x -= 3;
            else --x;
        }

	}

	cout << t << endl;
	
	return 0;
}
