#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

long long n,m;
void input(void){
	cin >> m >> n;
}

int main(void){
	input();
	long long ans=1;
	
	if(m==0){

	}
	for(long long i=n;i>m;i--){
		ans= ans*(i%10);
		ans=ans%10;
		//cout <<ans;
		if(ans==0) break;
	}

	cout << ans << endl;

	return 0;
}
