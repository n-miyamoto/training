#include <bits/stdc++.h>

using namespace std;
using ll=long long;



int main(void){
	int h, w;
	cin >> h >> w;

	vector<string> m(h);

	for(auto& s: m) cin >> s;

	int a=1000, b=0;
	int c=1000, d=0;

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(m[i][j]=='#'){
				a = min(a, i);
				b = max(b, i);
				c = min(c, j);
				d = max(d, j);
			}
		}
	}


	for(int i=a;i<=b;i++){
		for(int j=c;j<=d;j++){
			if(m[i][j]=='.'){
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;
	return 0;
}
