#include <bits/stdc++.h>

using namespace std;
#define BUF (2005)
#define ll long long 

int n;
int A[BUF];
int dp[BUF*BUF];

int main(void){
	cin >> n;
	int sum=0;
	for(int i=1;i<=n;i++){ 
		cin >> A[i];
		sum+=A[i];
	}

	if(sum%2==1) sum++;

	bitset<BUF*BUF> bs(1);
	
	for(int i=1;i<=n;i++) bs = bs|(bs<<A[i]);


	int cnt = sum/2;
	while(bs[cnt]==0)cnt++;
	cout << cnt << endl;
	return 0;
}
