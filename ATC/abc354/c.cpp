#include <bits/stdc++.h>

using namespace std;

struct card {
	int a;
	int c;
	int i;
};

int main(void){
	int n;
	cin >> n;

	vector<card> cards(n);

	for(int i=0;i<n;i++) cards[i].i = i+1;
	for(auto &c : cards) cin >> c.a >> c.c;

	sort(cards.begin(), cards.end(), [](const card &a, const card &b) {
        return a.a < b.a;
	});

	vector<card> ans;
	int min = 1000000001;
	for(int i=n-1;i>=0;i--){
		if(cards[i].c < min){
			ans.push_back(cards[i]);
			min = cards[i].c;
		}
	}

	sort(ans.begin(), ans.end(), [](const card &a, const card &b) {
        return a.i < b.i;
	});


	cout << ans.size() << endl;
	for(const auto x : ans) cout << x.i << " ";
	cout << endl;

	return 0;
}
