#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n,c;


int a[32][BUF];
int cnt[BUF];

int main(void){
	cin >> n >> c;
	for(int i=1;i<=n;i++){
		int s,t,ch;
		cin >> s >> t >> ch;
		if(a[ch][s] == 0){
			a[ch][s] = 5;
		}else{
			a[ch][s]=0;
		}
		if(a[ch][t] == 0){
			a[ch][t] = -1;
		}else{
			a[ch][t]=0;
		}
	}

	for(int ch = 1;ch<=c;ch++){
		for(int i=1; i<BUF;i++){
			if(a[ch][i]==5){
				if(a[ch][i-1]==-1){
					a[ch][i]=0;
					a[ch][i-1]=0;
				}else{
					a[ch][i]=0;
					a[ch][i-1]=1;
				}
			}
		}
	}

	int tv=0;
	int ans = 0;
	for (int i = 0; i < BUF ; i++)
	{
		for (int ch = 1; ch <= c; ch++)
		{
			tv+=a[ch][i];
		}
		ans = max(ans,tv);
	}

	cout << ans << endl;	
	return 0;
}
