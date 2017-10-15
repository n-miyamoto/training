#include <bits/stdc++.h>
using namespace std;
#define INF (1000000001)
#define BUF (100005)

int n,k;
int a[BUF];

int main(void){
	cin >> n >>k;
	
	for(int i=1;i<=n;i++) cin >> a[i];

	if(k>2){
		sort(a+1,a+1+n);
		cout << a[n] << endl;
		return 0;
	}

	if(k==1){
		sort(a+1,a+1+n);
		cout << a[1] << endl;
		return 0;	
	}

	if(k==2){
		if(a[1]>a[n]) cout << a[1] << endl;
		else cout << a[n] << endl;
		return 0;
	}

	return 0;
}
