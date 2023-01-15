#include <bits/stdc++.h>

using namespace std;
#define ll long long 

ll n, m, k;
vector<int> v;

int main(void){
	cin >> n >> m >> k;
	v.resize(n);
	for (auto &x : v){
		cin >> x;
	}

	multiset<int> mset1;
	multiset<int> mset2;
	ll sum=0;
	vector<int> v_sort(v);
	sort(v_sort.begin(), v_sort.begin()+m);

	int i=0;
	for (i=0;i<k;i++){
		sum+= v_sort[i];
		mset1.insert(v_sort[i]);
	}

	for (;i<m;i++){
		mset2.insert(v_sort[i]);
	}

	cout << sum << " ";
	//cout << *mset1.begin() << *mset1.rbegin();cout << *mset2.begin() << *mset2.rbegin();

	for(i=1;i< n-m+1;i++){

		ll out = v[i-1];
		ll in  = v[i+m-1];

		if( out <= *mset1.rbegin()){
			mset1.erase(mset1.find(out));
			sum -= out;
			if(mset2.empty()){
				mset1.insert(in);
				sum+=in;
			}
			else if(in < *mset2.begin()){
				mset1.insert(in);
				sum += in;
			}else{
				mset1.insert(*mset2.begin());
				sum += *mset2.begin();
				mset2.erase(mset2.begin());
				mset2.insert(in);
			}
		}else{
			mset2.erase(mset2.find(out));

			if(in < *mset1.rbegin()){
				mset1.insert(in);
				sum += in;
				sum -= *mset1.rbegin();
				mset2.insert(*mset1.rbegin()); 
				mset1.erase(prev(mset1.end())); 
			}else{
				mset2.insert(in);
			}
		}

		cout << sum << " "; 
	}

	cout << endl; 

	return 0;
}
