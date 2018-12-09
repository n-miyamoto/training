#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll n,k;
ll ans = 0;
int main(void){

	cin >> n >> k;

	ll m = n/k;
	ll m_=0;
	if(k%2==0) m_=n/(k/2)-m;
	cout << m*m*m + m_*m_*m_<< endl;
	
	return 0;
}
