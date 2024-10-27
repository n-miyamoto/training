#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(auto&& x: a) cin >> x;


	vector<ll> rev(n, -1);
	int first;
	for(int i=0;i<n;i++){
		if(a[i]<0) first = i+1; 
		else rev[a[i]-1] = i+1;
	}

	int prev = first;
	for(int i=0;i<n;i++){
		cout << prev << " ";
		prev = rev[prev-1];
	}
	cout << endl;

	return 0;
}
