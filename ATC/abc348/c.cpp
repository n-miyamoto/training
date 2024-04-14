#include <bits/stdc++.h>

using namespace std;


int main(void){
	int n;
	cin >> n;

	unordered_map<int, int> um;

	for(int i=0;i<n;i++){
		int a, c;
		cin >> a >> c;

        auto [it, inserted] = um.try_emplace(c, a);
        if (!inserted) it->second = std::min(it->second, a);
	}

	auto max_it = std::max_element(um.begin(), um.end(), 
                                   [](const auto& left, const auto& right) {
                                       return left.second < right.second;
                                   });

	cout << max_it->second << endl;
	
	return 0;
}
