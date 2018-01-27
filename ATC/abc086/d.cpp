#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n,k;
int x[BUF];
int y[BUF];

int d[4003][4003];
int m[4003][4003];

void show(void){

	cout << "d----------\n";
	for(int i=0;i<2*k;i++) {
		for(int j=0;j<2*k;j++) cout << d[j][i];
		cout << "\n";
	}
	
	cout << "m----------\n";
	for(int i=0;i<2*k;i++) {
		for(int j=0;j<2*k;j++) cout << m[j][i];
		cout << "\n";
	}
}

int main(void){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		int tx,ty;
		char tc;
		cin >> tx >> ty >> tc;
		//change all white to black.
		if(tc=='W')ty+=k;

		//move all point to 0~2k-1.
		x[i] = tx%(2*k);
		y[i] = ty%(2*k);

		if(x[i]<k && y[i]<k){
			x[i]+=k;
			y[i]+=k;
		}
		if(x[i]<k && y[i]>=k){
			x[i]+=k;
			y[i]-=k;
		}

//		cout << x[i] << "," << y[i] << "\n";
	}

	//check all corner.
	for(int i=1;i<=n;i++){
		d[max(x[i]-k+1,0)][max(y[i]-k+1,0)]++;
		d[    x[i]+1     ][    y[i]+1     ]++;
		d[max(x[i]-k+1,0)][    y[i]+1     ]--;
		d[    x[i]+1     ][max(y[i]-k+1,0)]--;
	
		d[max(x[i]-k+1,0)][    y[i]+k+1   ]++;
		d[    x[i]+1     ][    y[i]+1+2*k ]++;
		d[max(x[i]-k+1,0)][    y[i]+1+2*k ]--;
		d[    x[i]+1     ][    y[i]+k+1   ]--;

		d[   x[i]+k+1    ][max(y[i]-k+1,0)]++;
		d[   x[i]+1+2*k  ][    y[i]+1     ]++;
		d[   x[i]+k+1    ][    y[i]+1     ]--;
		d[   x[i]+1+2*k  ][max(y[i]-k+1,0)]--;
	
		d[    x[i]+1     ][    y[i]+1     ]++;
		d[    x[i]+1 +k  ][    y[i]+1 +k  ]++;
		d[    x[i]+1     ][    y[i]+1 +k  ]--;
		d[    x[i]+1 +k  ][    y[i]+1     ]--;

		d[   x[i]+k+1    ][    y[i]+k+1       ]++;
		d[   x[i]+1+2*k  ][    y[i]+1+2*k     ]++;
		d[   x[i]+k+1    ][    y[i]+1+2*k     ]--;
		d[   x[i]+1+2*k  ][    y[i]+k+1       ]--;
	
	}

	int ans = 0;
	int st=0;
	for(int j=0;j<3*k;j++) {
		st=0;
		for(int i=0;i<3*k;i++){
			//first line
			st+=d[i][j];
			if(j==0) m[i][j] = st;
			else  m[i][j]=m[i][j-1]+st; 	
			ans = max(ans,m[i][j]);
		}
	}

//	show();
	
	cout << ans << endl;
	return 0;
}
