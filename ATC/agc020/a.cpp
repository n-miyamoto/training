#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n,A,B;

int main(void){
	int ans;
	cin >> n >> A >> B;
	
	ans = (B-A)%2;

	if(ans == 0) cout << "Alice\n";
	else cout << "Borys\n";	
	return 0;
}
