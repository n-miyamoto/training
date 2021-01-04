#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
vector<int> r1;
vector<int> r2;

int main(void){
	cin >> n;
	for (int i=0;i<n;i++){
		int x ,y;
		cin >> x >> y;
		r1.push_back(x+y);
		r2.push_back(x-y);
	}

	sort(r1.begin(), r1.end());
	sort(r2.begin(), r2.end());

	int ans1 = abs(r1[0] - r1[n-1]);
	int ans2 = abs(r2[0] - r2[n-1]);

	cout << max(ans1, ans2) << endl;

	return 0;
}

