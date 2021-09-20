#include <bits/stdc++.h>

using namespace std;
#define ll long long 

int n;
vector<int> a;
vector<int> dp[200];

void print_vec(const vector<int> &vec){
	cout << vec.size();
	for(auto x : vec) cout << " " << x+1;
	cout << endl;
}

void show_dp(void){
	for(int i=0;i<200;i++){
		cout << i << ":" ;
		for(auto x : dp[i]) cout << x << " ";
		cout << endl; 
	}
}

int main(void){
	cin >> n;
	a.resize(n);
	for(auto& x : a) cin >> x;
	//for(const auto& x : a) cout <<  x;

	for(int i=0;i<n;i++){
		//show_dp();

		vector<int> vt[200];
		int tmp = a[i]%200;
		vt[tmp].push_back(i);
		
		if(!dp[0].empty()){
			dp[0].push_back(i);
			cout << "Yes" << endl;
			print_vec(dp[0]);
			print_vec(vt[tmp]);
			return 0;
		}

		for(int j=1;j<200;j++){
			if(!dp[j].empty()){
				vt[(j+tmp)%200] = dp[j];
				vt[(j+tmp)%200].push_back(i);
			}
		}


		for(int j=0;j<200;j++){
			if(!dp[j].empty() && !vt[j].empty()){
				cout << "Yes" << endl;
				print_vec(dp[j]);
				print_vec(vt[j]);
				return 0;
			}else if(dp[j].empty() && !vt[j].empty()){
				for(auto x: vt[j]){
					dp[j].push_back(x);
				}
			}
		}
	}

	cout << "No" << endl;
	
	return 0;
}
