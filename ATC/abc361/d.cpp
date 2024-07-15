#include <bits/stdc++.h>

using namespace std;
using ll=long long;

set<unsigned int> st; 

unsigned int swapBits(unsigned int n, int i, int j) {
	auto num = n;
    if (((num >> i) & 1) != ((num >> j) & 1)) {
        int bitMask = (1 << i) | (1 << j);
        num ^= bitMask;
    }
	return num;
}


unsigned int decode(const string& s, int n){
	unsigned int ret = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='W') ret|=(1<<i);
	}

	ret += (n<<18);
	return ret;
}

void print_state(unsigned int state, int n){
	int pos = state >> 18;
	for(int i=0;i<n+2;i++){
		char c;
		if(i==pos) c='.';
		else if(i==pos+1) c='.';
		else if((state>>i)&1 ) c='W';
		else c='B';

		cout << c;
	}
	cout << endl;
}

int main(void){
	int n;
	cin >> n;

	string s, t;
	cin >> s;
	cin >> t;

	if(count(s.begin(), s.end(), 'W') != count(t.begin(), t.end(), 'W')){
		cout << -1 << endl;
		return 0;
	}
	

	queue<pair<unsigned int, int>> q;

	q.push(make_pair(decode(s, n), 0));
	unsigned int end_state = decode(t, n);

	while(q.front().first!=end_state){

		auto state = q.front().first;
		auto count = q.front().second;
		q.pop();

		//print_state(state, n);
		//cout << count << endl;

		int bit = state >> 18;
		for(int i=0;i<(n+1);i++){
			if(i==bit || i==bit-1 || i==bit+1) continue;
			auto tmp = swapBits(state&0x1FFFF, i, bit);
			tmp = swapBits(tmp, i+1, bit+1);
			tmp += (i<<18);

			if (st.find(tmp) != st.end()) {
				continue;
			}

			st.insert(tmp);
			//cout << "i : " << i << endl;
			q.push(make_pair(tmp, count+1));
		}

		if(q.empty()){
			cout << -1 << endl;
			return 0;
		}
	}


	cout << q.front().second << endl;

	return 0;
}
