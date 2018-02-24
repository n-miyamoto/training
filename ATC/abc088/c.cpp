#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;
int c[4][4];

int check(int r1,int r2,int l1, int l2){
	if(c[r1][l1]+c[r2][l2]==c[r1][l2]+c[r2][l1]) return 1;
	
	return 0;
}

int f=0;
int main(void){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin >> c[i][j];
		}
	}

	if(check(1,2,1,2)==0) f=1;
	if(check(1,2,1,3)==0) f=1;
	if(check(1,2,2,3)==0) f=1;
	if(check(1,3,1,2)==0) f=1;
	if(check(1,3,1,3)==0) f=1;
	if(check(1,3,2,3)==0) f=1;
	if(check(1,2,1,2)==0) f=1;
	if(check(1,2,1,3)==0) f=1;
	if(check(1,2,2,3)==0) f=1;

	if(f==1){
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	return 0;
}
