#include <iostream>
#include <vector>
#include <utility>

using ll = long long;
using Position = std::pair<int, int>;

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<Position> positions;

    Position currentPosition = {1, 0};
    positions.push_back(currentPosition);

    for (int queryIndex = 0; queryIndex < q; ++queryIndex) {
        int commandType;
        std::cin >> commandType;

        if (commandType == 1) {
            char direction;
            std::cin >> direction;
            switch (direction) {
                case 'R': currentPosition.first++; break;
                case 'L': currentPosition.first--; break;
                case 'U': currentPosition.second++; break;
                case 'D': currentPosition.second--; break;
                default: /* Handle error */ break;
            }
            positions.push_back(currentPosition);
        } else if (commandType == 2) {
            int offset;
            std::cin >> offset;
            size_t length = positions.size();
            if (offset < length) {
                std::cout << positions[length - offset].first << " " << positions[length - offset].second << std::endl;
            } else {
                std::cout << offset - length + 1 << " 0" << std::endl;
            }
        } else {
            // Handle error
        }
    }

    return 0;
}