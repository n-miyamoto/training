#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll a,b;
ll ans = 0;
int main(void){
	cin >> a >> b;
	ll diff = b-a+1;

	if(a%2==1){
		ans^=a;
		diff--;
	}

	if(b%2==0){
		ans^=b;
		diff--;
	}

	ans ^= (diff/2)%2;

	cout << ans << endl;
	return 0;
}
