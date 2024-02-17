#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#include <string>

using ll = long long;
using Position = std::pair<int, int>;
using PositionPair = std::pair<Position, Position>;

bool isSamePosition(const PositionPair& pp) {
    return pp.first == pp.second;
}

unsigned int encode(const PositionPair& pp) {
    return pp.first.first + (pp.first.second << 8) + (pp.second.first << 16) + (pp.second.second << 24);
}

PositionPair move(const std::vector<std::string>& mat, const PositionPair& pp, char dir) {
    Position nextP0 = pp.first;
    Position nextP1 = pp.second;

    switch (dir) {
        case 'U': nextP0.second++; nextP1.second++; break;
        case 'R': nextP0.first++; nextP1.first++; break;
        case 'D': nextP0.second--; nextP1.second--; break;
        case 'L': nextP0.first--; nextP1.first--; break;
    }

    int n = mat.size();
    auto isBlocked = [&](const Position& p) {
        return p.first < 0 || p.second < 0 || p.first >= n || p.second >= n || mat[p.second][p.first] == '#';
    };

    if (isBlocked(nextP0)) nextP0 = pp.first;
    if (isBlocked(nextP1)) nextP1 = pp.second;

    return {nextP0, nextP1};
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> matrix(n);
    for (auto& line : matrix) {
        std::cin >> line;
    }

    std::vector<Position> positions;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 'P') {
                positions.emplace_back(j, i);
            }
        }
    }

    PositionPair startPosition = {positions[0], positions[1]};
    std::queue<std::pair<int, PositionPair>> queue;
    queue.push({0, startPosition});

    std::unordered_set<unsigned int> visited;
    visited.insert(encode(startPosition));

    while (!queue.empty()) {
        auto [count, current] = queue.front();
        queue.pop();

        if (isSamePosition(current)) {
            std::cout << count << std::endl;
            return 0;
        }

        for (char dir : {'U', 'R', 'D', 'L'}) {
            PositionPair next = move(matrix, current, dir);
            unsigned int encodedNext = encode(next);
            if (!visited.contains(encodedNext)) {
                queue.push({count + 1, next});
                visited.insert(encodedNext);
            }
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}
