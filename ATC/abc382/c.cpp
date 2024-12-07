#include <bits/stdc++.h>

using namespace std;
using ll=long long;
constexpr int MAX = 200005;

int main(void){
	int n, m;
	cin >> n >> m;

	vector<int> v, vi;
	for(int i=1, mn = MAX;i<=n;i++){
		int tmp;
		cin >> tmp;
		if(mn>tmp){
			mn = tmp;
			v.push_back(tmp);
			vi.push_back(i);
			//cout << tmp << i << endl;
		}
	}

	for(int i=0;i<m;i++){
		int b;
		cin >> b;

		auto it = lower_bound(v.begin(), v.end(), b, greater<int>());
 	    if (it != v.end()) {
			int index = distance(v.begin(), it);
        	cout << vi[index] << endl;
    	} else {
    	    cout << -1 << endl;
    	}
	}
	
	return 0;
}
