#include <bits/stdc++.h>

using namespace std;
using ll=long long;

bool in_range(ll i, ll j, ll n){
	if(i<=n && j<=n && i>0 && j>0) return true;
	return false;
}

int main(void){
	ll n, m;
	cin >> n >> m;

	vector<ll> a(m), b(m);
	for(int i=0;i<m;i++){
		cin >> a[i] >> b[i];
	}

	set<ll> st;

	for(int i=0;i<m;i++){
		st.insert(n*a[i] + b[i]);
		if(in_range(a[i]+2, b[i]+1, n)) st.insert(n*(a[i]+2)+b[i]+1);
		if(in_range(a[i]+1, b[i]+2, n)) st.insert(n*(a[i]+1)+b[i]+2);
		if(in_range(a[i]-1, b[i]+2, n)) st.insert(n*(a[i]-1)+b[i]+2);
		if(in_range(a[i]-2, b[i]+1, n)) st.insert(n*(a[i]-2)+b[i]+1);
		if(in_range(a[i]-2, b[i]-1, n)) st.insert(n*(a[i]-2)+b[i]-1);
		if(in_range(a[i]-1, b[i]-2, n)) st.insert(n*(a[i]-1)+b[i]-2);
		if(in_range(a[i]+1, b[i]-2, n)) st.insert(n*(a[i]+1)+b[i]-2);
		if(in_range(a[i]+2, b[i]-1, n)) st.insert(n*(a[i]+2)+b[i]-1);
	}

	cout << n*n-st.size()<< endl;
	
	return 0;
}
