#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        int tmp;
        std::cin >> tmp;
        a[tmp] = i;
    }

    std::set<int> v;
    for (int i = 1; i <= k; ++i) { v.insert(a[i]); }

    auto calculate_distance = [&v]() -> int {
        return *v.rbegin() - *v.begin();
    };

    auto ans = calculate_distance();

    for (int i = 2; i + k - 1 <= n; ++i) {
        v.erase(a[i - 1]);
        v.insert(a[i + k - 1]);
        ans = std::min(ans, calculate_distance());
    }

    std::cout << ans << '\n';

    return 0;
}