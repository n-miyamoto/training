#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll n;

ll used_alphabet[0xFF];

ll s2num(string s, vector<ll> p){
	reverse(s.begin(), s.end());
	ll ret = 0;
	ll m = 1;
	for(auto c: s){
		ret += p[used_alphabet[c]] * m;
		m *= 10;
	}
	return ret;
}

int main(void){
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	for(auto c : s1) used_alphabet[c]=1;
	for(auto c : s2) used_alphabet[c]=1;
	for(auto c : s3) used_alphabet[c]=1;

	// for debug
	string alphabets = "";
	for(char c = 'a';c<='z';c++ ){
		if(used_alphabet[c]){
			used_alphabet[c] = alphabets.size();
			alphabets.push_back(c);
		}
	}

	// Too many alphabets. unsolvable
	if(alphabets.size()>10){
		cout << "UNSOLVABLE" << endl;
		return 0;
	}

	
	vector<ll> p;
	for(ll i=0;i<10;i++) p.push_back(i);

    do{
		// start from 0
		if(p[used_alphabet[s1[0]]]==0) continue;
		if(p[used_alphabet[s2[0]]]==0) continue;
		if(p[used_alphabet[s3[0]]]==0) continue;
		ll n1 = s2num(s1, p);
		ll n2 = s2num(s2, p);
		ll n3 = s2num(s3, p);

		if( n1+n2 == n3 )
		{
			cout << n1 << endl;
			cout << n2 << endl;
			cout << n3 << endl;
			return 0;
		}
    }while(next_permutation(p.begin(),p.end()));

	// no matched answer. unsolvable
	cout << "UNSOLVABLE" << endl;
	return 0;
}
