#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n;
	cin >> n;
	vector<int> k(n);
	for(auto& x: k) cin >> x;

	auto sum = accumulate(k.begin(), k.end(), 0);

	int ans = sum;

	for(int i=0;i< (1<<n) ; i++){
		int tmp = 0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) tmp+= k[j];
		}

		ans = min(ans, max(tmp, sum-tmp) );
	}

	cout << ans << endl;
	
	return 0;
}
