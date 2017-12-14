#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


int h1,h2,a1,a2,c1;
int n;
char s[BUF];
int ans[BUF];

int main(void){
	cin >> h1 >> a1 >>c1;
	cin >> h2 >> a2;

	int hp=h1;

	while(h2>0){
		n++;
		if(h2-a1<=0){
			ans[n]=1;
			h2-=a1;
		}else if(hp-a2>0){
			//strike
			ans[n]=1;
			h2-=a1;
		}else{
			//heal
			hp+=c1;
		}
		//atacked by mc
		hp-=a2;
	}	

	cout << n << "\n";
	for(int i=1;i<=n;i++){
		//cout << ans[i];
		if(ans[i]==1) cout << "STRIKE\n";
		else cout << "HEAL\n";
	}

	return 0;
}
