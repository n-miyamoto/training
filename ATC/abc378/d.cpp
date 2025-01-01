#include <bits/stdc++.h>

using namespace std;
using ll=long long;


struct state{
	int i,j,d;
	bitset<100> map;
};

bool is_movable(const int i, const int j, const bitset<100> m, const int h, const int w){
	return 0<=i && i<h && 0<=j && j<w && m[i*w+j]==0;
}

int main(void){
	int h, w, k;
	cin >> h >> w >> k;

	vector<string> s(h);
	for(auto&& x: s) cin >> x;

	bitset<100> map = (0);
	for(int i=0;i<h;i++) 
		for(int j=0;j<w;j++)
			if(s[i][j] == '#')
				map.set(i*w+j) ;

	queue<state> q;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(s[i][j] == '.'){
				q.push({i,j,0,map});
			}
		}
	}

	ll ans = 0;
	while(!q.empty()){
		auto t = q.front();
		q.pop();

		if(t.d == k){
			ans++;
			continue;
		}

		t.map.set(t.i*w+t.j);
		;
		if(is_movable(t.i+1, t.j, t.map, h, w)) q.push({t.i+1, t.j, t.d+1, t.map});
		if(is_movable(t.i, t.j+1, t.map, h, w)) q.push({t.i, t.j+1, t.d+1, t.map});
		if(is_movable(t.i-1, t.j, t.map, h, w)) q.push({t.i-1, t.j, t.d+1, t.map});
		if(is_movable(t.i, t.j-1, t.map, h, w)) q.push({t.i, t.j-1, t.d+1, t.map});
	}

	cout << ans << endl;
	return 0;
}

/*
   10 10 11
   ..........
   ..........
   ..........
   ..........
   ..........
   ..........
   ..........
   ..........
   ..........
   ..........
   */


