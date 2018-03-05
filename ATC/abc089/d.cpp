#include <bits/stdc++.h>

using namespace std;
#define BUF (305)
#define ll long long 

int h,w,d,q;
int A[BUF][BUF];
int B[BUF*BUF];

typedef struct {
	int x;
	int y;
}P;

P p[BUF*BUF];

int dist(P a,P b){
	int k=abs(a.x-b.x)+abs(a.y-b.y);
	return k;
}

int main(void){
	cin >> h >> w >> d;
	
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin >> A[i][j];
			p[A[i][j]]={i,j};
		}
	}

	int a = h*w/d;
	
	for(int i=1;i<=a;i++){
		for(int j=0;j<d;j++){
			int index = d*i+j;
			B[index] = B[index-d]+dist(p[index-d],p[index]);
		}
	}

	cin >> q;
	for(int i=0;i<q;i++){
		int r,l;
		cin >> r >> l;
		cout << B[l]-B[r] << "\n";
	}
	return 0;
}
