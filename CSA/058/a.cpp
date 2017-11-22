#include <bits/stdc++.h>
using namespace std;
#define BUF (1005)
#define ll long long 

int n,k;
int a[BUF];

int main(void){
	cin >> n >> k;
	for(int i= 0;i<n;i++) cin >> a[i];
	sort(a,a+n);

	int cnt = 0;
	for(int i=0;i<n;i++){
		int f=1;
		for(int j=0;j<n;j++)if(i!=j) if(abs(a[i]-a[j])<=k) f=0;
		if(f==1)cnt++;
	}

	cout << cnt << endl;

	return 0;
}
