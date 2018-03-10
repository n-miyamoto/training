#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

char s[BUF];
char lft[BUF];
char rgt[BUF];

enum {
	L=0,
	M,
	R
};

int v[257];
int t[257];
int l[BUF];
int p[BUF];
ll ans;




static int n;
ll bit[BUF];

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
void add(int i, ll v){
    while(i<=n){
        bit[i]+=v;
        i+=i&-i;
    }
}

/*
    require sum value a[0] ~ a[i];
*/
ll sum(int i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}


int main(void){
	cin >>s;
	n = strlen(s);

	//count 
	for(int i=0;i<n;i++) v[s[i]]++;

	//find odd
	int odd_cnt = 0;
	char odd = 0;
	int odd_index = 0;
	for(int i='a';i<='z';i++) {
		if(v[i]%2==1){
			odd_cnt++;
			odd = i; 
		}
	}
	//finish.
	if(odd_cnt>1)
	{ 
		cout << -1 << endl;
		return 0;
	}
	
	//label l,m,r
	for(int i=0;i<n;i++){
		t[s[i]]++;
		if(2*t[s[i]]<=v[s[i]]) l[i]=L;
		else l[i]=R;
		if(s[i]==odd && t[s[i]]==(v[odd]+1)/2){
			l[i] = M;
			if(l[i]==M) odd_index = i;
		}
	}


//debug
/*
	for(int i=0;i<n;i++){
		cout << l[i];
	}
*/

//find first R
	int f_M=0;
	for(int i=0;i<n;i++){
		if(l[i]==R){
			f_M=i;
			break;
		}
	}

//cout << f_M << odd_index;
	if(n%2==1 && odd_index < f_M){
		for(int i=odd_index;i<n;i++){
			if(l[i]==L) ans++;
		}
	}else if (n%2==1 && odd_index>f_M){
		for(int i=0;i<odd_index;i++){
			if(l[i]==R) ans++;
		}
	}	

//cout << ans;
	//count 
	int ini = f_M;
	for(int i=ini;i<n;i++){
		if(l[i]==L){
			ans+=i-f_M;
			f_M++;
		}
	}



	//make L,R string
	int li=0,ri=0;
	for(int i=0;i<n;i++){
		if(l[i]==L) {
			lft[li] =(s[i]);
			li++;
		}
		if(l[i]==R){
			rgt[ri]  =(s[i]);
			ri++;
		}
	}



	queue<int> A[257];

	for(int i=0;i<n/2;i++){
		char c = lft[i];
		A[c].push(i);
	}



	for(int i=n/2-1;i>=0;i--){
		char c = rgt[i];
		p[i] = n/2 - A[c].front();
		A[c].pop();
//		cout << p[i];
	}

	int N = n/2;

	bit_init(N+2);
//	cout << n;

	for(int i=0;i<N;i++){
		ans+=(ll)(i-sum(p[i]));
		add(p[i],1);
	}

	cout << ans << endl;
	return 0;
}
