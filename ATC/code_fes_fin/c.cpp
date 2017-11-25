#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;
int D[BUF];
int dcnt[13];
int used[25];
int ans;


void dfs(int d){
	int sm,bg;
	sm=D[d];
	bg=24-D[d];

	if(d==n+1){
		//count used!!!!
		int cnt=0;
		int index=0;
		int min = 1000;
		for(int i=0;i<=24;i++){
			
			if(used[i]==1){
				cnt=i-index;
				index = i;
				if(min>cnt) min = cnt;
			}
		}

//		cout << min << "calc\n";
		if(min==1000) return ;
		if(min>ans) ans = min;
		return;
	}

	if(used[sm]==0){

		used[sm]=1;

//		cout << d << sm << "\n";	
		dfs(d+1);
		used[sm]=0;
	}

	if(used[bg]==0){

//		cout << d << bg << "\n";	
		used[bg]=1;
		dfs(d+1);
		used[bg]=0;
	}

	if(used[bg]==1 && used[sm]==1) return;
}

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> D[i];
		dcnt[D[i]]++;
	}

	for(int i=1;i<12;i++){
		if(dcnt[i]>2){ 
			cout << 0;
			return 0;
		}
	}

	if(dcnt[0]>0){
		cout << 0;
		return 0;
	}

	if(dcnt[12]>1){
		cout << 0;
		return 0;
	}

	if(n==1){
		int sm=D[1];
		int bg=24-sm;
		cout << sm;
		return 0;
	}


/*
	for(int i=0;i<12;i++){
		if(dcnt[i]==2){ 
			used[i]=1;
			used[24-i]=1;
		}
	}
*/
	//used[0]=1;
	used[24]=1;
	dfs(1);

	cout << ans;
	return 0;
}
