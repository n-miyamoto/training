#include <bits/stdc++.h>
using namespace std;

#define BUF (1000)
#define INF (1000000005)
#define ll long long 

int n;
char s[BUF];
int v[BUF];

int main(void){
	cin >> n;
	cin >>s;

	for(int i=0;i<n;i++) v[s[i]]++;

	for(int i=0;i<n;i++){
		if(v[s[i]]==1){
			cout << s[i] << endl;
			return 0;
		}
	}	

	cout << -1 << endl;
	return 0;
}
