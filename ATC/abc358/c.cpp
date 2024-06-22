#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n, m;
	cin >> n >> m;

	vector<int> v(n, 0);
	for(int i=0;i<n;i++){
		string s;
		cin >> s;

		for(int j=0;j<m;j++){
			if(s[j]=='o') v[i] += 1<<j;
		}
	}

	int mn = n;
	for(int i=0;i<(1<<n);i++){
		int tmp=0;
		int pop_cnt = 0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				tmp|=v[j];
				pop_cnt++;
			}
		}

		if(tmp==((1<<m)-1)) mn = min(mn, pop_cnt);
	}

	cout << mn << endl;
	
	return 0;
}
