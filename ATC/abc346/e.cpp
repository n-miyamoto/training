#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


struct query{
	ll type;
	ll idx;
	ll color;
};

int main(void){
	ll h, w, m;
	cin >> h >> w >> m;

	vector<query> queries(m);
	for (auto& q : queries) {
        cin >> q.type >> q.idx >> q.color;
    }
	
	//remove unused queries
	vector<bool> used_col(200005, false);
	vector<bool> used_row(200005, false);
	for(ll i=m-1;i>=0;i--){
		if(queries[i].type ==1){
			if(used_row[queries[i].idx]){
				queries[i].type=0;
			}
			used_row[queries[i].idx] = true;
		}else{
			if(used_col[queries[i].idx]){
				queries[i].type=0;
			}
			used_col[queries[i].idx] = true;
		}
	}

	vector<ll> prefix_sum1(m+1, 0);
	vector<ll> prefix_sum2(m+1, 0);
	for(ll i=0;i<m;i++){
		prefix_sum1[i+1] = prefix_sum1[i];
		prefix_sum2[i+1] = prefix_sum2[i];
		if(queries[i].type==1){
			prefix_sum1[i+1]++;
		}else if(queries[i].type==2){
			prefix_sum2[i+1]++;
		}else{
			// zero
		}
	}

	vector<ll> ans(200001, 0);
	for(ll i=0;i<m;i++){
		if(queries[i].type == 1){
			ans[queries[i].color] += (w - prefix_sum2[m] + prefix_sum2[i+1]);
			//cout << queries[i].color << w << prefix_sum2[m] << prefix_sum2[i+1] << endl;
		}else if(queries[i].type == 2){
			ans[queries[i].color] += (h - prefix_sum1[m] + prefix_sum1[i+1]);
			//cout << queries[i].color << h << prefix_sum1[m] << prefix_sum1[i+1] << endl;
		}
	}

	ll sum = 0;
	for(ll i=0;i<200001;i++){
		if(i!=0) sum+=ans[i];
	}
	ans[0]=h*w-sum;

	ll total = 0;
	for(ll i=0;i<200001;i++){
		if(ans[i]!=0) total++;
	}
	cout << total << endl;

	for(ll i=0;i<200001;i++){
		if(ans[i]!=0){
			cout << i << " " << ans[i] << endl;
		}
	}

	return 0;
}
