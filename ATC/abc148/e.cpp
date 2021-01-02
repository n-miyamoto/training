#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 
#define MX (1000000000000000000)


ll n;
ll e5 = 0;

ll find_e5(void){
	ll ret = 1;
	ll tmp = 1;
	while(MX>tmp){
		tmp *=5;
		ret++;
	}
	return ret;
}

int main(void){
	cin >> n;
	if(n%2 == 1){
		cout << 0 << endl;
		return 0;
	}

	e5 = find_e5();
	//cout << e5 << endl;

	ll md = 1;
	ll ans = 0;
	for(int i=0;i<e5;i++){
		md*=5;
		ans += (n/md)/2;
	}
	
	cout << ans << endl;
	return 0;
}
