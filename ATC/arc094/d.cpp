#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;

int main(void){
	cin >> n;

	for(int i=0;i<n;i++){
		ll a,b;
		ll big = 0;
		cin >> a >> b;
		ll sc = a*b;
		ll c=min(a,b);
		ll h = max(a,b);
		ll l = min(a,b);
		while(1){
			ll m = (h+l)/2;
			if(m*m<=sc-1){
				l=m;
			}else{
				h=m;
			}
			if(abs(h-l)<=1){
				c=l;
				break;
			}
		}
		if(a==b){
			cout << 2*a-2 << "\n";
			continue;
		}
		if(c*(c+1)<=sc-1) big=1;
		if(a==b) big++;
		cout << 2*c -2 + big << "\n";	
	}


	return 0;
}
