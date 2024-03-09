#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	string s;
	int q;
	cin >> n >> s >> q;

	char replace_to[26];
	for (char c = 'a'; c<='z'; c++ ){
		replace_to[c - 'a'] = c;
	}

	// Update Replacement Table
	for (int i=0;i<q;i++){
		char c, d;
		cin >> c >> d;

		for (char t = 'a'; t<='z'; t++ ){
			if(replace_to[t - 'a'] == c) replace_to[t - 'a'] = d;
		}
	}

	// Replace
	for (auto &c : s){
		c = replace_to[c - 'a'];
	}

	cout << s << endl;

	return 0;
}
