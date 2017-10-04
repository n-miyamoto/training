#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int n;
int m;
int k[BUF];
int f[BUF];

void input(void){
	cin >> n >> m;
	for(int i=0;i<m;i++)cin >> k[i] >> f[i];
}

int main(void){
	input();
	int ans=-1;
	int cnt=0;
	for(int j=1;j<=100;j++){
		int flg=1;		
		for(int l=0;l<m;l++){
			if((k[l]-1)/j+1!=f[l]) {
				flg=0;
				//cout << j;
				break;
			}
		}
		if(flg){
			if(ans==-1) ans = (n-1)/j+1;
			else if(ans != (n-1)/j+1){
				cout << -1 <<endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
	

	return 0;
}
