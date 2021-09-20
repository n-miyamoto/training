#include <bits/stdc++.h>

using namespace std;
#define ll long long 

ll A, B, K;

//calc combination xCy.
ll calc_comb(ll x, ll y){
	ll ans=1;
	for(ll i=1;i<=y;i++){
		ans*=x;
		ans/=i;
		x--;
	}
	return ans;
}

string solve(ll a, ll b, ll k){

	ll total = a+b;
	ll count = 0;
	ll count_prev = 0;
	string s = "";

	if(a==0 || b==0){
		for(int i=0;i<a;i++) s.push_back('a');
		for(int i=0;i<b;i++) s.push_back('b');
		return s;
	}

	for(ll first_a_num = a;first_a_num>=0;first_a_num--){
		ll comb = calc_comb(total - first_a_num - 1, a - first_a_num);
		count_prev=count;
		count+= comb;

		if(k<=count){
			for(int i=0;i<first_a_num;i++) s.push_back('a');
			s.push_back('b');
			s+=solve(a-first_a_num, b-1, k-count_prev);
			break;
		}
	}
	return s;
}

int main(void){
	cin >> A >> B >> K;
	cout << solve(A, B, K) << endl;
	
	return 0;
}
