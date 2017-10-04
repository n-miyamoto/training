#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int n;
long long k;
int a,b;
int A[4][4];
int B[4][4];
void input(void){
	cin >> k >> a >> b;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin >> A[i][j];
		}
	}

	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cin >> B[i][j];
		}
	}
}

int j(int a,int b){
	if(a==1 && b==3){
		return 1;
	}
	if(a==2 && b==1){
		return 1;
	}
	if(a==3 && b==2){
		return 1;
	}
	return 0;
}

int main(void){
	input();

	int f[4][4];
	for(int i=0;i<16;i++)	f[i/4][i%4] = 0;

	long long x=a;
	long long y=b;
	int p,q,t;
	long long xp[12];
	long long yp[12];
	yp[0]=0;xp[0]=0;
	for(int i=1;i<11;i++){
		xp[i] = xp[i-1] + j(x,y); 
		yp[i] = yp[i-1] + j(y,x);
		if(f[x][y]==0){
			f[x][y]=i;
		}else{
			p=f[x][y];
			q=i;
			t=q-p;
			break;
		}		
		int xt = x;
		int yt = y;
		x = A[xt][yt];
		y = B[xt][yt];
	}

	if(k<q){
		cout << xp[k] << " " << yp[k] << endl;
		return 0;
	}

	long long l;
	int m;
	l=(k-p+1)/t;
	m=(k-p+1)%t;

	long long ans,bns;
	ans = xp[p-1+m] + l*(xp[q]-xp[p]);
	bns = yp[p-1+m] + l*(yp[q]-yp[p]);
	
	cout << ans << " " << bns << endl;

//	cout <<p<< " " << q<< " " <<t<<l<<m;
	return 0;
}
