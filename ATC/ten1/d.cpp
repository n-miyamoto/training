#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (100005)

int N,K;
int A[BUF],B[BUF];

void input(void){
	cin >> N >> K;
	for(int i=1;i<=N;i++) cin >> A[i] >> B[i];
}



int dfs(int b){
	if(b==0) return 0;

	if(K>>b%2==0) return dfs(b-1);
	else{

	}
}

int C[BUF];

int cost(int b){
	int tmp=0;
	for(int i=1;i<=N;i++){
		if(C[i]<b) tmp+=B[i]; 
	}
	return tmp;
}

int main(void){
	input();

	for(int i=1;i<=N;i++){
		for(int j=0;j<=30;j++){
			if(A[i]>>j==1)C[i] = j+1; 
		}
		cout << C[i];
	}

	for(int i=0;i<=30;i++){


	}
	return 0;
}
