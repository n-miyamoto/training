#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll K;
string S,T;

ll prob[10][10];
ll rest[10];
ll total_rest;

vector<ll> s, t;

ll pow10(ll n){
	ll ret = 1;
	for(ll i=0;i<n;i++) ret*=10;
	return ret;
}

ll calc_score(vector<ll> &v){
	ll ret = 0;
	vector<ll> hist(10);
	for(auto &x : hist) x = 0;
	for(auto x : v) hist[x]++;

	for(ll i=1;i<=9;i++){
		ret += i * pow10(hist[i]);
	}
	return ret;
}

int main(void){
	cin >> K >> S >> T;

	for(auto c : S) if(c!='#') s.push_back(c - '0');
	for(auto c : T) if(c!='#') t.push_back(c - '0');

	//calc rest
	for(ll i=1;i<=9;i++) rest[i] = K;
	for(auto x : t) rest[x]--;
	for(auto x : s) rest[x]--;
	for(auto x : rest) total_rest += x;

	// calc prob
	for(ll i=1;i<=9;i++){
		for(ll j=1;j<=9;j++){
			if(i==j){
				prob[i][j] = rest[i]*(rest[i]-1);
			}else{
				prob[i][j] = rest[i]*rest[j];
			}
		}
	}

	double ans = 0.0;
	for(ll i=1;i<=9;i++){
		for(ll j=1;j<=9;j++){
			vector<ll> s_ = s;
			vector<ll> t_ = t;
			s_.push_back(i);
			t_.push_back(j);
			ll s_score = calc_score(s_);
			ll t_score = calc_score(t_);
			if(s_score>t_score){
				ans += (double)prob[i][j]/total_rest/(total_rest-1);
			}
		}
	}


	cout << fixed << setprecision(15) << ans << endl;

	
	return 0;
}
