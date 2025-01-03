#include <bits/stdc++.h>

using namespace std;
using ll=long long;


ll sum_from_zero(ll n){
	return n*(n+1)/2;
}

ll sum_range(ll base, ll from, ll to){
	ll ret = 0;
	for(int i=from; i<= to ; i++) ret += i-base;
	return ret;
}

ll sum_range_opt(ll base, ll from, ll to){
	ll l = to - from + 1;
	ll ret = 0;
	ret += (from-base)*l;
	ret += sum_from_zero(l-1);
	return ret;
}

int main(void){
	//input
	ll n, m;
	cin >> n >> m;
	
	vector<ll> x(m), a(m);
	for(auto &t : x )cin >> t;
	for(auto &t : a )cin >> t;


	// sort x, a
	vector<pair<ll, ll>> v;
	v.push_back(make_pair(0, 0));
	for(int i=0;i<m;i++) v.push_back(make_pair(x[i], a[i]));
	sort(v.begin(), v.end());

	// debug
	//for(const auto& [a, b]: v) cout << a << " " <<b << endl;

	// cacl prefix sum
	vector<ll> s(m+1, 0);
	bool check= true;
	for(int i=1;i<=m;i++){
		s[i] = s[i-1] + v[i].second;
		if(v[i].first>(s[i-1]+1)) check=false; 
	}
	if(s[m]!=n) check=false;

	// check
	if(!check) {
		cout << -1 << endl;
		return 0;
	}

	// calc sum
	ll ans = 0;
	for(int i=1;i<=m;i++){
		ans += sum_range_opt(v[i].first, s[i-1]+1,  s[i]);
		//cout << ans << v[i].first <<  s[i-1]+1 <<   s[i] << endl;
	}

	cout << ans << endl;

	//test
	//bool test = true;
	//for(int i=1;i<100;i++){
	//	for(int j=i;j<i+100;j++){
	//		for(int k=j;k<j+100;k++ ){
	//			auto l=sum_range(i, j, k);
	//			auto r=sum_range_opt(i, j, k);
	//			if(l!=r){
	//				test = false;
	//				cout << "false : " << i << " " << j << " " << k << endl;
	//			}
	//		}
	//	}
	//}
	//cout << "test res : " << test << endl;

	return 0;
}
