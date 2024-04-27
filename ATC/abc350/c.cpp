#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;

int main(void){
	cin >> n;
	vector<int> a(n+1);
	vector<int> v(n+1);

	for(int i=1;i<=n;i++){
		cin >> a[i];
		v[a[i]] = i;
	}

	vector<pair<int, int>> ans;

	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			int tmp_indx = v[i];
			ans.push_back(make_pair(i, tmp_indx));
			
			a[tmp_indx] = a[i];
			v[a[i]] = tmp_indx;
			a[i] = i;
			v[i] = i;
		}
	}

	cout << ans.size() << endl;
	for(const auto x : ans ){
		cout << x.first << " " << x.second << endl;
	}
	
	return 0;
}
