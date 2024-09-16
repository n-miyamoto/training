#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int h, w, q;
	cin >> h >> w >> q;

	vector<set<int>> row(h+1);
	vector<set<int>> col(w+1);

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			row[i].insert(j);
			col[j].insert(i);
		}
	}

	for(int i=0;i<q;i++){
		int r, c;
		cin >> r >> c;


		auto it = row[r].lower_bound(c);
		if(*it==c){
			row[r].erase(c);
		}else if(row[r].size()==0){
			// do nothing
		}else if(it==row[r].end()){
			it--;
			auto val = *it;
			row[r].erase(val);
			col[val].erase(r);
		}else if(it==row[r].begin()){
			auto val = *it;
			row[r].erase(val);
			col[val].erase(r);
		}else{
			auto next_val = *it;
			auto prev_val = *(prev(it));
			row[r].erase(next_val);
			col[next_val].erase(r);
			row[r].erase(prev_val);
			col[prev_val].erase(r);
		}

		it = col[c].lower_bound(r);
		if(*it==r){
			col[c].erase(r);
		}else if(col[c].size()==0){
			// do nothing
		}else if(it==col[c].end()){
			it--;
			auto val = *it;
			col[c].erase(val);
			row[val].erase(c);
		}else if(it==col[c].begin()){
			auto val = *it;
			col[c].erase(val);
			row[val].erase(c);
		}else{
			auto next_val = *it;
			auto prev_val = *(prev(it));
			col[c].erase(next_val);
			row[next_val].erase(c);
			col[c].erase(prev_val);
			row[prev_val].erase(c);
		}
	}

	int ans = 0;
	for(int i=1;i<=h;i++) ans += row[i].size();
	cout << ans << endl;
	
	return 0;
}
