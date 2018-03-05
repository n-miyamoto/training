#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
char s[BUF][11];
ll c[258];

int main(void){
	cin >> n;

	for(int i=0;i<n;i++){
		char tmp[14];
		cin >> tmp;
		c[tmp[0]]++;
	}

	ll ans = 0;

	ans+= c['M']*c['A']*c['R'];
	ans+= c['M']*c['A']*c['C'];
	ans+= c['M']*c['A']*c['H'];
	ans+= c['M']*c['R']*c['C'];
	ans+= c['M']*c['R']*c['H'];
	ans+= c['M']*c['C']*c['H'];
	ans+= c['A']*c['R']*c['C'];
	ans+= c['A']*c['R']*c['H'];
	ans+= c['A']*c['C']*c['H'];
	ans+= c['R']*c['C']*c['H'];

	cout << ans << endl;


	return 0;
}
