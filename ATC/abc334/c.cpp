#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> elements(k);
    std::vector<ll> sumFromLeft(k / 2);

    for (auto &element : elements) {
        std::cin >> element;
    }

    for (int i = 0, j = 0; i < k - 1; i += 2, ++j) {
        sumFromLeft[j] = -elements[i] + elements[i + 1];
    }

    std::vector<ll> prefixSumLeft(k / 2 + 1, 0);
    for (int i = 1; i <= k / 2; ++i) {
        prefixSumLeft[i] = prefixSumLeft[i - 1] + sumFromLeft[i - 1];
    }

    // Even case
    if (k % 2 == 0) {
        std::cout << prefixSumLeft[k / 2] << std::endl;
        return 0;
    }

    // Odd case
    std::vector<ll> sumFromRight(k / 2);
    for (int i = k - 1, j = 0; i > 0; i -= 2, ++j) {
        sumFromRight[j] = -elements[i - 1] + elements[i];
    }

    std::vector<ll> prefixSumRight(k / 2 + 1, 0);
    for (int i = 1; i <= k / 2; ++i) {
        prefixSumRight[i] = prefixSumRight[i - 1] + sumFromRight[i - 1];
    }

    ll answer = 200000LL * 200000LL;
    for (int i = 0; i <= k / 2; ++i) {
        ll temp = prefixSumLeft[i] + prefixSumRight[k / 2 - i];
        answer = std::min(answer, temp);
    }

    std::cout << answer << std::endl; 

    return 0;
}