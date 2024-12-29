#include <bits/stdc++.h>

using namespace std;
using ll=long long;


struct state {
	int i;
	int j;
	int d;
};

bool is_valid(const vector<string> &m, int i, int j, int h, int w){
	if(i<0 || i>=h) return false;
	if(j<0 || j>=w) return false;
	if(m[i][j] == 'H') return false;
	if(m[i][j] == '#') return false;

	return true;
}

int main(void){
	int h, w, d;
	cin >> h >> w >> d;

	vector<string> m(h);
	for(auto && s: m ) cin >> s;

	queue<state> q;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if (m[i][j]=='H') q.push({i, j, d});

	vector<vector<int>> map(h, vector<int>(w, -1));
	while(!q.empty()){
		auto t = q.front();
		q.pop();

		map[t.i][t.j] = max( map[t.i][t.j], t.d);

		if(t.d==0) continue;

		if(is_valid(m, t.i+1, t.j, h, w) && map[t.i+1][t.j] < t.d-1)
			q.push({t.i+1, t.j, t.d-1});
		if(is_valid(m, t.i, t.j+1, h, w) && map[t.i][t.j+1] < t.d-1)
			q.push({t.i, t.j+1, t.d-1});
		if(is_valid(m, t.i-1, t.j, h, w) && map[t.i-1][t.j] < t.d-1)
			q.push({t.i-1, t.j, t.d-1});
		if(is_valid(m, t.i, t.j-1, h, w) && map[t.i][t.j-1] < t.d-1)
			q.push({t.i, t.j-1, t.d-1});
	}

	int ans = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			//cout << map[i][j] << " ";
			if(map[i][j]>=0) ans++;
		}
		//cout << endl;
	}

	cout << ans << endl;
	
	return 0;
}
