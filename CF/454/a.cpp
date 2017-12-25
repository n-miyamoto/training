#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


int m;
int v[3];

int main(void){
	cin >> v[0] >> v[1] >> v[2];

	cin >> m;
/*
	int c=v[2];

	if(m>2*c || m<v[2]){
		cout << -1 << endl;
		return 0;
	}
*/
	int ans = -1;
	for(int i=1;i<2*v[1];i++){
	//	cout << i;
		if(i>=v[2] && i<=(2*v[2]) && i>=m && i<=(2*m) ){
			ans = i;
			break;
		}
	}

	if(v[1]>m){
	}else{
		ans = -1;
	}

	if(ans == -1){
		cout << ans;
		return 0;
	}

	cout <<2*v[0]<< "\n";
	cout <<2*v[1]<< "\n";
	cout << ans  << " \n";

	return 0;
}
