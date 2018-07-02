#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 
#define INF 1e15
int n;
ll a[BUF];
ll s[BUF];
ll total;
int main(void){
	cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    a[i]-=i;
  }

  sort(a+1,a+n+1);

  for(int i=1;i<=n;i++){
    s[i]=s[i-1]+a[i];
  }

  ll ans = INF;
  for(int i=1;i<n;i++){
    if(a[i]==a[i+1]) continue;

    ll tmp = s[n]-2*s[i]; 
    if(2*i-n>0) tmp+= (2*i-n)*a[i];
    else tmp+= (2*i-n)*a[i+1];

    ans = min(ans,tmp);
  }

  if(ans==INF) {
    cout << 0 << endl;
    return 0;
  }

  cout << ans << endl;
	return 0;
}
