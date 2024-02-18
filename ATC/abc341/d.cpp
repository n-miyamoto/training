#include <iostream>
#include <algorithm>
#include <numeric>

using ll = long long;

ll lcm(ll a, ll b) {
    return a / std::gcd(a, b) * b;
}

int main() {
    ll n, m, k;
    std::cin >> n >> m >> k;

    // Ensure n < m by swapping
    if (n > m) {
        std::swap(n, m);
    }

    const ll l = lcm(n, m);
    const ll countN = l / n - 1;
    const ll countM = l / m - 1;
    const ll countNM = countN + countM;

    const ll blockNum = (k + countNM - 1) / countNM;
    const ll kMod = (k + countNM - 1) % countNM + 1;

    for (int i = 1, j = 1, count = 1; i <= countN; i++, count++) {
        ll current = n * i;

        if (count == kMod) {
            std::cout << (blockNum - 1) * l + current << std::endl;
            return 0;
        }

        if (current < j * m && j * m < (current + n)) {
            count++;
            current = m * j;
            j++;
        }
        if (count == kMod) {
            std::cout << (blockNum - 1) * l + current << std::endl;
            return 0;
        }
    }

    return 0;
}