#include <bits/stdc++.h>

using namespace std;
#define BUF (100)
#define ll long long 

int n;
char s[BUF];
char c[258];

int main(void){
	cin >> s;

	int n= strlen(s);

	for(int i=0;i<n;i++){
		c[s[i]]=1;
	}

	for(char i='a';i<='z';i++){
		if(c[i]==0){
			s[n]=i;
			s[n+1]='\0';
			cout << s;
			cout << endl;
			return 0;
		}
	}


	for(int i=n-1;i>=0;i--){
		if(s[i]=='z'){
			c['z']=0;
			continue;
		}
		for(char j=s[i]+1;j<='z';j++){
			if(c[j]==0){
				s[i] = j;
				s[i + 1] = '\0';
				cout << s << endl;
				return 0;
			}
		}
		c[s[i]]=0;
	}

	cout << -1 << endl;
	return 0;
}
