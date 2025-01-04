#include <bits/stdc++.h>

using namespace std;
using ll=long long;

// Function to calculate prime numbers up to a given limit
std::vector<ll> sieve_of_eratosthenes(ll limit) {
    std::vector<bool> is_prime(limit + 1, true); // Assume all numbers are prime initially
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    
    for (ll i = 2; i <= std::sqrt(limit); ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= limit; j += i) {
                is_prime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }
    
    // Store all prime numbers in a vector
    std::vector<ll> primes;
    for (ll i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

ll findLargestPrimeIndex(const std::vector<ll>& primes, const ll x, const ll N) {
    ll left = 0;
    ll right = primes.size() - 1;
    ll maxPrimeIndex = -1;  // Default if no prime is found
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll prime = primes[mid];
        
        // Check if prime^2 * x^2 <= N

		if(prime*x>sqrt(N)+100) right = mid - 1; 
        else if (prime * prime * x * x <= N) {
            // This prime satisfies the condition, so it could be the answer
            maxPrimeIndex = mid;  // Store the index of the prime
            // Move the left poller to search for larger primes
            left = mid + 1;
        } else {
            // This prime doesn't satisfy the condition, search for smaller primes
            right = mid - 1;
        }
    }
    
    return maxPrimeIndex;
}

int main() {
	ll n;
	cin >> n ;
	
    std::vector<ll> p = sieve_of_eratosthenes(2000005);
    

	ll ans = 0;
    for(const auto x: p){
		int resultIndex = findLargestPrimeIndex(p, x, n);
		if(resultIndex==-1) break;
		//cout << "x: " << x << " index: " << resultIndex << " val " << p[resultIndex] << endl; 
		auto val = p[resultIndex];
		resultIndex++;
		if(x<=val) resultIndex--;
		ans += resultIndex;
		//cout << ans << " " << " " << resultIndex << endl; 
	}

	ans/=2;

    for(const auto x: p){
		if(x*x*x*x*x*x*x*x <= n) ans++;
		else break;
	}

	cout << ans<< endl;

    return 0;
}
