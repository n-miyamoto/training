#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    constexpr long long MAX_VALUE = 500005;
    using ll = long long;

    ll n, q;
    std::cin >> n >> q;

    std::vector<ll> values(n + 1, 0);
    std::vector<ll> histogram(MAX_VALUE, 0);
    std::set<ll> mex;

    // Reading and initializing values and histogram
    for (ll i = 1; i <= n; ++i) {
        std::cin >> values[i];
        if (values[i] < MAX_VALUE) {
            histogram[values[i]]++;
        }
    }

    // Initializing mex set
    for (ll i = 0; i < MAX_VALUE; ++i) {
        if (histogram[i] == 0) {
            mex.insert(i);
        }
    }

    // Processing queries
    for (ll k = 0; k < q; ++k) {
        ll index, newValue;
        std::cin >> index >> newValue;

        ll oldValue = values[index];
        values[index] = newValue;

        // Update histogram for the old value
        if (oldValue < MAX_VALUE) {
            if (--histogram[oldValue] == 0) {
                mex.insert(oldValue);
            }
        }

        // Update histogram for the new value
        if (newValue < MAX_VALUE) {
            if (++histogram[newValue] == 1) {
                mex.erase(newValue);
            }
        }

        std::cout << *mex.begin() << std::endl;
    }

    return 0;
}