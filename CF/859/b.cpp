#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int n;
void input(void){
	cin >> n;
}

int main(void){
	input();

	int cnt = 0;
	for(int i=1;i<=1000;i++){
		if( n>(i-1)*(i-1) && n<=i*i) cnt = i;
	}

	int mod=1;
	while(1){
		if( cnt*(mod-1) < n && n <= cnt*mod )break;
		mod++;
	}
	//cout << cnt << mod;
	cout << 2*cnt+2*mod<< endl;
	return 0;
}
