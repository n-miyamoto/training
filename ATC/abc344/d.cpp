#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define INF (10000)

int main() {
    string t;
    int n;
    cin >> t >> n;

    vector<vector<int>> dp(n+1, vector<int>(t.size()+1, INF));
    dp[0][0] = 0; // Base case: 0 groups needed to form an empty string.

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        vector<string> s(a);
        for(string &x: s) {
            cin >> x;
        }

        // Copy previous state.
        for(size_t j = 0; j <= t.size(); j++) {
            dp[i][j] = dp[i-1][j];
        }

        // Attempt to extend the transformation with strings from the current group.
        for(size_t j = 0; j < t.size(); j++) {
            if(dp[i-1][j] < INF) {
                for(const string &x: s) {
                    if(t.substr(j, x.size()) == x) {
                        dp[i][j + x.size()] = min(dp[i][j + x.size()], dp[i-1][j] + 1);
                    }
                }
            }
        }
    }

    if(dp[n][t.size()] < INF) {
        cout << dp[n][t.size()] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}