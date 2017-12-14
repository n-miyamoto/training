#include <bits/stdc++.h>
using namespace std;

#define BUF (200005)
#define INF (1000000005)
#define ll long long 

int n;
int N,M;
int L[BUF];
int R[BUF];
int v[BUF];
int s[BUF];
int e[BUF];
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
    for(int i=0;i<=n;i++)bit[i]=0;
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


int main(void){
	cin >> N >> M;

	bit_init(N);

	for(int i=1;i<=M;i++){
		int l,r;
		cin >> l >> r;
		L[i]=l;
		R[i]=r;
		s[l]++;
		e[r]++;
	}

	int cnt = 0;
	int sm = 0;
	for(int i=1;i<=N;i++){
		cnt+=s[i];
		v[i]=cnt;
		cnt-=e[i];
		if(v[i]>0)sm++;
		if(v[i]==1)add(i,1);
	}

	//for(int i=1;i<=N;i++) cout << v[i];
	//for(int i=1;i<=N;i++) cout << bit[i];

	
	
	for(int i=1;i<=M;i++){
		int tmp;
		tmp = sum(R[i])-sum(L[i]-1);
		cout << N-sm+tmp << "\n";
	}


	return 0;
}
