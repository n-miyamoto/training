#include <iostream>
#include <unordered_map>

using ll = long long;

std::unordered_map<ll, ll> cache; 

ll calculateSum(ll n){
	if(n==1) return 0;

	if(cache.contains(n)){
		return cache[n];
	}

	ll ans;
	if(n%2==0){
		ans = n + 2*calculateSum(n/2);
	}else{
		ans = n + calculateSum(n/2) + calculateSum(n/2+1);
	}

	cache[n] = ans;
	return ans;
}

int main(void){
	ll n;
	std::cin >> n;
	std::cout << calculateSum(n) << std::endl;
	return 0;
}

