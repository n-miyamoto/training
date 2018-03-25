#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
ll sum;
ll a[BUF];
int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum+=abs(a[i]-a[i-1]);
	}
	a[n+1]=0;
	sum+=abs(a[n]-a[n+1]);

	for(int i=1;i<=n;i++){
		ll d,b,c;
		d=abs(a[i]-a[i-1]);
		b=abs(a[i+1]-a[i]);
		c=abs(a[i+1]-a[i-1]);
		cout << sum-d-b+c << "\n";
	}
	return 0;
}
