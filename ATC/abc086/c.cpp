#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


int n;

bool check(int t, int x, int y){
	int tmp = x+y;
	if(tmp<=t && tmp>=-t){
		tmp = abs(tmp);
		//cout << tmp%2 << t%2;	
		if((tmp%2) == (t%2) ){
			//cout << true;
			return true;
		}
	}
	return false;
}

int main(void){
	cin >> n;
	int ans = 1;
	int tc=0,xc=0,yc=0;
	for(int i=0;i<n;i++){
		int t,x,y;
		cin >> t >> x >> y;
		if(!check(t-tc,x-xc,y-yc))ans = 0;
		//cout << check(t-tc,x-xc,y-yc);
		tc = t;xc = x;yc = y;
	}

	if(ans == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
	
}
