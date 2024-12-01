#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;


	//encode
	s.push_back('/');
	vector<int> v;
	int count = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[i+1]) {
            ++count;
        } else {
            if (s[i]=='1') {
                v.push_back(count);
            }else{
                v.push_back(-count);
            } 
            count = 1;
        }
    }

	//for(auto x : v) cout << x;

	for(int cnt = 0,i=0;i<v.size();i++){
		if(v[i]>0) cnt++;
		if(cnt==k){
			int tmp = v[i];
			v[i] = v[i-1];
			v[i-1] = tmp;
			break;
		}
	}

	//for(auto x : v) cout << x;
	
	//decode;
	for(auto x : v){
		if(x>0) for(int i=0;i<x;i++) cout << '1';
		else    for(int i=0;i<-x;i++) cout << '0';
	}
	cout << endl;
}
