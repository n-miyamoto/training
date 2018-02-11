#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define BUF (100005)
#define INF (1000000005)
typedef long long ll;


int N,Q,K;
int a[BUF];
int b[BUF];
ll c[BUF];

typedef struct {
	int a;
	int b;
	ll  c;
} LIST;

typedef struct {
	int to;
	ll cst;
} EDGE;

typedef struct {
	int x;
	int y;
} QUERY;

LIST l[2*BUF];
QUERY q[BUF];
vector<EDGE> v[BUF];

void input(void){
	cin >> N;
	for(int i=0; i<N-1;i++){
		int a,b,c;
		cin >> a >> b >> c;
		EDGE tmp;
		tmp.to = b;
		tmp.cst =c;
		v[a].push_back(tmp);
		tmp.to = a;
		v[b].push_back(tmp);
	}
	cin >> Q >> K;

	for(int i=0;i<Q;i++) cin >> q[i].x >> q[i].y ;
}

ll  cs[BUF];

void dfs(int k,ll p){
	if(cs[k]!=INF) return ;
	cs[k] = p;

	if(v[k].size()==0){
		return;
	}
	for (vector<EDGE>::const_iterator i = v[k].begin ();i != v[k].end (); i++){ 
	//	cout << i->to << " " << i->cst << endl;
		dfs( i->to , p+ (ll)i->cst );
	}
	return;	
}

int main(void){
	input();

	for(int i=0;i<=N;i++) cs[i]=INF;

	dfs(K,0);

//	for(int i=1;i<=N;i++) cout << cs[i] << endl;

	for(int i=0;i<Q;i++){
		cout << cs[q[i].x]+cs[q[i].y] << endl;
	}

	return 0;
}