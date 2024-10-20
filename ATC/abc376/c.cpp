#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n-1);

	for(auto& x: a)cin >> x;
	for(auto& x: b)cin >> x;

	std::sort(a.begin(), a.end(), std::greater<int>());
	std::sort(b.begin(), b.end(), std::greater<int>());

	int ans = -1;
	for(int i=0, j=0;i<n;i++, j++){
		if(a[i] <= b[j] ) continue;
		if(ans == -1){
			j--;
			ans = a[i];
		}
		else {
			ans = -1;
			break;
		}
	}

	cout << ans << endl;
	
	return 0;
}
