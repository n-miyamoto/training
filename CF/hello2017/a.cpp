#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


long long n,m;


int main(void)
{
	cin >> n >> m;

	long long K=1;
	while(n>0){
		K*=2;
		if(K>100000000){
			break;
		}
		n--;
	}

	if(n<0) cout << m << endl;
	else cout << m%K << endl;

	return 0;
}
