#include <bits/stdc++.h>

using namespace std;
using ll=unsigned long long;

int main(void)
{
	ll a, b, C;
	cin >> a >> b >> C;

	ll X=0,Y=0;
	//Check 1 bit
	for(ll i=0;i<61;i++){
		if(C>>i & 1){
			if(a>b){
				X |= (ll)1<<i;
				a--;
			}else{
				Y |= (ll)1<<i;
				b--;
			}
		}
		//cout << "dbg:" << a << " " << b << " " << X << " " << Y << endl;
	}

	if(a!=b){
		cout << -1 << endl;
		return 0;
	}

	//Check 0 bit
	for(ll i=0;i<61;i++){
		if((C>>i & 1) == 0){
			if(a>0){
				X |= (ll)1<<i;
				Y |= (ll)1<<i;
				a--;
			}

			if(a==0) break;
		}
		//cout << "dbg:" << a << " " << X << " " << Y << endl;
	}

	if(a>0) cout << -1 << endl;
	else cout << X << " " << Y << endl;

	//test
	//int cnt_a = 0, cnt_b = 0;
	//for(int i=0;i<63;i++){
	//	if (X>>i &1) cnt_a++;
	//	if (Y>>i &1) cnt_b++;
	//}
	//cout << "a " << cnt_a<< endl;
	//cout << "b " << cnt_b<< endl;
	//cout << "X^Y==C " << (X^Y) << endl;

	return 0;
}
