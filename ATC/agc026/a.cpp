#include <bits/stdc++.h>

using namespace std;
#define BUF (105)
#define ll long long 

int n;
int a[BUF];
int main(void){
	cin >> n;
	int ans = 0;
	int cnt = 0;
	a[0] = -1;
	for ( int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i-1]==a[i]) cnt++;
		else {
			ans += (cnt+1)/2;
			cnt = 0;
		}
	}

	ans += (cnt+1)/2;
	cout << ans << endl;

	return 0;
}
