#include <bits/stdc++.h>
using namespace std;

#define BUF (107)
#define INF (1000000005)
#define ll long long 


int n,d;
char s[BUF];
int v[BUF];
int dif[BUF];


int main(void){
	cin >> n >> d;

	for(int i=0;i<n;i++) cin >> v[i];
	for(int i=1;i<n;i++) {
		dif[i] = v[i]-v[i-1];
	}

	sort(v,v+n);

	int stt=0;
	int end=n-1;
	int ans = 0;
	while(v[end]-v[stt]>d){
		if(end<=stt){
			cout << n-1 << endl;
			return 0;
		}
		ans++;
		int tmp = 0;
		while(dif[stt+1+tmp] == dif[end-tmp]){
			if(stt+1+tmp>=end-tmp){
				tmp--;
				break;
			}
			tmp++;
		}
		if(dif[stt+1+tmp]>dif[end-tmp]) stt++;
		else end--;
	}

	cout << ans << endl;
	return 0;
}
