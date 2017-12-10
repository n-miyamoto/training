#include <bits/stdc++.h>

using namespace std;
#define BUF (110)
#define INF (1000005)
#define ll long long 

int n;
int a[BUF];
int mn = INF;
int mx = -INF;
int mxi = 0;
int mni = 0;
int m=0;
int x[BUF];
int y[BUF];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){ 
		cin >> a[i];
		if(mn>a[i]){
			 mn = a[i];
			 mni=i;
		}
		if(mx<a[i]){
			 mx = a[i];
			 mxi=i;
		}
	}


	if(mn<0 && mx>0 && mx+mn>=0){
	for(int i=1;i<=n;i++){
		if(i==mxi) continue;
		a[i]+=mx;
		m++;
		x[m] = mxi;
		y[m] = i;
	}
	mn=1;
	}


	if(mn<0 && mx>0 && mx+mn<0){
	for(int i=1;i<=n;i++){
		if(i==mni) continue;
		a[i]+=mn;
		m++;
		x[m] = mni;
		y[m] = i;
	}
	mx=-1;
	}


	if(mn>=0){//all pos
		for(int i=1;i<n;i++){
			if(a[i]>a[i+1]){
				a[i+1]+=a[i];
				m++;
				x[m]=i;
				y[m]=i+1;
			}
		}
	}

	if(mx<=0){//all neg
		for(int i=n;i>1;i--){
			if(a[i]<a[i-1]){
				a[i-1]+=a[i];
				m++;
				x[m]=i;
				y[m]=i-1;
			}
		}	
	}


	cout << m << "\n";
	for(int i=1;i<=m;i++){
		cout << x[i] << " " << y[i] << "\n";
	}
	return 0;
}
