#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)

int N;
vector<int> A,B,C;

int main(void){
	cin >> N;
	for(int i=0;i<N;i++) {
		int a ;
		cin >> a;
		A.push_back(a);
	}		
	for(int i=0;i<N;i++) {
		int a ;
		cin >> a;
		B.push_back(a);
	}		

	for(int i=0;i<N;i++) {
		int a ;
		cin >> a;
		C.push_back(a);
	}		

	long long ans = 0;

	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());



	for(int i=0;i<B.size();i++){
		int anum,cnum;
		vector<int>::iterator ite = lower_bound(A.begin(), A.end(), B[i]);
		int index = ite - A.begin();
		if(index==A.size()) anum = A.size();
		else anum = ite - A.begin() ;
		
		ite = upper_bound(C.begin(),C.end(), B[i]);
		index = ite - C.begin();
		if(index==C.size()) cnum = C.size();
		else cnum = ite - C.begin();
	//	cout << anum << N-cnum  << "\n";
		ans += anum*(C.size()-cnum);
	}
	
	cout << ans << endl;
	return 0;
}

