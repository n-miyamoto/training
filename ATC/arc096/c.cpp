#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int a,b,c,x,y;
int ans;

int main(void){
	cin >> a >> b >> c >> x >> y;

	if( 2*c < a+b){
		int tmp = min(x,y);
		x-=tmp;
		y-=tmp;
		ans = 2*c*tmp;
	}else{
		cout << a*x + b*y << endl;
		return 0;
	}

	if(2*c < a){
		ans += 2*c*x;
	}else{
		ans += a*x;
	}

	if(2*c < b){
		ans += 2*c*y;
	}else{
		ans += b*y;
	}
	
	cout << ans << endl;

	return 0;
}
