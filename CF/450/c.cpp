#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


int n;
char s[BUF];
int p[BUF];
int tp[BUF];
int k[BUF];
int mx1;
int i1;
int mx2;
int i2;

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){ 
		cin >> p[i];
		if(mx1<p[i]){
			i2 = i1;
			i1 = i;
			mx2=mx1;
			mx1=p[i];
			tp[i]=1;//record.
		}
		else if(mx2<p[i]){
			mx2=p[i];
			i2=i;
			k[i1]++;
			tp[i]=2;
		}
	}

	if(n<3){
		cout << 1;return 0;
	}

	for(int i=1;i<=n;i++){
		if(tp[i]==1)k[i]--;
		//cout << k[i];
	}

	int ans;
	mx1=-INF;
	for(int i=1;i<=n;i++){
		if(mx1<k[i]){
			mx1=k[i];
			ans = p[i];	
		}else if(mx1==k[i]){
			if(ans>p[i]) ans = p[i];
		}
	}

	//cout << mx1;
	if(mx1<0) cout << 1;
	else cout << ans;

	return 0;
}
