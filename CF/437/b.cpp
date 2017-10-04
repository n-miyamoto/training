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

	if(n==1){
		cout << 1 << " " << 1 << endl;
		cout << 1 << endl;
		return 0;
	}

	int M=2;
	int D[3];
	D[1]=1;
	D[2]=2;
	int N=(n-1)*2;	

	cout <<N << " "<<M << endl;
	cout << D[1] << " " << D[2] << endl;
	return 0;
}
