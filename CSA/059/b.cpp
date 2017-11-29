#include <bits/stdc++.h>
using namespace std;

#define BUF (1000)
#define INF (1000000005)
#define ll long long 

ll g1,g2,p1,p2;
char s[BUF];

int main(void){
	cin >> g1 >> p1 >> g2 >> p2;
	
	ll a1=g1*p1;
	while(a1%100!=0){
		a1++;
	}
	cout << a1;
	a1/=100;

	ll a2=g2*(p2+1);
	a2--;
	while(a2%100!=0){
		a2--;
	}
	cout << a2;
	a2/=100;

	
	cout << a2-a1 << endl;	

	return 0;
}
