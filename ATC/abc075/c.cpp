#include <bits/stdc++.h>

using namespace std;
#define BUF (60)

int N,M;

int A[BUF][BUF];
int a[BUF],b[BUF];
int f[BUF];
int fcnt=0;

int dfs(int nd){
//	cout << nd << fcnt;
	f[nd]=1;fcnt++;
	if(fcnt==N) return 1; //renketsu
	int ret=0;
	for(int i=1;i<=N;i++){
		if( f[i]==0 && A[nd][i]==1){
			ret+=dfs(i);
		}
	}
	if(ret>0) return 1;
	else return 0;
}

int main(void){
	memset(A,0,BUF*BUF);
	memset(f,0,BUF);
	cin >> N >> M;
	for(int i=1;i<=M;i++){
		cin >> a[i] >> b[i];
		A[a[i]][b[i]] = 1;
		A[b[i]][a[i]] = 1;
	}

	int ans = M;
	for(int i=1;i<=M;i++){
		memset(f,0,BUF);
		fcnt=0;
		A[a[i]][b[i]]=0;
		A[b[i]][a[i]]=0;
		ans -= dfs(1);
		A[a[i]][b[i]]=1;
		A[b[i]][a[i]]=1;
		//cout << ans << "\n";
	}	

	cout << ans << endl;

	return 0;
}
