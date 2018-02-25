#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 
#define INF (1000005)

int n;

typedef struct {
	int x;
	int y;	
}P;

P p[105];

#define BIN (500000)
int v[BIN];

int main(void){
	cin >> n;

	for(int i=1;i<=n;i++){
		cin >> p[i].x >> p[i].y;
	}	

	double th = 2*M_PI/BIN;
	double theta = 0;
	for(int i=0;i<BIN;i++){
		theta+=th;	
		double mx=-INF;
		int max_i=-1;
		for(int j=1;j<=n;j++){
			double tmp = p[j].x*cos(theta)+p[j].y*sin(theta) ;
			if(mx < tmp){
				mx = tmp;
				max_i = j;
			}
		}
		v[max_i]++;
	}

	for(int i=1;i<=n;i++){
		cout << (double)v[i]/(double)BIN << "\n";
	}

	return 0;
}
