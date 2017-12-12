#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


int a,b,c;
int used[BUF];

int main(void){
	cin >> a >> b >> c;

	int cnt = 0;	
	
	while(1){
		if(used[a]==1)break;
		used[a]=1;
		cnt++;
		a*=10;
		int tmp = a/b;
		if(tmp==c) {
			cout << cnt << endl;
			return 0;
		}
		a=a%b;
	}

	cout << "-1" << endl;
	return 0;
}
