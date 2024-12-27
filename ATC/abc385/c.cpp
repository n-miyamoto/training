#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n;
	cin >> n;

	vector<int> h(n);
	for(auto&& x: h) cin >> x;

	int ans = 1;
	for(int t=1;t<=n;t++){
		for(int i=0;i<t;i++){
			int prev = 0, cnt = 1;
			for(int j=i;j<n;j+=t){
				if(prev == h[j]){
					cnt++;
				}else{
					cnt=1;
				}
				prev = h[j];
				ans = max(ans, cnt);
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}

