#include <bits/stdc++.h>

using namespace std;
using ll=long long;


struct stat{
	int i;
	int j;
	bool go_vertical;
	int count;
};


bool is_movable(int i, int j, const vector<string>& mat, int h, int w){
	if(i<0)  return false;
	if(i>=h) return false;
	if(j<0)  return false;
	if(j>=w) return false;
	if(mat[i][j]=='#') return false;

	return true;
}

void push_and_fill(queue<stat> &q, vector<vector<bool>> &mat, stat st){
	mat[st.i][st.j] = false;
	q.push(st);
}


int main(void){
	int h, w;
	cin >> h >> w;

	vector<string> mat(h);
	for(auto& s: mat) cin >> s;

	//find start and goal
	pair<int, int> s, g;
	for(int i=0;i<h;i++){
		for(int j=0; j<w;j++){
			if(mat[i][j] == 'S') s = make_pair(i, j);
			else if (mat[i][j]=='G') g = make_pair(i, j);
		}
	}	
	
	vector<vector<bool>> mat_vert(h, vector<bool>(w, true));
	vector<vector<bool>> mat_hori(h, vector<bool>(w, true));

	queue<stat> q;
	q.push({s.first, s.second, true, 0});
	mat_vert[s.first][s.second] = false;
	q.push({s.first, s.second, false, 0});
	mat_hori[s.first][s.second] = false;
		
	while(!q.empty()){
		auto t = q.front();
		q.pop();

		//cout << "status : "<< t.i << t.j << t.go_vertical << t.count << endl;
		
		//Finish if t is on Goal
		if(t.i==g.first && t.j==g.second){
			cout << t.count << endl;
			return 0;
		}

		if(t.go_vertical){
			if(is_movable(t.i+1, t.j  , mat, h, w) && mat_hori[t.i+1][t.j]) push_and_fill(q, mat_hori, {t.i+1, t.j  , false, t.count+1});
			if(is_movable(t.i-1, t.j  , mat, h, w) && mat_hori[t.i-1][t.j]) push_and_fill(q, mat_hori, {t.i-1, t.j  , false, t.count+1});
		}else{
			if(is_movable(t.i  , t.j+1, mat, h, w) && mat_vert[t.i][t.j+1]) push_and_fill(q, mat_vert, {t.i  , t.j+1, true , t.count+1});
			if(is_movable(t.i  , t.j-1, mat, h, w) && mat_vert[t.i][t.j-1]) push_and_fill(q, mat_vert, {t.i  , t.j-1, true , t.count+1});
		}
	}

	cout << -1 << endl;
	return 0;
}
