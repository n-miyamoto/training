#include <bits/stdc++.h>

using namespace std;
#define BUF (205)

int h,w;
int a[BUF][BUF];
int c[11][11];


void wf(void){
	for(int k=0;k<10;k++) for(int i=0;i<10;i++) for(int j=0;j<10;j++){
		if(c[i][j] > c[i][k]+c[k][j]) c[i][j] = c[i][k]+c[k][j];
		
	}
}

int main(void){
	cin >> h >>w;
	for(int i=0;i<10;i++) for(int j=0;j<10;j++) cin >> c[i][j];
	wf();
	int ans =0;
	for(int i=1;i<=h;i++) for(int j=1;j<=w;j++){
		 int tmp;
		 cin >> tmp;
		 //cout << tmp;
		 if(tmp!=-1)ans+=c[tmp][1]; 
	}

	cout << ans << endl;
	return 0;
}
