#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

int n;

ll A[BUF];
ll B[BUF];

ll a[BUF];
ll b[BUF];


int main(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> A[i];
	for(int i=1;i<=n;i++) cin >> B[i];

	ll ans=0;
	for(int k=0;k<31;k++){
		ll cnt = 0;
		ll T = 1 << k;
		for(int i=0;i<=n;i++) a[i] = A[i]%(2*T);
		for(int i=0;i<=n;i++) b[i] = B[i]%(2*T);
		sort(b+1,b+n+1);

		for(int i=1;i<=n;i++){
			ll *j0 =lower_bound(b+1,b+n+1,1*T-a[i]);
			ll *j1 =lower_bound(b+1,b+n+1,2*T-a[i]);
			ll *j2 =lower_bound(b+1,b+n+1,3*T-a[i]);
			ll *j3 =lower_bound(b+1,b+n+1,4*T-a[i]);
			cnt+= (j1-j0) + (j3-j2) ;
			//out << j0-b << j1-b << j2-b<< j3-b << " ";
			//cout << "  " << cnt << "\n";
		}
		//cout << "\n";
		//cout << T <<  k << cnt << "\n";
		if(cnt%2==1) ans+= T;
		
	}	

	cout << ans << endl;
	return 0;
}
