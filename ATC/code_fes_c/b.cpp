#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)

int n;
int a[BUF];

int main(void){

	cin >> n;
	int even = 0;
	for(int i=1;i<=n;i++){
		int tmp = 0;
		cin >> tmp;
		if(tmp%2==0) even++;
	}

	cout << pow(3,n)-pow(2,even) << endl;



	return 0;
}
