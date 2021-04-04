#include <bits/stdc++.h>

using namespace std;
#define BUF (1500005)
#define ll long long 

int N, M;
vector<int> a;
vector<int> v(BUF);
set<int> s;

int main(void){
	//input 
	cin >> N >> M;
	a.resize(N);
	for(int i=0;i<N;i++) cin >> a[i];


	for(int i=0;i<M;i++) v[a[i]]++;

	for(int i=0;i<BUF;i++){
		if(v[i]==0) s.insert(i);
	}

	int mexmin = *s.begin();
	for(int i=1;i< (N-M+1) ;i++){
		int out = a[i-1];
		int in  = a[i+M-1];

		v[in]++;
		v[out]--;
		if(v[in]==1) s.erase(in);
		if(v[out]==0) s.insert(out);

		if(mexmin > *s.begin()) mexmin = *s.begin();
	}

	std::cout << mexmin << endl;

	return 0;
}
