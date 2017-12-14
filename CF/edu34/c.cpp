#include <bits/stdc++.h>
using namespace std;

#define BUF (5005)
#define INF (1000000005)
#define ll long long 


int n;
int a[BUF];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];

	if(n==1) {
		cout << 1;
		return 0;
	}

	sort(a+1,a+1+n);

	int prv=a[1];
	int cnt=1;
	int ans=0;
	for(int i=2;i<=n;i++){
		if(a[i]==prv) cnt++;
		else cnt=1;
		if(cnt>ans)ans=cnt;
		prv = a[i];
	}

	cout << ans;

	return 0;
}
