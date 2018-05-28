#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
int m;


int N;
int p[BUF]; //parentp
int d[BUF]; //depth
int v[BUF];
pair<int,int> pr[BUF];

void uf_init(int n_){
    N=n_;
    for(int i=1;i<=n_;i++) p[i]=i,d[i]=0;
}

int find(int x){
    if(p[x]==x) return x;
    else{
        p[x] = find(p[x]);
        return p[x];
    }
}

void unite(int x, int y){
    x=find(x);
    y=find(y);

    if(x==y)return;

    if(d[x]<d[y]){
        p[x]=y;
    }else if(d[x]>d[y]){
        p[y]=x;
    }else{
        p[y]=x;
        d[x]++;
    }
}

bool same(int x, int y){
    return find(x)==find(y);
}


int main(void){
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> v[i];
	for(int i=1;i<=m;++i) cin >> pr[i].first >> pr[i].second;

	uf_init(n);
	for(int i=1;i<=m;++i){
		unite(pr[i].first, pr[i].second);
	}

	int ans = 0;

	for(int i=1;i<=n;++i){
		if(same(i,v[i])) ans++;
	}	

	cout << ans << endl;


	return 0;
}
