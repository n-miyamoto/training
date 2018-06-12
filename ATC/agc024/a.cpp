#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll a,b,c,k;

int main(void){
	cin >> a >> b >> c >> k;

	if(k%2==0){
		cout << a-b << endl;
	}else{
		cout << b-a << endl;
	}

	
	return 0;
}
