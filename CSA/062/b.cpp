#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 

int n;
int s[BUF];

int b[BUF];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		if(s[i-1]<s[i]){
			b[i-1]=0;
		}else b[i-1]=1;
	}

	for(int i=1;i<=n;i++){
		cin >> s[i];
	}
	if(s[n-1]==1) b[n]=0;
	else b[n] = 1;

	for(int i=1;i<=n;i++) cout << b[i];

	return 0;
}
