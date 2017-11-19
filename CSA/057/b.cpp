#include <bits/stdc++.h>


using namespace std;
#define BUF (400005)

int n ,k;
char s[BUF];
char c[BUF];

int main(void){
	cin >> n >> k;
	cin >> s;

	int f=1;
	for(int i=0;i<n;i++){
		if(s[i]=='1') f=0;
	}
	if(f==1){
		cout << n*k;
		return 0;
	}

	if(k==1) for(int i=0;i<n;i++){
		c[i] = s[i];
	}
	if(k==2) for(int i=0;i<n;i++){
		c[i] = s[i];
		c[i+n]=s[i];
	}

	if(n>2) for(int i=0;i<n;i++){
		c[i] = s[i];
		c[i+n]=s[i];
		c[i+2*n]=s[i];
	}
	int ans=0;
	int cnt=0;
	for(int i=0;i<strlen(c);i++){
		if(c[i]=='0') cnt++;
		else cnt=0;

		if(ans<cnt) ans=cnt;
	}
	cout << ans;
 


	
	return 0;
}
