#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll n;
int v[30];
int main(void){
	cin >> n;
	ll tmp = n;
	ll cnt=0;
	int ans = 0;
	while(tmp!= 0){
		v[cnt]=tmp%10;
		tmp=tmp/10;
		cnt++;
	}

	//1999とか29999とか
	int f = 0;
	for (int j = 0; j < cnt - 1; j++)
	{
		if (v[j] != 9)
			f = 1;
	}
	if (f == 0)
	{
		ans = v[cnt-1]+9*(cnt-1);		
		cout << ans << endl;
		//cout << n << endl;
		return 0;
	}
	int i;

	//find first 9
	for(i=cnt-1;i>=0;i--){
		if(v[i]!=9)break;
	}
	//first num is not 9
	if(cnt==i+1){
		ans = v[cnt-1]-1+9*(cnt-1);
		cout << ans << endl;
		//if(v[cnt-1]!=1) cout << v[cnt-1]-1;
		//for(int j=0;j<cnt-1;j++) cout << 9;
		return 0;
	}

	//find 99... k 
	ans = 9*(cnt)-1;
	cout << ans << endl;
//	for(int j=0;j<cnt;j++){
		
//		if(j==i+1) cout << 8;
//		else cout << 9;
	
	cout << endl;


	return 0;
}
