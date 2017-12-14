#include <bits/stdc++.h>
using namespace std;

#define BUF (20005)
#define INF (1000000005)
#define ll long long 

int n;
int s[BUF];

int main(void){
	cin >> n;
	for(int i=0;i<2*n;i++) cin >> s[i];

	int ans = 0;
	int bit = 0;
	int cnt=0;
	for(int i=0;i<2*n;i++){
		if(bit!=s[i]) cnt++;
	    bit++;
		bit%=2;
	}
	ans = cnt;
	cnt=0;
	bit = 1;
	for(int i=0;i<2*n;i++){
		if(bit!=s[i]) cnt++;
	    bit++;
		bit%=2;
	}
	ans=min(ans,cnt);

	cout << ans/2 ;
	

	return 0;
}
