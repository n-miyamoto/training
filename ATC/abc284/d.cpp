#include <bits/stdc++.h>

using namespace std;
#define BUF (10)
#define ll long long 

ll t;
ll test[BUF];

int main(void){
	cin >> t;

	for(ll i=0;i<t;i++){
		cin >> test[i];
	}

	for(ll i=0;i<t;i++){
		for(ll j=2;j<3*1000000;j++){
			ll p, q;
			if(test[i]%j==0){
				if(test[i]%(j*j)==0){
					p=j;
					q=test[i]/p/p;
				}else{
					q=j;
					p=sqrt(test[i]/j);
				}
				cout << p << " " << q << endl;
				break;
			}
		}
	}
	
	return 0;
}
