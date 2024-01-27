#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    std::vector<int> left(n, 0);
    left[0] = 1;
    for (int i = 1; i < n; i++) {
        left[i] = (heights[i] > left[i - 1]) ? left[i - 1] + 1 : heights[i];
    }

    std::vector<int> right(n, 0);
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        right[i] = (heights[i] > right[i + 1]) ? right[i + 1] + 1 : heights[i];
    }

    int maxVisible = 0;
    for (int i = 0; i < n; i++) {
        maxVisible = std::max(maxVisible, std::min(left[i], right[i]));
    }

    std::cout << maxVisible << std::endl;

    return 0;
}