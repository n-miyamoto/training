#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
#define BUF (70005)
#define NBUF (100000000)

int n;
string  s[BUF];
map<string, int> m;

void input(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> s[i];
}

int main(void){
	input();
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=9;j++)for(int k=0;k<=9-j;k++){
			if(m.find(s[i].substr(k,j))==m.end() ){
				m[s[i].substr(k,j)] = i;	
			}else if(m[s[i].substr(k,j)]!=i){
				m[s[i].substr(k,j)] = -1;	
			}
//			cout << k <<" " << k+j-1 << " "  << endl;
		}
	}

	int ans[BUF];
	string str[BUF];
	for(int i=1;i<=n;i++)ans[i] = -1;
	for(auto &a:m){
//		cout << a.first << " " << a.second <<endl;
		if(a.second>0){
			if(ans[a.second]<0){
				ans[a.second]=a.first.size();
				str[a.second]=a.first;
			}else if(ans[a.second]>a.first.size() ){
				ans[a.second]=a.first.size();
				str[a.second]=a.first;	
			}
		}
	}	

	for(int i=1;i<=n;i++) cout << str[i] << endl;

	return 0;
}
