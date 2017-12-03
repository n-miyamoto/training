#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define INF  (-1000000005)

int n;
int f[105][12];
ll p[105][13];
int c[105];

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++) for(int j=0;j<10;j++) cin >> f[i][j];

	for(int i=1;i<=n;i++) for(int k=0;k<=10;k++)cin >> p[i][k];


	ll ans = INF;
	for(int k=1;k<1024;k++){

		//calc all c
		for(int i=1;i<=n;i++) {
			c[i] = 0;
			for(int j = 0; j < 10; j++)
			{
				int tmp = (k >> j) % 2;
				if (tmp == 1 && f[i][j] == 1)
				{
					c[i]++;
				}
			}
		}
		

		//calc cost
		ll cost = 0;
		for(int i=1;i<=n;i++){
			//cout << c[i]<<" ";
			//if(c[i]>10) return 0;
			cost+=p[i][c[i]];
			
		}

		//update
		if(ans<cost) ans=cost;
	}

	cout << ans;

	return 0;
}
