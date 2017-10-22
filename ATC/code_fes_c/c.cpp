#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)

char s[BUF];
char str[BUF];
int main(void){
	cin >> s;
	
	int cnt = 0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]!='x'){
			str[cnt] = s[i];
			cnt++;
		}
	}

	for(int i=0;i<strlen(str);i++){
		if(str[i]!=str[strlen(str)-i-1]){
			cout << -1 << endl;
			return 0;
		}
	}

	int lo = 0;
	int hi = strlen(s)-1;
	int ans=0;
	while(1){
		if(lo>=hi) break;
		if(s[lo]!=s[hi]){
			if(s[lo]=='x'){
				ans++;
				lo++;
			}else{
				ans++;
				hi--;
			}
		}else{
			lo++;
			hi--;
		}
	}
	cout << ans << endl;
	return 0;
}
