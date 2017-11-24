#include <bits/stdc++.h>
using namespace std;
#define BUF (1000)
#define ll long long 


int n;
int bn[BUF];

int main(void){
	cin >> n;

	int i=1;
	while(1){
		bn[i]=(pow(2,i)-1)*pow(2,i-1);
		if(bn[i]>n) break;
		i++;
	}

	i--;

	//cout <<  bn[i] << endl;
	
	while(i>0){
		if(n%bn[i]==0) break;
		i--;
	}
	cout <<  bn[i] << endl;
	return 0;
}
