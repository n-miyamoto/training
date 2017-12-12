#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


int n;
int x[BUF];
int y[BUF];
int cnt;

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		 cin >> x[i] >> y[i];
		if(x[i]<0)cnt++;
	}

	if(cnt<=1) cout << "Yes" << endl;
	else if(n-cnt<=1) cout << "Yes" << endl;
	else cout << "No" << endl;


	return 0;
}
