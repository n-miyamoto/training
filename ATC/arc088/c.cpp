#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll x,y;

int main(void){
	cin >> x >> y;
	int ans = 0;
	while(x<=y){
		ans++;
		x*=2;
	}

	cout << ans << endl;
	
	return 0;
}
