#include <bits/stdc++.h>
#include <mysqdiv.h>

using namespace std;
#define BUF (100005)
#define ll long long 
#define INF (1000000006)


static int n;
int a[BUF];
int bucket[BUF];

/*
separate to bucket
bucket  |   b0   |   b1   |   b2   |	
array    a0 a1 a2 a3 a4 a5 a6 a7 
*/
void sqdiv_init(int n_){
	for(int i=0;i<n_;i++)a[i]=INF;
	n=0;
	while(n*n<n_)n++;
	for(int i=0;i<=n;i++)bucket[i]=INF;
	/*
	for(int i=0;i<n;i++){
		for(int j=i*n;j<i*n+n;j++){
			bucket[i]=min(bucket[i],a[j]);
		}
	}
	*/
}

//update()
void update_bkt(int i, int v){
	a[i]=v;
	bucket[i/n]=v;
	for(int k=i/n*n;k<i/n*n+n;k++)bucket[i/n] = min(bucket[i/n],a[k]);
}

//query()
int req(int s, int e){
	int l=a[s];int c=INF;int r=a[e];
	int ans = INF;
	if(s/n==e/n){
		for(int i=s;i<=e;i++)ans = min(ans,a[i]);
		return ans;
	}

	for(int i=s;i<n*(s/n+1);i++) l=min(l,a[i]);
	for(int i=s/n+1;i<e/n;i++) c=min(c,bucket[i]);	
	for(int i=e;i>=e/n*n;i--) r=min(r,a[i]);

	ans=min(l,r);ans=min(ans,c);
	return ans;
}

int sqdiv_show_n(void){
	 return n;
}

int sqdiv_show_node(int a){
	return bucket[a];
}
void sqdiv_show(void){
	cout << "---show all vals------\n";
	for(int i=0;i<n*n;i++) cout << a[i] << " ";
	cout << "\n---show all buckets--\n";
	for(int i=0;i<n;i++) cout << bucket[i] << " ";
	cout << "\n------------\n";
	return ;
}


#ifdef MYTEST
int main(void){
	int root;
	cin >> root;	sqrtdiv_init(root);
	cout << n;
	while(1){
		int i,a;
		char b;
		cin >> b >> i >> a;
		if(b=='u') update_bkt(i,a),sqrtdiv_show();
		if(b=='r') cout << req(i,a) << "!!!\n";
	}
	sqrtdiv_show();

	return 0;
}
#endif //MYTEST

