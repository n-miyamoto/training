#include <iostream>
using namespace std;
using ll=unsigned long long;

int main(void)
{
	ll a, b, C;
	cin >> a >> b >> C;

	ll X=0,Y=0;
	//Check 1 bit
	for(ll i=0;i<61;i++){
		if((C>>i) & 1){
			if(a>b){ X |= 1LL<<i; a--;}
			else   { Y |= 1LL<<i; b--;}
		}
	}

	if(a!=b){
		cout << -1 << endl;
		return 0;
	}

	//Check 0 bit
	for(ll i=0;i<61;i++){
		if((C>>i & 1) == 0){
			if(a>0){
				X |= 1LL<<i;
				Y |= 1LL<<i;
				a--;
			}
			if(a==0) break;
		}
	}

	if(a>0) cout << -1 << endl;
	else cout << X << " " << Y << endl;

	return 0;
}
