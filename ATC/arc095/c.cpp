#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;
vector<int> v;
vector<int> v_sort;

int main(void){
	cin >> n;
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		v_sort.push_back(tmp);
	}

	sort(v_sort.begin(), v_sort.end());

	int ml = v_sort[n/2-1];
	int mh = v_sort[n/2];

	for(int i=0;i<n;i++){
		if(v[i]<=ml){
			cout << mh << "\n";
		}else{
			cout << ml << "\n";
		}
	}

	return 0;
}
