#include <bits/stdc++.h>
using namespace std;

#define BUF (5005)
#define INF (1000000005)
#define ll long long 

int n;
char s[BUF];


int main(void){
	cin >> s;
	n = strlen(s);

	int ans=0;
	//search substr s[i]~s[j].
	for(int i=0;i<n-1;i++){
		int d=0;
		int cnt=0;
		
		for(int j=i;j<n;j++){

			if(s[j]=='(')d++;
			if(s[j]==')')d--;
			if(s[j]=='?'){
				if(d>0){
					d--;
					cnt++;
				}else{
					d++;
				}
			}
			while(d<0 && cnt){
				cnt--;
				d+=2;
			}
			if(d<0) break;
			if(d==0) ans++;			
		}
	}	

	cout << ans << endl;
	return 0;
}
