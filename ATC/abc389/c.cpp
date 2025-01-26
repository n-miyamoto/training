#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n;
	cin >> n;

	vector<ll> psum(1, 0);

	
	ll start = 0;
	for(int i=0; i<n;i++){
		int q, l=0, k=0;
		ll tmp=0;
		cin >> q;
		

		switch(q){
			case 1:
				cin >> l;
				tmp = psum.back() + l;
				psum.push_back(tmp);
				break;

			case 2:
				start++;
				break;

			case 3:
				cin >> k;
				cout << psum[k-1 + start] - psum[start] << endl;
				break;
		}
	}

	return 0;
}
