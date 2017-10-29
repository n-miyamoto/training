#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)

int N,K;

int main(void){
	cin >> N >> K;
	int ans = 1;
	for(int i=0;i<N;i++){
		int A,B;
		A=2*ans;
		B=ans+K;
		if(A>B){
			ans = B;
		}else{
			ans = A;
		}
	}

	cout << ans << endl;
	
	return 0;
}
