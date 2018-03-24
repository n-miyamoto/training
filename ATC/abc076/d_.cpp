#include <bits/stdc++.h>

using namespace std;
#define BUF (105)
#define INF (1000000006)
#define ll long long 

int n;
int t[BUF];
int v[BUF];
int g[100*200*2+5];

int f(int x, int y){
	if(y==0) return x;
	if(y==n+1) return -x+2*t[n];

	if(x<2*t[y-1]){
		return -x+2*t[y-1]+2*v[y];
	}else if(x>2*t[y]){
		return x-2*t[y]+2*v[y];
	}else {
		return 2*v[y];
	}
}




int main(void){
	cin >> n;
	int tm=0;

	for(int i=1;i<=n;i++){
		int tmp;
		cin >> tmp;
		tm+=tmp;
		t[i]=tm;
	}

	for(int i=1;i<=n;i++){
		cin >> v[i];
	}


	for(int i=0;i<=2*t[n];i++){
		int m = INF;
		for(int k=0;k<=n+1;k++){
			m=min(m,f(i,k));
		}
		g[i]=m;
		//cout << m << " ";
	}

	int ans = 0;
	for(int i=0;i<2*t[n];i++){
		ans += g[i]+g[i+1];
	}

	cout << setprecision(20) <<  (double)ans/(double)8 << endl;
	return 0;
}
