#include <bits/stdc++.h>
using namespace std;
#define BUF (1000005)

int n;
int a[BUF];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	for(int i=1;i<=n;i++){
		if(a[i]%a[1]!=0){
			cout << -1 << endl;
			return 0;
		}
	}

	cout << 2*n << "\n";
	for(int i=1;i<=n;i++){
		cout << a[1] << " ";
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
