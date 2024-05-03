#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


int main(void){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& x : a) cin >> x;

	list<int> l;
	for(const auto& x:a ){
		l.push_back(x);

		while(l.size()>1){
			auto ite = std::prev(l.end());
			auto ite_prev = std::prev(ite);;
			if(*ite!=*ite_prev) break;
			(*ite_prev)++;
			l.pop_back();
		}
	}

	cout << l.size() << endl;
	
	return 0;
}
