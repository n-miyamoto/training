#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n;
	string s;
	cin >> n;
	cin >> s;
	
	vector<int> v;
	s.push_back('0');
	char stat = s[0];
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(stat == s[i]) cnt++;
		else{
			switch (stat)
			{
			case '1':
				v.push_back(cnt);
				break;
			
			case '2':
				v.push_back(-cnt);
				break;

			case '/':
				for(int j=0;j<cnt;j++) v.push_back(0);
				break;
			}
			stat = s[i];
			cnt = 1;
		}
	}

	//find 11/22
	int ans = 1;
	for(int i=1;i<v.size()-1; i++){
		if(v[i-1] > 0 && v[i]==0 && v[i+1] < 0){
			ans = max(ans, 2*min(v[i-1], -v[i+1])+1 );
		}
	}

	cout << ans << endl;
	return 0;
}
