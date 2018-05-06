#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;
vector<int> a;

int main(void){
	cin >> n;
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	sort(a.begin(), a.end());

	int k;
	int mx = 0;
	int ans;
	for( int i=0;i<n-1;i++){
		int tmp = min(a[n-1]-a[i],a[i]);
		if(mx<tmp){
			mx = tmp;
			ans = i;
		}
	}

	cout << a[n-1] << " " << a[ans] << endl;	
	return 0;
}
