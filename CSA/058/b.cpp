#include <bits/stdc++.h>
using namespace std;
#define BUF (2005)
#define ll long long 

int n;
typedef struct {
	int a;int b;
}SEG;
SEG s[BUF];

bool asc( const SEG& left, const SEG& right ) {
    return left.a < right.a;
}

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> s[i].a >> s[i].b;
	sort(s+1,s+n+1,asc);
	
	ll ans = -1; 

	for(int i=1;i<=n;i++){
		//fix i
		ll cnt = 0;
		ll sl = 0;

		if(i!=1)
		for(int j=i-1;j>0;j--){
			sl +=s[j+1].a - s[j].b;
			cnt+=sl;
		}

		ll sr = 0;
		if(i!=n)
		for(int j=i+1;j<=n;j++){
			sr+=s[j].a-s[j-1].b;
			cnt+=sr;
		}

	//	cout << cnt; 
		if(ans==-1 || ans>cnt) ans = cnt;
	}

	cout << ans << endl;

	return 0;
}
