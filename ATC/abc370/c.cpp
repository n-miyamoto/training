#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	string s, t;
	cin >> s >> t;
	
	int n=0;
	for(int i=0;i<s.size(); i++) if(s[i]!=t[i]) n++;
	cout << n << endl;

	for(int i=0;i<s.size(); i++){
		if(s[i]>t[i]) {
			s[i] = t[i];
			cout << s << endl;
		};
	}

	for(int i=s.size()-1;i>=0; i--){
		if(s[i]<t[i]) {
			s[i] = t[i];
			cout << s << endl;
		};
	}

	return 0;
}
