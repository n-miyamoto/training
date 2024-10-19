#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(auto& t : a ) cin >> t;
	
	ll m;
	cin >> m;
	vector<ll> b(m);
	for(auto& t : b ) cin >> t;

	ll l;
	cin >> l;
	vector<ll> c(l);
	for(auto& t : c ) cin >> t;

	ll q;
	cin >> q;
	vector<ll> x(q);
	for(auto& t : x ) cin >> t;


	vector<ll> v;
	for(const auto A: a){
		for(const auto B: b){
			for(const auto C: c){
				v.push_back(A+B+C);
			}
		}
	}

	sort(v.begin(), v.end());

	for(const auto t: x){
    	if (binary_search(v.begin(), v.end(), t)) 	cout << "Yes\n";
    	else 										cout << "No\n";

	}

	return 0;
}
