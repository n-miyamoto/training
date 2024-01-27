#include <iostream>
#include <algorithm>
#include <vector>

constexpr int N_MAX = 200005;
using ll = long long;

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> types(n), indexes(n);
    std::vector<int> potions(N_MAX, 0), monsters(N_MAX, 0), picks(N_MAX, 0);

    bool defeated = false;
    for (int i = 0; i < n; i++) {
        std::cin >> types[i] >> indexes[i];
        int idx = indexes[i];

        if (types[i] == 1) {
            potions[idx]++;
        } else if (types[i] == 2) {
            potions[idx]--;
            if (potions[idx] < 0) {
                defeated = true;
            }
        } else {
            std::cout << "err";
        }
    }

    if (defeated) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int k = 0, kMax = 0;
    for (int i = n - 1; i >= 0; i--) {
        int idx = indexes[i];
        if (types[i] == 1) {
            if (monsters[idx] > 0) {
                monsters[idx]--;
                k--;
                picks[i] = 1;
            }
        } else if (types[i] == 2) {
            monsters[idx]++;
            k++;
            kMax = std::max(kMax, k);
        } else {
            std::cout << "err";
        }
    }

    std::cout << kMax << std::endl;
    for (int i = 0; i < n; i++) {
        if (types[i] == 1) {
            std::cout << picks[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
