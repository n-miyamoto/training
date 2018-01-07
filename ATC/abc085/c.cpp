#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 
#define A (10000)
#define B (5000)
#define C (1000)
int n;
int y;

int main(void){
	cin >> n >> y;

	//y= iA+jB+kC;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			int k=n-i-j;
			if(k<0 || k>n) continue;
			if(y==i*A+j*B+k*C){
				cout << i << " " << j << " " << k << endl;
				return 0; 
			}
		}
	}

	cout << "-1 -1 -1" << endl;

	return 0;
}
