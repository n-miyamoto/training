#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
using ll = long long;

static int N;
int p[BUF]; //parentp
int d[BUF]; //depth

void uf_init(int n){
    N=n;
    for(int i=0;i<n;i++) p[i]=i,d[i]=0;
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

void show_alld(void){
    cout << "depth  : ";
    for(int i=0;i<N;i++) cout << d[i] << " ";
    cout << "\n";
}
void show_allp(void){
    cout << "parent : ";
    for(int i=0;i<N;i++) cout << p[i] << " ";
    cout << "\n";
}
int show_parent(int i){
    return p[i];
}

int show_depth(int i){
    return d[i];
}

int main(void){
	ll n, m;
	cin >> n >> m;
	
	uf_init(n);

	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		unite(a, b);
	}

	vector<ll> group(BUF, 0);
	for(int i=1;i<=n;i++){
		group[find(i)]++;
	}


	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans += group[i]*(group[i]-1)/2;
	}
	ans-=m;

	cout << ans << endl;

	return 0;
}
