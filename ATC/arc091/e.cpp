#include <bits/stdc++.h>

using namespace std;
#define BUF (300005)
#define ll long long 

int n,a,b;

int v[BUF];


int main(void){
	cin >> n >> a >> b;

	int sep = n/a;
	if(n%a!=0)sep++;
	
	if(n<a){
		cout << -1 << endl;
		return 0;
	}
	if(b<sep || n-a+1 < b){
		cout << -1 << endl;
		return 0;
	}

	int cnt = 0;
	while(1){
		int st = 1+a*cnt;
		int end= a+a*cnt;

		if(st<=n&&n<=end){
			int c=0;
			for(int i=st;i<=n;i++){
				v[i]=-cnt*a+c+st;
				c++;
			}
			break;
		}

		for(int i=1;i<=a;i++){
			v[i+cnt*a]=n-a+i-cnt*a;
		}
		cnt++;
	}

	for(int i=a+1;i<=n;i++){
		int k = i/a;
		if(i%a!=0)k++;
		k+=n-i;
		//cout << k << i<< " ";
		if(k==b){
			sort(v+i,v+n+1,greater<int>());
			break;
		}
	}

	for(int i=1;i<=n;i++){
		 cout << v[i];
		 cout << " ";
	}
	cout << endl;
	return 0;
}
