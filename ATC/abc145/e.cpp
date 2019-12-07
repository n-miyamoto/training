#include <bits/stdc++.h>

using namespace std;
#define BUF (3005)
#define ll long long 

int N,T;
vector<int> A,B;
int dp1[BUF][BUF];
int dp2[BUF][BUF];

void dump_dp(){
	cout << "--- dp1 ---" << endl;
	for(int n=0;n<N;n++){
		for(int t=0;t<=T;t++){
			cout << dp1[t][n] << " ";
		}
		cout << endl;
	}

	cout << "--- dp2 ---" << endl;
	for(int n=0;n<N;n++){
		for(int t=0;t<=T;t++){
			cout << dp2[t][n] << " ";
		}
		cout << endl;
	}
}

int main(void){
	// in
	cin >> N >> T;
	for(int i=1;i<=N;i++){
		int a,b;
		cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
	}

	//for(int n=0;n<=N;n++){ dp1[0][n] = 0; }
	for(int t=0;t<=T;t++){ 
		if(A[0]<=t){
			dp1[t][0] = B[0];
		}
	}
	for(int t=1;t<=T;t++){
		for(int n=1;n<N;n++){
			if(t-A[n] < 0) dp1[t][n] = dp1[t][n-1];
			else dp1[t][n] = max(dp1[t][n-1], B[n] + dp1[t-A[n]][n-1]);
		}
	}

	//for(int n=0;n<=N;n++){ dp2[0][n] = 0; }
	for(int t=1;t<=T;t++){ 
		dp2[t][0] = B[0];
	}
	
	for(int t=1;t<=T;t++){
		for(int n=1;n<N;n++){
			dp2[t][n] = max(dp2[t][n-1], dp1[t-1][n-1] + B[n]);
			if(t-A[n] >= 0) {
				dp2[t][n] = max(dp2[t][n], B[n] + dp2[t-A[n]][n-1]);
			}
		}
	}

	cout << dp2[T][N-1]<<endl;

	//dump_dp();

	return 0;
}
