#include <iostream>
using namespace std;

int main() {
    int N, S, K;
    cin >> N >> S >> K;

    int totalPrice = 0;
    for (int i = 0; i < N; ++i) {
        int P, Q;
        cin >> P >> Q;
        totalPrice += P * Q;
    }

    if (totalPrice < S) {
        totalPrice += K;
    }

    cout << totalPrice << endl;
    return 0;
}