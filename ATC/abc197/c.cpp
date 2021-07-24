#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;
vector<int> v;

/*
  s0   s1   s2    ...    s(n-2)       0
a0 | a1 | a2 | a3 ... a(n-2) | a(n-1) |
*/
int orxor(int s){
	int ret = 0;
	int tor = 0;
	for(int i=0;i<n;i++){
		//find a seperator
		//cout << v[i] << " " << tor << " "  << ret << endl;
		tor |= v[i];
		if( s&(1<<i) ){
			ret ^= tor;
			tor = 0;
		}
	}
	ret ^= tor;

	return(ret);
}

int main(void){
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}

	int ans = 0x7FFFFFFF; //intmax
	for(int i=0;i < (1<<(n-1));i++){
		int tmp = orxor(i);
		ans = min(tmp, ans);
	}

	cout << ans << endl;
	
	return 0;
}
