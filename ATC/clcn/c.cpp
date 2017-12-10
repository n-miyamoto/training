#include <bits/stdc++.h>

using namespace std;
#define BUF (100)
#define ll long long 

ll a,b;
int A[BUF][BUF];
ll cnt =1;
vector<ll> v;

void dfs(ll n){
	cnt++;
//	cout << n << " ";
	if(n==b) return;

	v.push_back(n);
	for(ll i=n+1;i<=b;i++){
		int f=1;
		for(auto x: v){
			if(A[x-a][i-a]==1)f=0;
		}

		if(f==1){
			dfs(i);
		}
	}
	v.pop_back();
	return ;
}

int main(void){
	cin >> a >> b;

	for(ll i=a;i<=b;i++){
		for(ll j=a;j<=b;j++){
			A[i-a][j-a] = 0;
			for(ll k=2;k<=35;k++){
				if(i%k==0 && j%k==0){
					A[i-a][j-a] = 1;
					break;
				} 
			}
		}
	}

/*
	for(int i=0;i<=b-a;i++){
		for(int j=0;j<=b-a;j++){
			cout << A[i][j]<<  " ";
		}
		cout << "\n";
	}
	*/

	for(ll i=a;i<=b;i++){
		dfs(i);	
//		cout << cnt << " ";
	}
	cout << cnt << endl;

	return 0;
}
