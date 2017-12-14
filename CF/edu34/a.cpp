#include <bits/stdc++.h>
using namespace std;

#define BUF (105)
#define INF (1000000005)
#define ll long long 


int n;
int a[BUF];
int ans[BUF];

int main(void){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		int r=a[i]/3;
		for(int j=0;j<=r;j++){
			if(((a[i]-(3*j))%7)==0 )ans[i]=1;
		}
	}

	for(int i=0;i<n;i++){
		if(ans[i]==1) cout << "YES\n";
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
