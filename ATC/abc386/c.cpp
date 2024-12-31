#include <bits/stdc++.h>

using namespace std;
using ll=long long;

bool solve1(string a, string b){
	int l = b.length();

	for(int i=0, cnt = 0; i<l;i++){
		if(a[i]!=b[i]) cnt++;
		if(cnt>1) return false;
	}

	return true;
}

bool solve2(string a, string b){
	int l = b.length();

	for(int i=0, cnt = 0; i<l;i++){
		if(a[i+cnt]!=b[i]) cnt++;
		if(cnt>1) return false;
	}

	return true;
}

int main(void){
	int k;
	string s,t;
	cin >> k >> s >> t;

	int sl = s.length();
	int tl = t.length();

	int d = sl-tl;

	if(d== 0 && solve1(s, t)) cout << "Yes" << endl;
	else if(d== 1 && solve2(s, t)) cout << "Yes" << endl;
	else if(d==-1 && solve2(t, s)) cout << "Yes" << endl;
	else  cout << "No" << endl;
	
	return 0;
}
