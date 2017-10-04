#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int n,k;
unsigned int A[BUF];
unsigned int B[BUF];
unsigned int M[BUF];

void input(void){
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> A[i] >> B[i];
}

unsigned int max(unsigned int a, unsigned int b){
	if(a>b) return a;
	else return b;
}

unsigned int dfs(int l){
	if(l==0) return 0;

	if((k>>(l-1))%2==0){
		return dfs(l-1);
	}else{
		cout << "dfs" << l << endl;
		unsigned int c0 = 0;
		for(int j=1;j<=n;j++) if(M[j]<l) c0+=B[j];
		unsigned int ks = 0;;
		for(int j=1;j<=n;j++) if(M[j]==l) if(A[j]<=k) ks += B[j];
		unsigned int c1 = dfs(l-1) + ks;
		cout << c0 << " " << c1 << ks <<endl;
		return max(c0,c1);
	}
}

int main(void){
	input();

	for(int i=1;i<=n;i++){
		for(int j=30;j>0;j--){
			if((A[i]>>j)%2==1) {
				M[i] = j+1;
				break;
			}
		}
		cout << M[i] << endl;
	}

	cout << dfs(30) << endl;
	return 0;

}
