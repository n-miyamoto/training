#include <stdio.h>
#include <iostream>
#include <vector>

#define BUF (100005)

using namespace std;

int n;
int u[BUF];
int v[BUF];
int f[BUF];

vector<int> vec[BUF];


void input(void){
	std::cin >> n;
	for(int i=0;i<n-1;i++){
		std::cin >> u[i] >> v[i];
	}
}

void dfs(int a,int b){
	for(int i=0;i<vec[a].size();i++){
		int k= vec[a][i];
		if(f[k]==0){
			f[k]=-1*b;
			dfs(k,-1*b);
		}
	}
	return;
}

int main(void){
	input();

	for(int i=0;i<n;i++){
		vec[u[i]].push_back(v[i]);
		vec[v[i]].push_back(u[i]);		
	}
	for(int i=1;i<=n;i++)f[i]=0;

	f[1]=1;
	dfs(1,1);

	int a=0;
	int b=0;
	for(int i=1;i<=n;i++){
//		cout << f[i] << endl;
		if(f[i]== 1)a++;
		if(f[i]==-1)b++;
	}

	cout << (long long) a*b-n+1 << endl;
	return 0;
}
