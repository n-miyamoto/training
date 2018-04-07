#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;
int a[3];

int ans = 0;
int odd;

int main(void){

	cin >> a[0] >> a[1] >> a[2];

	sort(a,a+3);

	int mx = a[2];

	ans += (mx-a[0])/2;
	if((mx-a[0])%2==1) odd++;

	ans += (mx-a[1])/2;
	if((mx-a[1])%2==1) odd++;

	//cout << ans << odd;

	if(odd == 1) ans+=2;
	if(odd == 2) ans++;

	cout << ans << endl;

	return 0;
}
