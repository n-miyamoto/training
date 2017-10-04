#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (100005)

int n,x;
int a[BUF];
void input(void){
	cin >> n >> x;
}

int main(void){
	input();
	if(x==0 && n==2) {
		cout << "NO\n";
		return 0;
	}


	cout << "YES\n";

	for(int i = 1;i<n;i++)a[i]=i;
	a[n-1] += 1<<19;

	a[n]=0;
	for(int i=1;i<n;i++) a[n] = a[n]^a[i];
	a[n] = a[n]^x;

	if(n>=3){
		a[n-1] = a[n-1] ^ (1<<18);
		a[n-2] = a[n-2] ^ (1<<18);
	}

	for(int i=1;i<=n;i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}
