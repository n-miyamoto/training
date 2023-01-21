#include <bits/stdc++.h>

using namespace std;
#define BUF (30)
#define ll long long 

int n;
bool check[BUF];
int cnt[BUF];

int main(void){
	string s;
	cin >> s;
	n = s.length();

	for(int i=0;i<n;i++){
		if(s[i]=='('){
			for(char c = 'a'; c<= 'z';c++){
				if(check[c-'a']){
					cnt[c-'a']++;
				}
			}
		}else if(s[i]==')'){
			for(char c = 'a'; c<= 'z';c++){
				if(check[c-'a']){
					cnt[c-'a']--;
					if(cnt[c-'a']<0){
						check[c-'a'] = false;
						cnt[c-'a']=0;
					}
				}
			}
		}else{
			if(check[s[i]-'a']){
				cout << "No" << endl;
				return 0;
			}else{
				check[s[i]-'a'] = true;
				cnt[s[i] -'a']=0;
			}
		}
	}

	cout << "Yes" << endl;

	return 0;
}
