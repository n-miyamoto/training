#include <bits/stdc++.h>

using namespace std;

int main(void){
	string s, t;
	cin >> s >> t;

	transform(t.begin(), t.end(), t.begin(), ::tolower);

	int count = 0;
	for(const auto c : s){
		if(c==t[count]) count++;
		if(count==3) break;
	}

	if(count==3) cout << "Yes" << endl;
	else if(count == 2 && t[2]=='x') cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
