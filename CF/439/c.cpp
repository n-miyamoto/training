#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define BUF (1000)
#define MOD (998244353)
typedef long long ll;

int a,b,c;
void input(void){
	cin >> a >> b >> c;
}

/*
ll uf(int a){
	if(a==1) return 1;
	ll ans = a*uf(a-1)%MOD;
	return ans; 
}

ll clc(int a , int b){
	int big = b;
	int small = a;
	if(a>b){
		big=a;
		small=b;
	}

	ll ans=1;
	ll sum = 1;
	for(int i=1;i<=small;i++){
		ans %= MOD;
		ans = ans*(small-i+1)*(big-i+1) / i / i;
		sum+=ans * uf(i) % MOD;
		sum%=MOD;
	}
	return sum;
}
*/

ll dp[5005][5005];
int main(void){
	input();
	
	for(int i=0;i<5005*5005;i++) dp[i/5005][i%5005] = 1;

	for(int i=1;i<=5000;i++){
		for(int j=1;j<=5000;j++){
			dp[i][j] = (dp[i-1][j]+j*dp[i-1][j-1])%MOD;		
		}
	}


	ll ans=(dp[a][b]*dp[b][c]%MOD * dp[a][c])%MOD;
	cout << ans << endl;
	return 0;
}
