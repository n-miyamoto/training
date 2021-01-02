#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int N;
ll K;

vector<ll> A;
vector<double> Af;
vector<double> kf;
vector<ll> ki;

int main(void){
	ll sum = 0;
	//input
	cin >> N >> K;
	A.resize(N);
	for(auto &a : A){
		cin >> a;
		sum+= a;
	}

	//sort A
	sort(A.begin(), A.end());

	//cut coarsely
	kf.resize(N);
	ki.resize(N);
	Af.resize(N);
	ll K_rest = K;
	for(int i=0;i<N;i++){
		kf[i] = (double)A[i]/sum*(K+N);
		ki[i] = floor(kf[i]) - 1;
		K_rest -= ki[i];
		Af[i] = (double)A[i]/(ki[i]+1);
	}

	//sort again
	sort(Af.begin(), Af.end());

	cout << (ll)ceil(Af[N-K_rest-1]) << endl;

	return 0;
}
