#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll n,m;

int main(void){
	cin >> n >> m;

	if(n==1){
		n=3;
	}
	if(m==1){
		m=3;
	}

	cout << (n-2)*(m-2) << endl;

	return 0;
}
