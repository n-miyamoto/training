#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


int main(void){
	ll n, t;
	cin >> n >> t;

	vector<ll> player_score(n+1, 0);
	map<ll, ll> variety;
	variety.insert(make_pair(0, n));

	for(ll i=0;i<t;i++){
		ll a, b;
		cin >> a >> b;

		auto score_prev = player_score[a];
		player_score[a]+=b;
		auto score_cur = player_score[a];

		variety[score_prev]--;
		if(variety[score_prev]==0) variety.erase(score_prev);

		if(variety.contains(score_cur)){
			variety[score_cur]++;
		}else{
			variety.insert(make_pair(score_cur, 1));
		}

		cout << variety.size() << endl;
	}

	
	return 0;
}
