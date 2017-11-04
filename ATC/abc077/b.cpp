#include <bits/stdc++.h>

using namespace std;
#define BUF (10005)

long long  n;

int main(void){
	cin >> n;
	long long  i=100005;
	while(1){
		if(n>=i*i){ 
			break;
		}
		i--;
	}
	cout << i*i << endl;
	return 0;
}
