#include <bits/stdc++.h>

using namespace std;
#define BUF (53)
#define INF (100)

int N,M;

int A[BUF][BUF];
int c[BUF][BUF];
int a[BUF];
int b[BUF];


void wf(void){
    for(int k=1;k<=N;k++) for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
        if(c[i][j] > c[i][k]+c[k][j]) c[i][j] = c[i][k]+c[k][j];   
    }
}

int ans = 0;
int main(void){
	cin >> N >> M;
	for(int i=0;i<BUF;i++)for(int j=0;j<BUF;j++) A[i][j]=INF;
	for(int i=1;i<=M;i++){
		cin >> a[i] >> b[i];
		A[a[i]][b[i]] = 1;
		A[b[i]][a[i]] = 1;
	}

	for(int i=1;i<=M;i++){
		for(int i=0;i<BUF;i++)for(int j=0;j<BUF;j++) c[i][j]=A[i][j];
		c[a[i]][b[i]]=INF;
		c[b[i]][a[i]]=INF;
		wf();
		if(c[a[i]][b[i]]==INF) ans++;
	}

	cout << ans << endl;

	return 0;
}
