#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)

int n;
char a[BUF],b[BUF];
int main(void){

	cin >> a ;
	cin >> b ;

	int ans = 1;
	for(int i=0;i<3;i++){
		if(a[i]!=b[2-i]) ans = 0;
	}
	
	if(ans==1) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
