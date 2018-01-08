#include <bits/stdc++.h>
using namespace std;

#define BUF (1005)
#define INF (1000000005)
#define ll long long 


int n;
char s[BUF];
vector<int> v[BUF];
int lf[BUF];
int lfn[BUF];

int main(void){
	cin >> n;
	for(int i=2;i<=n;i++){
		int tmp;
		cin >> tmp;
		v[tmp].push_back(i);
	}

	//find leaf
	for(int i=1;i<=n;i++){
		if(v[i].size()==0)lf[i]=1;//i is leaf
	}

	//find connected leaf
	for(int i=1;i<=n;i++){
		for(auto x: v[i]){
			if(lf[x]==1)lfn[i]++;
		}
	}

	//check node	
	for(int i=1;i<=n;i++){
		if(lf[i]==0){
			if(lfn[i]<3){
				cout << "No\n";
				return 0; 
			}
		}
	}

	cout << "Yes\n";
	
	return 0;
}
