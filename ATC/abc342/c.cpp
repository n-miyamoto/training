#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main() {
    int n, q;
    std::string s;
    std::cin >> n >> s >> q;

    std::unordered_map<char, char> replacements;
    for (char c = 'a'; c <= 'z'; ++c) {
        replacements[c] = c; // Initially, each character maps to itself
    }

    for (int i = 0; i < q; ++i) {
        char c, d;
        std::cin >> c >> d;
        // Update all entries in the map that currently map to 'c' to map to 'd' instead
        for (auto &entry : replacements) {
            if (entry.second == c) {
                entry.second = d;
            }
        }
    }

    // Apply the replacements to the string
    for (char &c : s) {
        c = replacements[c];
    }

    std::cout << s << std::endl;

    return 0;
}