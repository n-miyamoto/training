#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (100005)

int n,k;
int a[4][BUF];
int ans[4];
void input(void){
	cin >> n >> k;
	for(int i=0;i<n;i++)for(int j=0;j<k;j++){
		cin >> a[j][i];
	}
}

int main(void){
	input();

	for(int i=0;i<k;i++) for(int j=0;j<n;j++){
		ans[i]+=a[i][j];		
	}	

	int flg=1;
	for(int i=0;i<k;i++){
		if( ans[i] < (n/2) )flg=0;
	}

	if(flg==1) cout << "YES" <<endl;
	else cout << "NO" << endl;
	return 0;
}
