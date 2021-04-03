#include <bits/stdc++.h>

using namespace std;
#define BUF (2005)
#define ll long long 

int H,W;
char a[BUF][BUF];
int C[BUF][BUF];

using point = pair<int,int>;
point S,G;
vector<point> v[0xFF];
char used[0xff];

bool is_movable(point p){
	if(p.first  < 1) return false;
	if(p.second < 1) return false;
	if(p.first  > H) return false;
	if(p.second > W) return false;
	if(a[p.first][p.second]=='#') return false;
	return true;
}

bool is_warpable(point p){
	if(!is_movable(p)) return false;
	char c = a[p.first][p.second];  
	if('a' <= c && c <= 'z')
		return true;
	return false;
}

void get_warp_dir(point p, vector<point> &pv){
	char c = a[p.first][p.second];  
	//cout << "warp" << p.first << " " << p.second << c << endl;
	if(used[c]==1)return;
	used[c] = 1;
	for(auto x:v[c]){
		pv.push_back(x);
	} 
	return;
}

void show(){
	for(int i=0;i<=H;i++){
		for(int j=0;j<=W;j++){
			cout << a[i][j];
		}
		cout << endl;
	}
}

void showC(){
	for(int i=0;i<=H;i++){
		for(int j=0;j<=W;j++){
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
}

void showv(){
	for(int j='a';j<='z';j++){
		cout << v[j].size();
		for(int i=0;i<v[j].size();i++)
			cout << v[j][i].first << " " << v[j][i].second;
	}
}

void chech_point(point t, point tp, queue<point>&q){
	//cout << t.first << " " << t.second << endl;
	//cout << tp.first << " " << tp.second << endl;
	if(is_movable(tp)){
		if(C[tp.first][tp.second]==0 || C[tp.first][tp.second]>C[t.first][t.second]+1){
			//cout << "push" << tp.first << " " << tp.second << endl;
			q.push(tp);
			C[tp.first][tp.second] = C[t.first][t.second] + 1;  
		}
	}
}

int main(void){
	cin >> H >> W;
	for(int i=1;i<=H;i++){
		string s;
		cin >> s;
		for(int j=1;j<=W;j++){
			a[i][j] = s[j-1];
			if(a[i][j]=='S') S = make_pair(i,j);
			if(a[i][j]=='G') G = make_pair(i,j);
			if('a' <= a[i][j] && a[i][j] <= 'z')
				v[a[i][j]].push_back(make_pair(i,j));
		}
	}

	//show();
	//showC();
	//showv();

	queue<point> q;
	q.push(S);

	//main loop
	while(!q.empty()){
		point t = q.front();
		q.pop();
		point tp;
		//cout << "debug" << q.size() <<  t.first << " " << t.second << endl;

		if(t==G){
			cout << C[t.first][t.second] << endl;
			return 0;
		}

		//upper check 
		tp = make_pair(t.first-1, t.second);
		chech_point(t, tp, q);

		//right check
		tp = make_pair(t.first, t.second+1);
		chech_point(t, tp, q);

		//lower check 
		tp = make_pair(t.first+1, t.second);
		chech_point(t, tp, q);

		//left  check 
		tp = make_pair(t.first, t.second-1);
		chech_point(t, tp, q);

		//warp  check 
		tp = make_pair(t.first, t.second);
		if(is_warpable(tp)){
			vector<point> pv;
			get_warp_dir(tp, pv);
			for(auto d : pv){
				if(C[d.first][d.second]==0 || C[d.first][d.second] > C[t.first][t.second]+1){
					q.push(d);
					C[d.first][d.second] = C[t.first][t.second] + 1;  
				}
			}

		}
	}

	cout << -1 << endl;	
	return 0;
}
