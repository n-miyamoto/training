#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


int n;
char s[BUF];

int c[260];
int types = 0;

int main(void){
	cin >> s;

	n = strlen(s);
	for(int i=0;i<n;i++){
		if(c[s[i]]==0)types++;
		c[s[i]]++;
	}
	
	//cout << types;
	int ans;
	if(types==2){
		ans=1;
		for(char k='a';k<='z';k++){
			if(c[k]==1){
				ans=0;
			}
		}
	}else if(types==3){
		ans = 0;
		for(char k='a';k<='z';k++){
			if(c[k]>=2){
				ans=1;
			}
		}	
	}else if(types==4){
		ans = 1;
	}else {
		ans = 0;
	}

	if(ans == 1) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
