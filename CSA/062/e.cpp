#include <bits/stdc++.h>
using namespace std;

#define BUF (1005)
#define INF (1000000005)
#define ll long long 

int N,M,Q;
//bool A[BUF][BUF];
vector<int> v[BUF];
int c[BUF];
int eg[BUF];
bool dp[BUF][BUF];

int used[BUF];
int a[BUF];
int st=0;
void dfs(int x, int y){
	if(x==y){
		 st++;
		return;
	}

	used[x]=1;
	for(auto i:v[x]){
		if(used[i]==0) dfs(i,y);
	}
	used[x]=0;
	return;
}

int main(void){
	cin >> N>>M>>Q;
	for(int i=1;i<=M;i++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		c[x]++;
		c[y]++;
	}
	//query
	for(int i=1;i<=Q;i++) {
		int x,y;
		cin >> x >> y;
		st=0;
		dfs(x,y);		
		if(st==1)a[i] = st;

	}		

	for(int i=1;i<=Q;i++) {
		cout << a[i] << "\n";
	}		




	return 0;
}
