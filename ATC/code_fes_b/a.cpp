#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define BUF (1000)

int n;
char st[51];
void input(void){
	cin >> st;
}

int main(void){
	input();
	int l = strlen(st);
	st[l-8]=0;
	cout << st <<endl;	
}
