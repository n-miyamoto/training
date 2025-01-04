#include <bits/stdc++.h>

using namespace std;
using ll=unsigned long long;

char toggleCase(char c) {
    if (islower(c)) return std::toupper(c); 
	return std::tolower(c);
}

int main(void){
	string s;
	cin >> s;

	ll q;
	cin >> q;
	for(int i=0;i<q;i++){
		ll k;
		cin >> k;
		k--;
		ll M=k/s.length();
		ll m=k%s.length();

		if(__builtin_popcountll(M)%2)
			cout << toggleCase(s[m]);
		else
			cout << s[m];
		cout << " ";
	}
	cout << endl;
	
	return 0;
}
