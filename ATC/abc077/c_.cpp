#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)

long long  N;
long long  A[BUF],B[BUF],C[BUF];


int main(void){
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
	for(int i=0;i<N;i++) cin >> B[i];
	for(int i=0;i<N;i++) cin >> C[i];

	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);
	long long ans = 0;

	for(int i=0;i<N;i++){
		int anum,cnum;
		long long *ite = lower_bound(A, A+N, B[i]);
		int index = ite - A;
		if(index==N) anum = N;
		else anum = ite - A ;
		
		ite = upper_bound(C,C+N, B[i]);
		index = ite - C;
		if(index==N) cnum = N;
		else cnum = ite - C;
	//	cout << anum << N-cnum  << "\n";
		ans += (long long)anum*(long long )(N-cnum);
	}
	
	cout << ans << endl;
	return 0;
}

