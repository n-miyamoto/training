#include <bits/stdc++.h>
using namespace std;
#define BUF (105)

char s[BUF];

int main(void){
	cin >> s;
	int n=strlen(s);
	int qs[BUF];
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]=='Q')cnt++;
		qs[i]=cnt;
	}
	int ans = 0;
	for(int i=1;i<n-1;i++){
		if(s[i]=='A')ans+=qs[i]*(qs[n-1]-qs[i]);
	}
	cout << ans << endl;
	return 0;
}
