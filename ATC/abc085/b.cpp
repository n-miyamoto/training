#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


int a[BUF];
int d[BUF];
int n;


int main(void){
	int cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++){
		if(d[a[i]]==0){
			cnt++;
			d[a[i]]++;
		}
	}

	cout << cnt << endl;

	return 0;
}
