#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 
#define INF 400000005

int n;
int k;
int x[BUF];

int main(void){
	cin >> n >> k;
 	for (int i =1;i<=n;++i){
	       	cin >> x[i];
	}

	int ans = INF;

	for(int i=1;i<=n-k+1;i++){
		int r = x[i];
		int l = x[i+k-1];
		int mn = INF;
		if(r==l) mn = r;
		else if(r<0 && l>0){
			mn = min(-2*r+l, -r+2*l);
		}else if(r>=0 && l>=0){
		    mn = l;
		}else if(r<=0 && l<=0){
			mn = -r;
		}
		ans = min(ans,mn);
	}


	cout << ans << endl;

	return 0;
}
