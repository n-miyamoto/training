#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll d;

ll findMinGreaterThanSqrt(ll d) {
    return std::ceil(std::sqrt(d));
}

int main(void){
	cin >> d;
	auto root_d = findMinGreaterThanSqrt(d);

	auto mn = (ll)1000000000009;
	for (ll i=0;i<=root_d;i++){
		auto x = i;
		auto y = findMinGreaterThanSqrt(d-x*x);

		{
			if (d-x*x<0) { y=0; }
			auto tmp = abs(x*x+y*y-d);
			mn = min(mn, tmp);
			//cout << x << y << tmp << endl ;
		}

		{
			if (d-x*x<0) { y=0; }
			else  {
				y--;
			}
			auto tmp = abs(x*x+y*y-d);
			mn = min(mn, tmp);
			//cout << x << y << tmp << endl ;
		}
	}

	cout << mn << endl;
	
	return 0;
}
