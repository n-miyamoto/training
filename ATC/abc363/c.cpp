#include <bits/stdc++.h>

using namespace std;


bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

bool hasPalindromeSubstring(const string& s, int m) {
    int n = s.size();
    for (int i = 0; i <= n - m; ++i) {
        string substring = s.substr(i, m);
        if (isPalindrome(substring)) {
            return true;
        }
    }
    return false;
}

int main(void){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	sort(s.begin(), s.end());

	int ans=0;
    do {
		if(!hasPalindromeSubstring(s, k)) ans++;
    } while (next_permutation(s.begin(), s.end()));

	cout << ans << endl;

	return 0;
}
