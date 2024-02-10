#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;
vector<int> q, a, b;

#define N_MAX 1000005

int main(void){
	cin >> n;
	q.resize(n);
	a.resize(n);
	b.resize(n);

	for (auto& x: q) cin >> x; 
	for (auto& x: a) cin >> x; 
	for (auto& x: b) cin >> x; 

	int ans = 0;
	for(int i=0;i < N_MAX; i++){
		bool is_neg = false;
		for(int j = 0;j<n;j++){
			if(i!=0) q[j] -= a[j];
			if (q[j] < 0) is_neg=true;
		}
		if(is_neg) break;
		int b_count = N_MAX;
		for(int j=0;j<n;j++){
			if(b[j]!=0) b_count = min(b_count, q[j]/b[j]);
		}
		ans = max(ans, i+b_count);
		//cout << i << " " << b_count << endl;
	}

	cout << ans << endl;
	
	return 0;
}
