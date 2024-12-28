#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	vector<int> a(5);
	for(auto&& x : a ) cin >> x ;

	vector<pair<int, string>> v;

	for(int i=1;i<(1<<5);i++){
		int score = 0;
		string s;
		for(int j=0;j<5;j++){
			if(i>>j & 1){
				s.push_back('A'+(char)j);
				score += a[j];
			}
		}

		v.push_back(make_pair(score, s));
	}

	std::sort(v.begin(), v.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });

	for(const auto& [_, s] : v) cout << s << endl;
	
	return 0;
}
