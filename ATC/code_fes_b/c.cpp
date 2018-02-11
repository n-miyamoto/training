#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
#define BUF (100005)


int N,M;
set<int> edg[BUF];
void input(void){
	cin >> N >> M;
	for(int i=1;i<=M;i++){
		int a,b;
		cin >> a >> b;
		edg[a].insert(b);
		edg[b].insert(a);
	}
}

int dfs(int a , int p){
	
	
	return 0;
}

int main(void){
	input();

	for(int i=1;i<=N;i++){
		for(int j=1;j<=edg[i].size();i++){
			cout << edg[i][j] << endl;
		}
	}

	return 0;
}
