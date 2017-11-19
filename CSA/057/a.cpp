#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>


using namespace std;
#define BUF (1000)

int n;
char s[BUF];
int t[27];

int main(void){
	cin >> s;
	for(int i=1;i<=26;i++) cin >> t[i];
	int ans = 0;
	for(int i=0;i<=strlen(s);i++){
		ans+= t[s[i]-0x60];
	}

	cout << ans << endl;


	
	return 0;
}
