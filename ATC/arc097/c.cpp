#include <bits/stdc++.h>
using namespace std;

string str;
set<string> s;
int n;
int k;

int main(void){
	cin >> str;
	cin >> k;

	n= str.length();
	for(int i=1;i<=k;++i){
		for(int j=0;j<n-i+1;j++){
			s.insert(str.substr(j,i));
		}
	}	


	int cnt = 0;
	for(auto x : s){
		cnt++;
		if(cnt==k){
			cout << x<<endl;
			break;
		}
	}	

	return 0;
}
