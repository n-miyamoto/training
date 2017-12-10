#include <bits/stdc++.h>
#include <myunionfind.h>

using namespace std;
#define BUF (100005)
#define ll long long 
#define INF (1000000006)

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

#ifdef MYTEST
int main(void){

	uf_init(10);
	
	char b;
	int i,a;
	while(1){
		cin >> b >>i >> a;
		if(b=='u') unite(i,a);
		if(b=='f') find(i);
		if(b=='s') same(i,a);
		show_allp();
		show_alld();
	}


	return 0;
}
#endif //MYTEST

