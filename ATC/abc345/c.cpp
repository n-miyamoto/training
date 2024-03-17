#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    vector<ll> hist(26, 0);
    for (const auto &c : s) {
        hist[c - 'a']++;
    }

    ll ans = 0;
    // Calculate combinations of different characters
    for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            ans += hist[i] * hist[j];
        }
    }
    
    // Check for characters that appear at least twice and can form pairs with themselves
    bool sameString = any_of(hist.begin(), hist.end(), [](ll count){ return count >= 2; });
    if (sameString) ans++;

    cout << ans << endl;

    return 0;
}