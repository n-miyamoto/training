#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

ll n;
std::vector<ll>  a;
std::vector<ll>  a_;
ll buf[BUF];

namespace {

size_t Merge(std::vector<ll>& a, size_t i, size_t chunk_size, std::vector<size_t>& tmp) {
     std::vector<ll>::iterator a1 = a.begin() + i;
     size_t l1 = chunk_size;
     std::vector<ll>::iterator a2 = a1 + l1;
     size_t l2 = (a.size() > i + chunk_size * 2) ? chunk_size : a.size() - i - chunk_size;

     tmp.clear();
     size_t res = 0;

     for (size_t i1 = 0, i2 = 0; i1 != l1 || i2 != l2; ) {
          if (i1 == l1) {
               tmp.push_back(a2[i2++]);
          } else if (i2 == l2) {
               tmp.push_back(a1[i1++]);
          } else if (a1[i1] <= a2[i2]) {
               tmp.push_back(a1[i1++]);
          } else if (a2[i2] < a1[i1]) {
               tmp.push_back(a2[i2++]);
               res += l1 - i1;
          } else {
               std::cerr << "Oops" << std::endl;
          }
     }

     for (size_t di = 0; di < tmp.size(); ++di)
          a[i + di] = tmp[di];

     return res;
}

size_t CountCross(std::vector<ll>& a) {
     size_t res = 0;
     std::vector<size_t> tmp(a.size());

     for (size_t chunk_size = 1; chunk_size < a.size(); chunk_size *= 2)
          for (size_t i = 0; i + chunk_size < a.size(); i += chunk_size * 2)
               res += Merge(a, i, chunk_size, tmp);

     return res;
}

}


ll count(std::vector<ll> &array, ll num){
	ll ret = 0;
	std::vector<ll>  s;
	for(ll i=0;i<n;i++){
		if(array[i]<num){
			s.push_back(-1);
			ret++;
		}
		else{
			s.push_back(1);
		}
	}
//	for(ll i=0;i<n;i++) cout << s[i] << " ";
//	cout << "\n";
	for(ll i=1;i<n;i++){
		s[i]+=s[i-1];
//		cout << s[i] << " ";
	}
//	cout << "\n";

	ret += CountCross(s);
	return ret;
}

int main(void){
	cin >> n;
	for(ll i=1;i<=n;i++){
		ll tmp;
		cin >> tmp;
		a.push_back(tmp);
		a_.push_back(tmp);
	} 

	sort(a_.begin(), a_.end());
//	for(ll i=0;i<n;i++) cout << a_[i] << " ";
	ll low = 0;
	ll hi  = n-1;
	ll mid;

//	for(ll i=0;i<n;i++){
//		ll cnt = count(a, a_[i]);
//		cout << i << " " << a_[i] << " "<< cnt << " \n"; 
//	}
	while(1){
		mid = (hi+low+1)/2;
		
//		cout << low << " " << mid << " " << hi << " \n"; 
		ll cnt = count(a, a_[mid]);
//		cout << low << " " << mid << " " << hi << " "<<cnt <<  " \n"; 
		if(low == hi) break;
		else if(cnt<= (n*(n+1)/2 +1)/2) low = mid;
		else hi = mid-1;
	}

	cout << a_[mid] << endl;
	return 0;
}
