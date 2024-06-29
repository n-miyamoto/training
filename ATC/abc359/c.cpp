#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(void){
	ll sx, sy, tx, ty;
	cin >> sx >> sy
		>> tx >> ty;

	if((sx + sy)%2!=0) sx--; //align to left
	if((tx + ty)%2!=0) tx--; //align to left


	auto dy = abs(ty - sy);

	auto left = sx - dy;
	auto right= sx + dy;


	ll ans;
	if(tx < left) {
		ans = dy + (left - tx)/2;
	}else if (tx <= right){
		ans = dy;
	}else{
		ans = dy + (tx - right)/2;
	}

	cout << ans << endl;

	return 0;
}
