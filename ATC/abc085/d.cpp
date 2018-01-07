#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n,h;
int a[BUF];
int b[BUF];

int main(void){
	int amx=0;
	int bmx=0;	
	cin >> n >> h;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
		if(amx<a[i])amx = a[i];
	}

	sort(b+1,b+n+1);

	int ans = 0;
	int cnt = n;

	while(b[cnt]>amx){
//		cout << cnt << b[cnt];
		h-=b[cnt];
		ans++;

		if(h<=0){
			cout << ans << endl;
			return 0;
		}
		cnt--;
		if(cnt==0)break;
	}

	ans+=h/amx+1;
	if(h%amx==0)ans--;
	cout << ans << endl;

	return 0;
}
