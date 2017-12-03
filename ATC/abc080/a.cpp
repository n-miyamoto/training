#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n,a,b;


int main(void){
	cin >> n >> a >> b;
	cout << min(b,n*a);

	return 0;
}
