#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

multiset<ll> I[BUF];
ll N, Q;
vector<pair<ll,ll>> queries;
vector<pair<ll,ll>> infants;

multiset<ll> rates;

int main(void){
	cin >> N >> Q;

	infants.resize(N+1);
	for(ll i=1;i<=N;i++){
		ll a,b;
		cin >> a >> b;
		I[b].insert(a);
		infants[i] = make_pair(a,b);
	}

	queries.resize(Q);
	for(ll i=0;i<Q;i++){
		ll c,d;
		cin >> c >> d;
		queries[i] = make_pair(c,d);
	}

	for(ll i=0;i<BUF;i++){
		if(I[i].empty()) continue;
		auto max_ite = I[i].end(); max_ite--;
		rates.insert(*max_ite);
	}

	for(auto q : queries){
		//for(auto rate : rates ) cout << rate << " ";

		auto i = q.first; //infants index
		auto next  = q.second; //next youchien index
		auto rate = infants[i].first; //rate of infants i
		auto curr = infants[i].second; // current youchien index

		//curr
		auto max_ite = I[curr].end();max_ite--;
		auto curr_max = *max_ite;
		rates.erase(rates.find(curr_max));
		I[curr].erase(I[curr].find(rate));

		if(!I[curr].empty()){
			max_ite = I[curr].end();max_ite--;
			auto next_max = *max_ite;
			rates.insert(next_max);
		}

		//next
		if(!I[next].empty()){
			max_ite = I[next].end();max_ite--;
			auto next_max = *max_ite;
			rates.erase(rates.find(next_max));
		}

		I[next].insert(rate);
		max_ite = I[next].end();max_ite--;
		curr_max = *max_ite;
		rates.insert(curr_max);

		infants[i] = make_pair(rate, next);
		cout << *rates.begin() << endl;
	}


	return 0;
}
