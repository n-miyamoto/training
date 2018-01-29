#include <bits/stdc++.h>
using namespace std;

#define BUF (1005)
#define INF (1000000005)
#define ll long long 


int n,m;
map<string,string> M;

int main(void){
	cin >> n >> m;

	for(int i=1;i<=n;i++){
		string name,ip;
		cin >> name >> ip;
		M[ip]=name;
	}

	for(int i=1;i<=m;i++){
		string cmd;
		string ip;
		string tmp;
		cin >> cmd >> tmp;
		ip =tmp;
		ip.pop_back();


		cout << cmd << " " << ip << "; #" << M[ip] << "\n";
	}
	return 0;
}
