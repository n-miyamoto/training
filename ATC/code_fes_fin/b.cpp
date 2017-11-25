#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

char s[BUF];
int n;
int cnt[3];

int main(void){
	cin >> s;

	for(int i=0;i<strlen(s);i++) cnt[s[i]-'a']++;

	int f=1;
	
	if(abs(cnt[2]-cnt[1])>1) f=0;
	if(abs(cnt[1]-cnt[0])>1) f=0;
	if(abs(cnt[0]-cnt[2])>1) f=0;

	if(f) cout << "YES";
	else cout << "NO";	
	return 0;
}
