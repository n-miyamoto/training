#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll n;
vector<ll> v;
ll arr[20];


ll decode(ll arr[20]){
	ll ret = 0;
	ll base = 1;
	for(ll i=0;i<20;i++){
		ret += arr[i] * base;
		base *= 10;
	}

	return ret;
}

int main(void){
	cin >> n;

	//create all 
	for(int k=0;k<18;k++){  //keta
		for(int h=1;h<=9;h++){ //atama
			for(int d=-9; d<=9;d++){ //diff
				for(int i=0;i<20;i++) arr[i] = 0;  //initialize array
				for(int i=k; i>=0; i--){ 
					arr[i] = h+(k-i)*d;
				}

				bool flag = true;
				for(int i=0;i<20;i++){
					if(arr[i] < 0 || 9<arr[i] ){
						flag = false;
					}
				}

				if(flag){
					v.push_back(decode(arr));
					//cout << v.back() << endl;
				}
			}
		}
	}

	auto ite = lower_bound(v.begin(), v.end(), n);
	cout << *ite << endl;

	return 0;
}
