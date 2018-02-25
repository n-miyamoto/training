#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


int n,k;
char s[BUF];
char st[BUF];
char ans[BUF];
int v[300];

int main(void){
	cin >> n >> k;
	cin >> s;

	for(int i=0;i<n;i++)st[i]=s[i];
	for(int i=0;i<n;i++)ans[i]=s[i];
	sort(st,st+n);
	for(int i=0;i<n;i++)v[st[i]]=i;

	//k>n case. just add smallest char.
	if(k>n){
		for(int i=n;i<k;i++)s[i]=st[0];
		cout << s << endl;
		return 0;
	}


	int tmp = k-1;
	ans[k]='\0';
	while(v[ans[tmp]] == n-1){
		tmp--;
		if(tmp==0) break;
	}


	int j=v[ans[tmp]]+1;
	ans[tmp]=st[j];
	for(int i=tmp+1;i<k;i++){
		ans[i]=st[0];
	}

	cout << ans << endl;

	return 0;
}
