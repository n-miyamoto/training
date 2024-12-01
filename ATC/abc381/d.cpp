#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void){
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto&x : a) cin >> x;
	a.push_back(0);

	// encocde
	vector<int> vi;
	vector<int> vcnt;

	for (int cnt = 1, i = 0; i < n; i++){
		if (a[i] == a[i + 1])
			cnt++;
		else{
			vi.push_back(a[i]);
			vcnt.push_back(cnt);
			cnt = 1;
		}
	}

	//for(auto x: vi) cout << x ;
	//cout << endl;
	//for(auto x: vcnt) cout << x ;
	//cout << endl;

	vector<vector<int>> vv;
	vector<int> tmp;
	vi.push_back(0);
	vcnt.push_back(0);
	for(int i=0;i<vi.size();i++){
		if(vcnt[i]==2){
			tmp.push_back(vi[i]);
		}else if (vcnt[i]>2){
			tmp.push_back(vi[i]);
			vv.push_back(tmp);
			tmp.resize(0);
			tmp.push_back(vi[i]);
		}else{
			if(tmp.size()!=0){
				vv.push_back(tmp);
				tmp.resize(0);
			}
		}
	}

	//for(auto v: vv){
	//	for(auto x : v) cout << x;
	//	cout << endl;
	//}

	int ans = 0;
	vector<int> map(n+1, -1);
	for(auto& v: vv){
		//cout << "/ ";
		for(int i=0, from=0, to=0;i<v.size();i++){
			to = i;
			if(map[v[i]]>=0){
				int t = map[v[i]];
				for(int j=from; j<=t;j++) map[v[j]] = -1;
				from = t + 1;
			}
			map[v[i]] = i;

			//cout << 2*(to-from+1) << " ";
			ans = max(ans, 2*(to-from+1));
		}

		for(int i=0, from=0, to=0;i<v.size();i++){
			map[v[i]] = -1;
		}
		//cout << "/" << endl;
	}
	cout << ans << endl;
	return 0;
}

