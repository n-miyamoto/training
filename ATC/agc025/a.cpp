#include <bits/stdc++.h>

using namespace std;
#define BUF (10)
#define ll long long 

int n;
char s[BUF];

int main(void){
	cin >> s;
	n = strlen(s);

	int cnt = 0;
	int ans = 0;
	for(int i=0;i<n;++i){
		if(s[i]=='0') cnt++;
		ans += s[i] - '0';
	}

	if(s[0]=='1' && n-cnt==1){
		cout << 10 << endl;
		return 0;
	}

	cout << ans << endl;

	return 0;
}
