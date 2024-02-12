#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
    ll n;
    std::cin >> n;
    n--;

    std::vector<ll> ans;

    while (n != 0) {
        ans.push_back(n % 5);
        n /= 5;
    }

    if (ans.empty()) { 
        std::cout << 0 << std::endl;
        return 0;
    }

    std::reverse(ans.begin(), ans.end());
    for (const auto &x : ans) {
        std::cout << 2 * x;
    }
    std::cout << std::endl;

    return 0;
}