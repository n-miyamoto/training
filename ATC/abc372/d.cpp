#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n;
	cin >> n;

	vector<int> h(n);
	for(auto& x: h) cin >> x;

	if(n==1){
		cout << 0 << endl;
		return 0;
	}

	vector<int> ans(n, 0);
	stack<int> s;
	s.push(n-1);
	//cout << "push " << n-1 << endl;;
	ans[n-2] = s.size();

	for(int i=n-3;i>=0;i--){
		while(!s.empty() && h[s.top()] < h[i+1]){
			//cout << "pop " << s.top() << endl;;
			s.pop();
		}
		s.push(i+1);
		//cout << "push " << i+1 << endl;;

		ans[i] = s.size();
	}

	for(const auto & x : ans) cout << x << " ";
	cout << endl;
	
	return 0;
}
