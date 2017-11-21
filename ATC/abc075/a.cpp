#include <bits/stdc++.h>
//#include <stdio.h>
//#include <iostream>
//#include <algorithm>

using namespace std;
#define BUF (1000)

int a,b,c;

int main(void){
	cin >> a >> b >> c;
	int ans;
	if(a==b) ans = c;
	else if(a==c) ans = b;
	else ans = a;

	cout << ans << endl;

	return 0;
}
