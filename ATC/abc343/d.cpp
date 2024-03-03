#include <iostream>
#include <vector>
#include <map>

using ll = long long;

int main() {
    ll n, t;
    std::cin >> n >> t;

    std::vector<ll> playerScore(n + 1, 0); // Stores each player's current score
    std::map<ll, ll> scoreFrequency;       // Maps scores to their frequencies among players
    scoreFrequency[0] = n;                 // Initially, all players have a score of 0

	for (auto _ : std::vector<ll>(t)){
        ll player, scoreIncrease;
        std::cin >> player >> scoreIncrease;

        ll& currentScore = playerScore[player];
        ll previousScore = currentScore;
        currentScore += scoreIncrease;

        // Update the frequency map for the previous score
        if (--scoreFrequency[previousScore] == 0) {
            scoreFrequency.erase(previousScore);
        }

        // Update the frequency map for the current score
        scoreFrequency[currentScore]++;

        std::cout << scoreFrequency.size() << std::endl;
    }

    return 0;
}