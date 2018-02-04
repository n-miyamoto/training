#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

long long  x,y;

//最大公約数   ユークリッド互除法
long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

//最小公倍数
long long lcm(long long a,long long b){
    long long g = gcd(a,b);
    return a/g*b;
}

int main(void){
	cin >> x>>y;
	int anw=x;

	long long ans = lcm(x,y)-x;
	if(ans==0) ans = -1;	
	if(ans>1000000000000000000) ans = -1;
	cout << ans << endl;
	return 0;
}
