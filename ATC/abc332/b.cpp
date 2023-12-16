#include <iostream>
using namespace std;

int main() {
    int K, G, M;
    cin >> K >> G >> M;

    int glass = 0, mug = 0;

    for (int i = 0; i < K; ++i) {
        if (glass == G) {
            // Empty the glass
            glass = 0;
        } else if (mug == 0) {
            // Fill the mug
            mug = M;
        } else {
            // Transfer water from mug to glass
            int transfer = min(G - glass, mug);
            glass += transfer;
            mug -= transfer;
        }
    }

    cout << glass << " " << mug << endl;
    return 0;
}