#include <bits/stdc++.h>
#include <mybit.h>

using namespace std;
#define BUF (100005)
#define ll long long 
#define INF (1000000006)


static int n;
int bit[BUF];

/*
init my minary indexed tree
-----------------------
-----------
-----      ------      
--   ---   ---   ---
 a0 a1 a2 a3 a4 a5 a6 a7 
*/
void bit_init(int n_){
	n=1;
	while(n<n_)n*=2;
}

/*
add v to a[i]
update all related nodes
*/
void add(int i, int v){
	while(i<=n){
		bit[i]+=v;
		i+=i&-i;
	}
}

/*
	require sum value a[0] ~ a[i];
*/
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

/*
	show the segtree for debug;
*/
int bit_show_n(void){
	 return n;
}
int bit_show_node(int a){
	return bit[a];
}
void bit_show(void){
	cout << "---Binary  indexed tree---\n";
	for(int i=1;i<=n;i++) cout << bit[i] << " \n";
	cout << "------------\n";
	return ;
}


#ifdef MYTEST
int main(void){
	int root;
	cin >> root;	init(root);
	cout << n;
	while(1){
		int i,a;
		char b;
		cin >> b >> i >> a;
		if(b=='a') add(i,a),show();
		if(b=='s') cout << sum(i) << "!!!\n";
	}
	show();

	return 0;
}
#endif //MYTEST

