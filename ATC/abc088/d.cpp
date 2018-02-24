#include <bits/stdc++.h>

using namespace std;
#define BUF (55)
#define ll long long 

int h,w;
char s[BUF][BUF];

typedef struct {
	int first;
	int second;
	int num;
}P;

queue<P> q;

int main(void){
	cin >> h >> w;
	int count=0;

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin >> s[i][j] ;
			if(s[i][j]=='.')count++;
		}
	}

	for(int i=0;i<BUF;i++) s[0][i]='#';
	for(int i=0;i<BUF;i++) s[i][0]='#';
	for(int i=0;i<BUF;i++) s[i][w+1]='#';
	for(int i=0;i<BUF;i++) s[h+1][i]='#';

	P p;
	p.first = 1;
	p.second = 1;
	p.num=1;

	s[p.first][p.second]='#';
	
	q.push(p);
	int f=0;
	while(!q.empty()){
		p=q.front();
		q.pop();
		if(p.first==h && p.second==w){
			f=p.num;
			break;
		}

	    if( s[p.first  ][p.second-1]=='.' ){
			s[p.first  ][p.second-1]= '#';
			q.push({p.first  ,p.second-1,p.num+1});
		}
	    if( s[p.first-1][p.second  ]=='.' ){	
			s[p.first-1][p.second]= '#';
			q.push({p.first-1,p.second  ,p.num+1});
		}
	    if( s[p.first  ][p.second+1]=='.' ){
			s[p.first  ][p.second+1]= '#';
			q.push({p.first  ,p.second+1,p.num+1});
		}
	    if( s[p.first+1][p.second  ]=='.' ){
			s[p.first+1][p.second  ]= '#';
			q.push({p.first+1,p.second  ,p.num+1});
		}
	}

	if(f==0){
		cout << "-1" << endl;
		return 0 ;
	}
	cout << count-f << endl;

	return 0;
}
