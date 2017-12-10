#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

int n,k;
int v[BUF];
int cnt=0;

bool asc( int left, int right ) {
    return left  > right;
}



int main(void){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		int tmp;
		cin >> tmp;
		if(v[tmp]==0)cnt++;
		v[tmp]++;
	}

	sort(v+1,v+n+1,asc);
	//cout << cnt;	
	//for(int i=1;i<=n;i++) cout << v[i];

	int ans = 0;
	for(int i=k+1;i<=n;i++){
		if(v[i]==0) break;
		ans += v[i];
	}

	cout << ans << endl;

	return 0;
}
