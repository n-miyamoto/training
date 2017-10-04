#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define BUF (1000)

vector<int> vec;

int n;
int t[BUF];
int d[BUF];
int p[BUF];

void input(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> t[i] >> d[i] >> p[i];
}

int flag[21];

int dfs(int T, int V){
	int sum=0;
	for(int i=1;i<=n;i++)sum+=flag[i];
	if(sum==n){
		return V;
	}

	int max=0;
	ind max_ind=0;
	for(int i=1;i<=n;i++){
		int tmp;
		if(flag[i]==1){
		}else{
			flag[i]=1;
			if(T+t[i]<d[i]){
				tmp = dfs(T+t[i],V+p[i]);
				if(max<tmp){ 
					max = tmp;
					max_ind=i;
				}
			}else{
				tmp = V;
				if(max<tmp) max = tmp;
			}
			vec.pop_back();
			flag[i]=0;
		}
	}
	if(max_ind!=0)vec.push_back(max_ind);
	return max;
}

int main(void){
	input();
	for(int i=0;i<21;i++) flag[i]=0;

	cout << dfs(0,0) << endl;
	return 0;
}
