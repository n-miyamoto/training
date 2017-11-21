#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int n;
char s[3];
void input(void){
	cin >> s;
}

int main(void){
	input();
	if(s[0]==s[2]) cout << "Yes" << endl;
	else cout << "No" <<endl;
	return 0;
}
