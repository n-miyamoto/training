#include <bits/stdc++.h>

using namespace std;
#define BUF (1004)
#define ll long long 

char mat[BUF][BUF];
int n,m,a,b;

int main(void){
	cin >> n >> m >> a >> b;
	int od=0;
	//fill with .
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			mat[i][j]='.';
		}
	}
	
	int r=0;
	int c=0;
	if(n%2==1 ){ 
		r=min(a,m/2);
		a-=r;
		for(int i=0;i<r;i++){
			mat[n][2*i+1]='<';
			mat[n][2*i+2]='>';
		}
	}
	if(m%2==1 ){ 
		c=min(b,n/2);
		b-=c;
		for(int i=0;i<c;i++){
			mat[2*i+1][m]='^';
			mat[2*i+2][m]='v';
		}
	}

	if(n%2==1 && m%2==1 && a%2==1 && b%2==1){
			mat[n-2][m-2]='<';
			mat[n-2][m-1]='>';
			mat[n-2][m  ]='^';
			mat[n-1][m  ]='v';
			mat[n  ][m  ]='>';
			mat[n  ][m-1]='<';
			mat[n  ][m-2]='v';
			mat[n-1][m-2]='^';
			a--;
			b--;
			od = 1;
	}

	int recta=(a+1)/2;
	int rectb=(b+1)/2;
	int rects=recta+rectb;

	if((n/2)*(m/2)-od -rects<0){
		cout << "NO\n";
		return 0;
	}else{
		cout << "YES\n";
	}

	//cout << a << b ;

	for(int i=0;i<n/2;i++){
		for(int j=0;j<m/2;j++){
			if(a<=0)break;
			mat[2*i+1][2*j+1 ] = '<'; 
			mat[2*i+1][2*j+2 ] = '>';
			mat[2*i+2][2*j+1 ] = '<';
			mat[2*i+2][2*j+2 ] = '>';
			if(a==1){
				mat[2*i+2][2*j+1 ] = '.';
				mat[2*i+2][2*j+2 ] = '.';	
			}	
			a-=2;
		}
	}
	
	for (int i = 0; i < n / 2; i++){
		for (int j = 0; j < m / 2; j++){
			if (mat[2 * i + 1][2 * j + 1] == '.'){
				if (b<=0)break;
				mat[2 * i + 1][2 * j + 1] = '^';
				mat[2 * i + 1][2 * j + 2] = '^';
				mat[2 * i + 2][2 * j + 1] = 'v';
				mat[2 * i + 2][2 * j + 2] = 'v';
				if(b==1){
					mat[2 * i + 1][2 * j + 2] = '.';
					mat[2 * i + 2][2 * j + 2] = '.';	
				}
				b-=2;
			}
		}
	}


	//show
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			cout << mat[i][j];
		}
		cout << "\n";
	}
	return 0;
}
