#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

ll minimizeBase(ll x) {
    ll k = 1;
    ll result = x;
    while (k * k <= x) {
        if (x % (k * k) == 0) {
            result = std::min(result, x / (k * k));
        }
        k++;
    }
    return result;
}

int main() {
    ll n;
    std::cin >> n;
    std::vector<ll> numbers(n);
    for (auto& num : numbers) {
        std::cin >> num;
    }

    std::vector<ll> simplifiedNumbers(n);
    for (ll i = 0; i < n; i++) {
        simplifiedNumbers[i] = minimizeBase(numbers[i]);
    }

    std::sort(simplifiedNumbers.begin(), simplifiedNumbers.end());

    ll pairsCount = 0;
    for (ll i = 0, count = 0; i < n; i++) {
        count++;
        if (i == n - 1 || simplifiedNumbers[i + 1] != simplifiedNumbers[i]) {
            pairsCount += count * (count - 1) / 2;
            count = 0;
        }
    }

    std::cout << pairsCount << std::endl;
    
    return 0;
}
