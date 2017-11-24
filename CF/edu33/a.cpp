#include <bits/stdc++.h>
using namespace std;
#define BUF (1000)
#define ll long long 


int n;
int w[BUF];

int main(void){
	cin >> n;
	for(int i=0;i<n;i++)cin >> w[i];
	int f[BUF];
	f[0]=3;

	for(int i=0;i<n;i++){
		//cout << w[i] << f[i];
		if(w[i]==f[i]){
			cout << "NO" << endl;
			return 0;
		}
		int a;
		if(w[i]==1&&f[i]==2) a=3;
		if(w[i]==1&&f[i]==3) a=2;
		if(w[i]==2&&f[i]==1) a=3;
		if(w[i]==2&&f[i]==3) a=1;
		if(w[i]==3&&f[i]==2) a=1;
		if(w[i]==3&&f[i]==1) a=2;
		f[i+1]=a;
	}

	cout << "YES" << endl;


	return 0;
}
