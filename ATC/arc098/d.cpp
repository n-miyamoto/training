#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

int n;
ll s[23][BUF];
ll  a[23];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		ll tmp;
		cin >> tmp;
		for(int j=0;j<22;j++){
			s[j][i] = s[j][i-1] + (tmp>>j)%2;
		}
	}
	ll ans = 0;
	for(int i=1;i<=n;++i){
		int low = i;
		int hi = n+1;
		while(low+1<hi){
			int mid = (low+hi)/2;
			int f=0;
			for(int j=0;j<22;++j){
				a[j] = s[j][mid] - s[j][i-1];
				if(a[j]>1){
					hi = mid;
					f=1;
				}
			}
			if(f) continue;
			low = mid;
		}
//		cout << i << low << "\n";
		ans += low - i + 1; 
	}

	cout << ans << endl;
	return 0;
}
