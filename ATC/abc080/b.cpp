#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;

int main(void){
	cin >> n;
	int n_=n;
	int ans = 0;
	while(n>10){
		int a=n%10;
		ans+=a;
		n/=10;
	}

	ans+=n;

//	cout << ans;
	if(n_%ans==0){
		cout << "Yes";
	}else cout << "No";

	return 0;
}
