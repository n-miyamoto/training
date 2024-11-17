#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int q;
	cin >> q;

	ll count = 0;
	vector<ll> plants;
	ll harvested = 0;
	for(int i=0;i<q;i++){
		int qi;
		cin >> qi;
		switch (qi)
		{
		case 1:
			plants.push_back(count);
			break;
		case 2:
			ll t;
			cin >> t;
			count += t;
			break;
		case 3:
			ll h;
			cin >> h;
			auto it = upper_bound(plants.begin(), plants.end(),count-h);
			auto index = distance(plants.begin(), it);
			if(index - harvested >= 0){
				cout << index - harvested << endl;
				harvested = index;
			}else cout << 0 << endl;

			break;
		}
	}
	
	return 0;
}
