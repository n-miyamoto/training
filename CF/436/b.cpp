#include <stdio.h>
#include <iostream>
#define BUF (0xFF)
using namespace std;

int n;
char s[BUF];

void input(void){
	cin >> n;
	cin >> s;
}


int main(void){
	input();

	int ans=0;

	int A[BUF];
	for(int i=0;i<BUF;i++) A[i]=0;

	for(int k=0;k<n;k++){
		if( s[k]>='a' && s[k]<='z'){
			//lower case
			A[s[k]] = 1;
		}
		
		if(k==n-1 || ( s[k]>='A' && s[k]<='Z' )){
			//upper case or last chr
			int sum =0;
			for(int i=0;i<BUF;i++){
				sum+=A[i];
			}
			if(sum>ans){
				ans = sum;
			}
			for(int i=0;i<BUF;i++) A[i]=0;
		}

	}


	cout << ans << endl;

	return 0;
}
