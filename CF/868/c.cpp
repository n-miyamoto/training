#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define BUF (100005)

int n,k;
int ans[4];
int a[0b10000];

void input(void){
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int key=0;
		for(int j=0;j<k;j++){
			int tmp;
			cin >> tmp ;
			if(tmp) key+=1<<j;
		}
		a[key]=1;
	}
}

int main(void){
	memset(a,0,0b10000);
	input();

	if(a[0]==1){cout << "YES" << endl; return 0;}
	for(int i=0; i<0b10000 ;i++ ){
		for(int j=0; j<0b10000 ;j++ ){
			if(a[i] && a[j] && i!=j && (i & j) == 0  ) {
				 cout << "YES" <<endl;	
				 return 0; 
			}
		}
	}

	cout << "NO" << endl;
	return 0;
}
