#include <bits/stdc++.h>

using namespace std;

char get_rotate(const vector<string> &a, const int n, const int i, const int j, const int rotate_index){
	char ret;
	switch(rotate_index){
		case 0:
			ret = a[i][j];
			break;
		case 1:
			ret = a[n-j-1][i];
			break;
		case 2:
			ret = a[n-i-1][n-j-1];
			break;
		case 3:
			ret = a[j][n-i-1];
			break;
	}
	return ret;
}

int main(void){
	int n;
	cin >> n;

	vector<string> a(n);
	for(auto& l: a) cin >> l;
	auto b=a;

	for(int i=0;i<n/2;i++){
		auto rotate = (i+1)%4;

		for(int j=i;j<n-i;j++){
			b[i][j] = get_rotate(a, n, i, j, rotate);
			b[j][i] = get_rotate(a, n, j, i, rotate);
			b[n-i-1][n-j-1] = get_rotate(a, n, n-i-1, n-j-1, rotate);
			b[n-j-1][n-i-1] = get_rotate(a, n, n-j-1, n-i-1, rotate);
		}
	}

	for(auto& l: b) cout << l << endl;
	
	return 0;
}
