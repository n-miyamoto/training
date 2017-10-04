#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int n;
char s[BUF];
void input(void){
	cin >> n;
	cin >> s;
}

int main(void){
	input();

	int cs=0;
	int cf=0;
	for(int i=0;i<n-1;i++){
		if(s[i]=='S' && s[i+1]=='F') cs++;
		if(s[i]=='F' && s[i+1]=='S') cf++;
	}
	if(cs>cf) cout << "YES" ;
	else cout << "NO";
	cout << endl;
	return 0;
}
