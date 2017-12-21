#include <bits/stdc++.h>
using namespace std;

#define BUF (200005)
#define INF (1000000005)
#define ll long long 

int n;
int v[BUF];
int p[BUF];
int p2[BUF];
int ans[BUF];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> v[i];

	int mx = 0;
	int mxi= 0;
	int mx2 =0;
	int mxi2=0;
	int total = 0;
	for(int i=1;i<=n;i++){
		if(v[i]>mx){
			mx2=mx;
			mxi2=mxi;
			mx=v[i];
			mxi=i;
			p[i] = 1;
			total++;
		}else if(v[i]>mx2){
			p2[mxi]++;
			mx2=v[i];
			mxi2=i;
		}
	}

	int A = 0;
	for(int i=1;i<=n;i++){
		ans[i] = total - p[i] + p2[i];
		if(A<ans[i]) A=ans[i];
	}
	
	cout << A << endl;
	return 0;
}
