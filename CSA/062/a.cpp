#include <bits/stdc++.h>
using namespace std;

#define BUF (11)
#define INF (1000000005)
#define ll long long 

int n;
int v[BUF];

int f[BUF*BUF];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> v[i];

	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			f[v[i]+v[j]]=1;
		}
	}

	int ans =0;
	for(int i=0;i<=BUF*BUF;i++) if(f[i]==1) ans++;

	cout << ans << endl;
	return 0;
}
