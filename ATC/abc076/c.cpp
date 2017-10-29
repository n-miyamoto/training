#include <bits/stdc++.h>

using namespace std;
#define BUF (55)

char S[BUF],T[BUF];


int main(void){
	cin >> S;
	cin >> T;

	int n = strlen(S);
	int k = strlen(T);
	int index=-1;	
	//cout << n << k;


	//No '?'s
	int f=0;
	for(int i=0;i<n;i++){
		if(S[i]=='?') f=1;
	}	
	if(f==0) {
		cout << S << endl;
		return 0;
	}
	
	for(int i=n-k;i>=0;i--){
		int flag = 1;
		for(int j=0;j<k;j++){
			if(S[i+j] == '?' || S[i+j] == T[j] ){
		//		cout << i << j;
			}else{
				flag = 0;
			}
		}
		if(flag){
			 index = i;
			 break;
		}
	}
	
	if(index < 0){
		cout	<< "UNRESTORABLE" << endl;
		return 0;
	}
//	cout << index;
	for(int i=0;i<k;i++) S[index+i] = T[i];

	for(int i=0;i<n;i++)if(S[i]=='?') S[i] = 'a';

	cout << S << endl;


	

	return 0;
}
