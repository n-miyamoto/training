#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (105)
#define INF (1000*1000)
int n;
int a[BUF];

void input(void){
	cin >> n;
	for(int i=0;i<2*n;i++) cin >> a[i];
}

int main(void){
	input();
	int ans = INF;
	for(int i=0;i<2*n;i++){
		for(int j=0;j<2*n;j++){
			int temp[BUF];
			for(int k=0;k<2*n;k++){
				temp[k]=a[k]; //copy
			}
			temp[i]=0;
			temp[j]=0;
			sort(temp,temp+2*n);
			int ins=0;
			for(int k=0;k<n;k++){
				ins+=temp[2*k+1]-temp[2*k];
			}
			//cout << ins;
			if(ans>ins)ans = ins;
		}
	}

	cout << ans << endl;
	return 0;
}
