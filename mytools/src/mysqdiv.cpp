#include <bits/stdc++.h>
//#include <mysqrtdiv.h>

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
void sqrtdiv_init(int n_){
	n=0;
	while(n*n<n_)n++;
	for(int i=0;i<n;i++)bucket[i]=INF;
	for(int i=0;i<n;i++){
		for(int j=i*n;j<i*n+n;j++){
			bucket[i]=min(bucket[i],a[j]);
		}
	}
}

//update()
void update(int i, int v){
	a[i]=v;
	bucket[i/n]=v;
	for(int k=i/n*n;k<i/n*n+n;k++)bucket[i/n] = min(bucket[i/n],a[k]);
}

//query()
int query(int s, int e){
	int l=INF;int c=INF;int r=INF;

	for(int i=s;i%n!=0;i++) l=min(l,a[i]);
	for(int i=s/n+1;i<e/n;i++) c=min(c,bucket[i]);	
	for(int i=e;i%n!=0;i--) r=min(r,a[i]);

	int ans;
	ans=min(l,r);ans=min(ans,c);
	return ans;
}

int sqrtdiv_show_n(void){
	 return n;
}

int sqrtdiv_show_node(int a){
	return bucket[a];
}
void sqrtdiv_show(void){
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
		if(b=='u') update(i,a),sqrtdiv_show();
		if(b=='q') cout << query(i,a) << "!!!\n";
	}
	sqrtdiv_show();

	return 0;
}
#endif //MYTEST

