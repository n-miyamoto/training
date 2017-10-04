#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int n;
void input(void){
	cin >> n;
}

int cp(int a, int b){
	int ans = 1;
	for(int i=2;i<=a;i++){
		if(a%i==0 && b%i==0)ans = 0;
	}
	return ans;
}

int main(void){
	input();

	int ap =0;
	int ad = 0;

	for(int i=1;i<=(n-1)/2;i++){
		if(cp(i,n-i)==1){
			ap = i;
			ad = n-i;
		}	
	}

	cout << ap << " " << ad <<endl;
	return 0;
}
