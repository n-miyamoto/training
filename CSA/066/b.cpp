#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 

int n,x;

typedef struct {
    int a;
    int b;
} P;

P p[BUF];
int dp[BUF];
int ans[BUF];

bool asc( const P& left, const P& right ) {
    return left.a < right.a;
}


int main(void){
	cin >>n >>x;
	for(int i=0;i<n;i++) cin >> p[i].a >> p[i].b;

	sort(p,p+n,asc);

	dp[0] = p[0].b;		
	for(int i=1;i<n;i++) dp[i] = dp[i-1]+p[i].b;

	int Ans=INF;	
	for(int i=0;i<n;i++){
//		cout << p[i].a << p[i].b << dp[i]<<"\n";
		if(p[i].a<=x) ans[i]=x-dp[i];
		else ans[i] = p[i].a -dp[i];

		Ans = min(Ans,ans[i]);		
		cout << p[i].a << p[i].b << ans[i]<<"\n";
	}
	cout << Ans << endl;

	return 0;
}
