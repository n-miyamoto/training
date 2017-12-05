#include <bits/stdc++.h>
#include <mysegtree.h>

using namespace std;
#define BUF (100005)
#define ll long long 
#define INF (1000000006)


int n;	//=2^k
int segt[2*BUF];

/*
init  seg tree
     0
   /   \
  1     2
 / \   / \
3  4  5   6
a0 a1 a2 a3 

n=4;
segt[7]
*/
void init(int n_){
	n=1;
	while(n<n_) n*=2;
	for(int i=0;i<n*2;i++) segt[i]=INF;
}

/*
update a[i]=v
update all related nodes
*/
void update(int i, int v){
	int k=i+n-1;
	segt[k] = v;

	while(k>0){
		k=(k-1)/2;
		segt[k]=min(segt[k*2+1],segt[k*2+2]);
	}
}

/*
	require minimum value a[s] ~ a[e];
	call query(s,e,0,0,n) from other functions.
*/
int query(int s,int e, int k, int l, int r){
	//s~e is not in l~r
	if(s>=r || e<=l) return INF;
	if(s<=l && r<=e) return segt[k];
	else{
		int vl = query(s,e,k*2+1,l,(l+r)/2);
		int vr = query(s,e,k*2+2,(l+r)/2,r);
		return min(vl,vr);
	}
}

/*
	show the segtree for debug;
*/
int show_n(void){
	 return n;
}
int show_node(int a){
	return segt[a];
}
void show(void){
	int cnt = 1;
	int ind = 0;
	cout << "---segtree---\n";
	while(cnt<=n){
		for(int i=ind;i<ind+cnt;i++) if(segt[i]!=INF) cout << segt[i] << " ";
		else cout << " - ";
		ind+=cnt;
		cnt =2*cnt;
		cout << "\n";
	}
	cout << "------------\n";
	return ;
}


#ifdef MYTEST
int main(void){
	int root;
	cin >> root;
	init(root);
	cout << n;
	while(1){
		int i,a;
		char b;
		cin >> b >> i >> a;
		if(b=='u') update(i,a),show();
		if(b=='q') cout << query(i,a,0,0,n) << "!!!\n";
	}
	show();

	return 0;
}
#endif //MYTEST

