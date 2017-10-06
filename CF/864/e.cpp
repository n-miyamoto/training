#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int n;
typedef struct{
	int t;
	int d;
	int p;
	int ix;
}A;

A a[101];
bool asc(A a1, A a2){
	return a1.d<a2.d;
} 

void input(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].t >> a[i].d >> a[i].p;
		a[i].ix = i;
	}
}

int main(void){
	input();
	sort(a+1,a+n+1,asc);

	int dp[101][2001];
	int p[101][2001];
	//for(int i=1;i<=n;i++) cout << a[i].ix;
	
	for(int i=1;i<=n;i++){
		for(int j=2001;j>=1;j--){
			dp[i][j] = dp[i-1][j];
			p[i][j]=0;
			//cout <<dp[i][j];
			if( j<a[i].d && j>=a[i].t ){
				if(dp[i-1][j-a[i].t]+a[i].p >dp[i][j]){
					dp[i][j] = dp[i-1][j-a[i].t]+a[i].p;
					p[i][j]=1;
				//	cout << dp[i][j];
				}
			}
		}
	}

	int max = 0;
	for(int i=0;i<2001;i++) if(max<dp[n][i]){
		max = dp[n][i];
	}
	cout << max << endl;
	return 0;
}
