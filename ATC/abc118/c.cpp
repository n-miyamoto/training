#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;

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
	long long  ans ;
	cin >> n;
	for (int i=1;i<=n;i++){
		long long  temp ;
		cin >> temp;
		if(i==1){
			ans = temp;
			continue;
		}
		ans = gcd(temp ,ans);
	}
	
	cout << ans << endl;

	return 0;
}
