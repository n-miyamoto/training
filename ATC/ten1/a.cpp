#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

char s[8];
void input(void){
	cin >> s;
}

int main(void){
	input();

	int c=0;
	for(int i=0;i<6;i++)if(s[i]=='1')c++;
	cout << c << endl;
	return 0;
}
