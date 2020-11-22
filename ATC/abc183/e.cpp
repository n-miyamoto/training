#include <bits/stdc++.h>

using namespace std;
#define BUF (2005)
#define ll long long 
#define MOD (1000000007)

int H,W;
char B[BUF][BUF];
ll  dp[BUF][BUF];
ll  dp_r[BUF][BUF];
ll  dp_d[BUF][BUF];
ll  dp_rd[BUF][BUF];

template<typename T>
void show(T* ptr){
	for(int i=0; i<H;i++){
		for(int j=0; j<W;j++){
			cout << ptr[BUF * i + j];
			cout << " ";
		}
		cout << "\n";
	}
}

int main(void){
	cin >> H >> W;
	for(int i=0; i<H;i++){
		char* tmp = &B[i][0];
		cin >> tmp;
	}
	for(int i=H-1; i>=0 ;i--){
		for(int j=W-1; j>=0;j--){

			if (i == H-1 && j== W-1){
				dp[i][j] = 1;
				dp_r[i][j] = 1;
				dp_d[i][j] = 1;
				dp_rd[i][j] = 1;
			}else if(B[i][j] != '#'){
				dp[i][j] = dp_r[i][j+1] + dp_d[i+1][j] + dp_rd[i+1][j+1];
				dp[i][j]%=MOD;
				dp_r[i][j] = dp[i][j] + dp_r[i][j+1];
				dp_r[i][j]%=MOD;
				dp_d[i][j] = dp[i][j] + dp_d[i+1][j];
				dp_d[i][j]%=MOD;
				dp_rd[i][j] = dp[i][j] + dp_rd[i+1][j+1];
				dp_rd[i][j]%=MOD;
			}
		}
	}

	cout << dp[0][0] << endl;
	
	//show<char>((char*)B);
	//show<ll>((ll*)dp);
	//show<ll>((ll*)dp_r);
	//show<ll>((ll*)dp_d);
	
	return 0;
}
