#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
ll a[BUF]; 

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];

	ll mn = 2;
	ll mx = 2;

	for(int i=n;i>0;i--){
		ll mnk,mxk;
		if(mn%a[i]==0) mnk=mn/a[i];
		else mnk = mn/a[i]+1;
		mxk = mx/a[i];
		if(mxk<mnk){
			cout << -1 << endl;
			return 0;
		}

		mn = a[i]*mnk;
		mx = a[i]*mxk+a[i]-1;

/*
		if(mn/a[i]==mx/a[i] && mn%a[i]!=0 && mx%a[i]!=0 ){
			cout << -1 << endl;
			return 0;
		}
		
		if(mn%a[i]!=0) mn = (mn/a[i]+1)*a[i];
		mx = mx/a[i]*a[i]+a[i]-1;
*/
//		cout << mn << mx<< "\n";

	}

	cout << mn <<" " << mx << endl;

	return 0;
}
