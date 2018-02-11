#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int a,b,c,d;
void input(void){
	cin >> a >> b >> c >> d ;
}

int main(void){
	input();

	int fa=0;
	int fb=0;
	int cnt = 0;
	for(int i=0;i<=100;i++){
		fa=0;fb=0;
		if(a<=i && i<b) fa = 1;
		if(c<=i && i<d) fb = 1;
		if(fa==1 && fb==1) cnt++;
	}
	

	cout << cnt << endl;
	return 0;
}
