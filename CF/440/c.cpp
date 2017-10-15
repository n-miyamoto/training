#include <bits/stdc++.h>
using namespace std;
#define BUF (100005)

int n;
long long  q[BUF]; 

int cn(long long a){
	int ans = 0;
	if(a<4) return -1;
	if(a==5 || a==7 || a==11 ) return -1;	


	if(a%4==0) return a/4;
	if(a%4==2) return a/4;
	if(a%4==1) return a/4-1;
	if(a%4==3) return a/4-1;
}

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> q[i];


	for(int i=1;i<=n;i++) cout << cn(q[i]) << "\n";
	return 0;
}
