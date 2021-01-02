#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

int N,M;
vector<ll> H;
vector<ll> W;

int main(void){

	//input
	cin >> N >> M;
	H.resize(N);
	W.resize(M);
	for(int i=0;i<N;i++){
		cin >> H[i];
	}
	for(int i=0;i<M;i++){
		cin >> W[i];
	}

	//sort H
	sort(H.begin(), H.end());	

	// accumurate from left
	vector<ll> sum_from_left(N);
	sum_from_left[0] = H[1] - H[0];
	for(int i=2;i<=N-3;i+=2){
		sum_from_left[i] = sum_from_left [i-2] + H[i+1] - H[i];
	}

	// accumurate from right
	vector<ll> sum_from_right(N);
	sum_from_right[N-1] = H[N-1] - H[N-2];
	for(int i=N-3;i>=2;i-=2){
		sum_from_right[i] = sum_from_right [i+2] + H[i] - H[i-1];
	}

	// find lower value
	ll ans = -1;
	for(auto x : W){
		auto it = lower_bound(H.begin(), H.end(), x);
		int i = it - H.begin();
		ll tmp;
		ll left, right;
		if(i%2==1){	// odd case
			left = (i<3) ? 0 : sum_from_left[i-3]; 
			right = (i>N-2) ? 0 : sum_from_right[i+1];
			tmp = left + x-H[i-1] + right;
		}
		else{	// even case
			left = (i<2) ? 0 : sum_from_left[i-2]; 
			right = (i>N-3) ? 0 : sum_from_right[i+2];
			tmp = left + H[i]-x + right;
		}
		//update answer
		if(ans<0 || tmp<ans) ans = tmp;
	} 

	cout << ans << endl;

	return 0;
}
