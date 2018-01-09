#include <bits/stdc++.h>

using namespace std;
#define BUF (8005)
#define ll long long 

char s[BUF];
int x,y;
vector<int> A[2];

bool dp[BUF][2*BUF];

int main(void){
	cin >> s;
	cin >> x >> y;
	int axis=1;
	int cnt=0;
	int n=strlen(s);
	s[n]='T';
	for(int i=0; i<=n; i++){
		if(s[i]=='T'){
			axis=(axis+1)%2;
			if(cnt!=0)A[axis].push_back(cnt);
			cnt = 0;
		}else cnt++;
	}
	

	//dp x
	memset(dp,0,2*BUF*BUF);
	dp[0][0+BUF]=true;
	cnt = 0;
	for(auto z:A[0]){
		cnt++;
		for(int i=0;i<2*BUF;i++){
			if(dp[cnt-1][i]){
				if(cnt==1&&s[0]=='F'){
					dp[cnt][i+z]=true;
				}else{
					dp[cnt][i+z]=true;
					dp[cnt][i-z]=true;
				}
			}
		}
	}

	//dp y
	bool tmp = dp[cnt][x+BUF];

	memset(dp,0,2*BUF*BUF);
	dp[0][0+BUF]=true;
	cnt = 0;
	for(auto z:A[1]){
		cnt++;
		for(int i=0;i<2*BUF;i++){
			if(dp[cnt-1][i]){
					dp[cnt][i+z]=true;
					dp[cnt][i-z]=true;
			}
		}	
	}

	if(tmp && dp[cnt][y+BUF]) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
