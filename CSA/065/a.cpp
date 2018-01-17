#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 

int n;
char s[BUF];
char p[27];

int main(void){
	cin >> s;
	cin >> p;
	n=strlen(s);
	for(int i=0;i<n;i++){
		cout << p[s[i]-'a'];
	}

	cout << endl;
	return 0;
}
