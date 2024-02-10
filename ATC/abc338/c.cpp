#include <iostream>
#include <vector>
#include <algorithm>

constexpr int N_MAX = 1000005;
using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> q(n), a(n), b(n);

    for (auto& x : q) std::cin >> x;
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;

    int maxCount = 0;
    for (int i = 0; i < N_MAX; i++) {
        bool isNegative = false;
        for (int j = 0; j < n; j++) {
            if (i != 0) q[j] -= a[j];
            if (q[j] < 0) isNegative = true;
        }
        if (isNegative) break;

        int minBCount = N_MAX;
        for (int j = 0; j < n; j++) {
            if (b[j] != 0) {
                minBCount = std::min(minBCount, q[j] / b[j]);
            }
        }
        maxCount = std::max(maxCount, i + minBCount);
    }

    std::cout << maxCount << std::endl;

    return 0;
}