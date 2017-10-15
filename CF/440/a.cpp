#include <bits/stdc++.h>
using namespace std;
#define BUF (11)

int n,m;
int a[BUF],b[BUF];

int main(void){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++) cin >> b[i];

	sort(a+1,a+n+1);
	sort(b+1,b+m+1);

	int min = 9;
	int f=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]){
				f=1;
				if(min>a[i])min = a[i];
			}
		}
	}

	//cout << b[1] << a[1];

	if(f==1){ 
		cout << min << endl;
		return 0;
	}


	if(a[1]>b[1]){
		cout << b[1]*10+a[1] << endl;
	}else{
		cout << a[1]*10+b[1] << endl;
	}
		
	return 0;
}
