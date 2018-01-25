#include <bits/stdc++.h>
using namespace std;

#define BUF (1000)
#define INF (1000000005)
#define ll long long 

int n,m;
int a[BUF];
int b[BUF];

int main(void){
	cin >> n>> m;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	sort(a,a+n,greater<int>() );
	sort(b,b+m,greater<int>() );

	int num = min(n,m);
	int aw=0;
	int bw=0;
	for(int i=0;i<num;i++){
		if(a[i]>b[i])aw++;
		else bw++;
	}

	cout << aw << " " << bw << endl;
	return 0;
}

