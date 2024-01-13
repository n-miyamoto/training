#include <iostream>
#include <vector>

constexpr int MAX = 47;

void showMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            if (elem < 0) {
                std::cout << "T ";
            } else {
                std::cout << elem << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    matrix[n / 2][n / 2] = -1; // Center

    char state = 'R'; // State is R, L, U, D
    int x = 0, y = 0;
    for (int i = 1; i < n * n; ++i) {
        matrix[y][x] = i;

        // Move
        switch (state) {
            case 'R': x++; break;
            case 'D': y++; break;
            case 'L': x--; break;
            case 'U': y--; break;
            default: break;
        }

        // Update state
        switch (state) {
            case 'R': if (x == n - 1 || matrix[y][x + 1] != 0) state = 'D'; break;
            case 'D': if (y == n - 1 || matrix[y + 1][x] != 0) state = 'L'; break;
            case 'L': if (x == 0 || matrix[y][x - 1] != 0) state = 'U'; break;
            case 'U': if (y == 0 || matrix[y - 1][x] != 0) state = 'R'; break;
            default: break;
        }
    }

    showMatrix(matrix);

    return 0;
}