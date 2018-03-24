#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


ll h,m,H,C,D,N;

int main(void){
	cin >> h >> m;
	cin >> H >> D >> C >> N;
	double ans;
	ll num = H/N;
	if(H%N!=0)num++;	
	
	if(h>=20){
		ans = (double)num*C * 0.8;
		cout << ans << endl;
		return 0;
	}

	ans = (double)num*C ;
	
	ll time = 20*60-h*60-m;
	H+=time*D;
	num = H/N;
	if(H%N!=0)num++;
	double tmp =  num *C *0.8 ;
	//cout << tmp << ans;
	cout << min(tmp,ans) << endl;

	return 0;
}
