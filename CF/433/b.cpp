#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

long long  n,k;
void input(void){
	cin >> n >> k;
}

int main(void){
	input();

	//min
	long long  min = 1;
	if(k==0 || k==n) min = 0;

	//max
	long long max = n-k;
	if(k<=n/3) max = 2*k;
	
	cout << min << " " << max << endl;

	return 0;
}
