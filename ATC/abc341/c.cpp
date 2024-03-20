#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    string t;
    cin >> t;

    vector<string> mat(h);
    for (auto& row : mat) {
        cin >> row;
    }

    int ans = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            bool canMove = true;
            int posX = x, posY = y;
            if (mat[posY][posX] == '#') continue; // Skip if starting position is an obstacle.

            for (const char c : t) {
                switch (c) {
                    case 'U': posY--; break;
                    case 'L': posX--; break;
                    case 'D': posY++; break;
                    case 'R': posX++; break;
                }
                // Check bounds and obstacle.
                if (posX < 0 || posY < 0 || posX >= w || posY >= h || mat[posY][posX] == '#') {
                    canMove = false;
                    break;
                }
            }
            if (canMove) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
