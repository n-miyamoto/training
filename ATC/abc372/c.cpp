#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	set<int> st;
	for(int i=0;i<n-2;i++){
		if(s[i]=='A' && s[i+1] == 'B' && s[i+2]=='C') st.insert(i);
	}

	for(int i=0;i<q;i++){
		int x;
		char c;
		cin >> x >> c;
		x--;
		s[x] = c;

		auto b = st.upper_bound(x);

		if(b!=st.begin()){
			auto prv = prev(b);
			if(*prv+2 >= x ) st.erase(prv);
		}

		for(int j=max(0, x-2);j<=min(x, n-3);j++){
			if(s[j]=='A' && s[j+1] == 'B' && s[j+2]=='C') st.insert(j);
		}
		cout << st.size() << endl;
	}
	
	return 0;
}
