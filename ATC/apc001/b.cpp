#include <bits/stdc++.h>

using namespace std;
#define BUF (10000)
#define ll long long 


ll a[BUF];
ll b[BUF];
int n;


int main(void){
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];	
	for(int i=1;i<=n;i++)cin >> b[i];

	int ans = 1;

	ll sa=0;
	ll sb=0;
	for(int i=1;i<=n;i++){
		if(a[i]-b[i]>0) sb+=a[i]-b[i];
		if((a[i]-b[i])<0 && ((b[i]-a[i])%2==1)){
			sa+=(b[i]-a[i]+1)/2;
			sb++;
		}
		if(a[i]-b[i]<0 && ((b[i]-a[i])%2==0)) sa+=(b[i]-a[i])/2;
		//cout << sa << sb << "\n";
	}

	if(sa<sb)ans = 0;

	if(ans == 0) cout << "No\n";
	else cout << "Yes\n";

	return 0;
}
