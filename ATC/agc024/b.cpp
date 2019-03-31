#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

int n;
int p[BUF];
int b[BUF];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> p[i];
		b[p[i]] = i;
	}

	int cnt = 0;
	int max_cnt=0;
	for(int i=1;i<n;i++){
		if(b[i]<b[i+1]){
			cnt++;
		}else 
			cnt = 0;
		max_cnt = max(cnt, max_cnt);
	}

	cout << n-max_cnt-1 << endl;
	
	return 0;
}
