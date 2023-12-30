#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
    ll n, q;
    std::cin >> n >> q;
    std::vector<ll> ranges(n);
    std::vector<ll> queries(q);

    for (auto &range : ranges) {
        std::cin >> range;
    }

    for (auto &query : queries) {
        std::cin >> query;
    }

    std::sort(ranges.begin(), ranges.end());

    // Calculate prefix sum
    for (int i = 1; i < n; ++i) {
        ranges[i] += ranges[i - 1];
    }

    for (const auto &query : queries) {
        auto it = std::upper_bound(ranges.begin(), ranges.end(), query);
        std::cout << it - ranges.begin() << std::endl;
    }

    return 0;
}
