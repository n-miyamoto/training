#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

char ps[2];
int n;

char p[2*BUF];

void input(void){
	cin >> ps;
	cin >> n;
	for(int i=0;i<n;i++) scanf("%s",p+2*i);
}

int main(void){
	input();
//	cout << p;

	for(int i=0;i<2*n-1;i++){
		if(ps[0]==p[2*i] && ps[1]==p[2*i+1]){
			cout << "YES" <<endl;
			return 0;
		}
	}

	int flg0=0;
	int flg1=0;

	for(int i=0;i<n;i++){
		if(ps[1]==p[2*i])  flg1=1;
		if(ps[0]==p[2*i+1])flg0=1;
	}

	if(flg0==1 && flg1==1){
		cout << "YES" <<endl;
	}else{
		cout << "NO" <<endl;
	}
	return 0;
}
