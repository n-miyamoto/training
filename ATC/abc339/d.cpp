#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


using pos_pair = pair<pair<int, int>, pair<int, int>>; 

bool is_same_pos(pos_pair pp){
	if (pp.first.first == pp.second.first && pp.first.second == pp.second.second) return true;
	return false;
}

unsigned int decode(pos_pair pp){
	unsigned int val = pp.first.first + (pp.first.second << 8) + (pp.second.first << 16) + (pp.second.second << 24);
	//cout << "decode " << val << endl;
	return val;
}

pos_pair move(const vector<string> &mat, pos_pair pp, const char dir){
	auto next_p0 = pp.first;
	auto next_p1 = pp.second;

	switch (dir)
	{
	case 'U'/* constant-expression */:
		/* code */
		next_p0.second++;
		next_p1.second++;
		break;

	case 'R'/* constant-expression */:
		/* code */
		next_p0.first++;
		next_p1.first++;
		break;

	case 'D'/* constant-expression */:
		/* code */
		next_p0.second--;
		next_p1.second--;
		break;

	case 'L'/* constant-expression */:
		/* code */
		next_p0.first--;
		next_p1.first--;
		break;

	default:
		break;
	}

	const auto n = mat.size();

	if(next_p0.first < 0 || next_p0.second < 0 || next_p0.first>=n || next_p0.second>= n){
		next_p0 = pp.first;
	} else if(mat[next_p0.second][next_p0.first] == '#'){
		next_p0 = pp.first;
	}

	if(next_p1.first < 0 || next_p1.second < 0 || next_p1.first>=n || next_p1.second>= n){
		next_p1 = pp.second;
	} else if(mat[next_p1.second][next_p1.first] == '#'){
		next_p1 = pp.second;
	}

	auto ret = make_pair(next_p0, next_p1);

	//cout << "---" << endl;
	//cout << pp.first.first;
	//cout << pp.first.second;
	//cout << pp.second.first;
	//cout << pp.second.second;
	//cout << endl;

	//cout << ret.first.first;
	//cout << ret.first.second;
	//cout << ret.second.first;
	//cout << ret.second.second;
	//cout << endl;

	return ret;
}

int main(void){
	int n;
	cin >> n;

	vector<string> matrix(n);
	for (auto &l : matrix){
		cin >> l;
	}

	//find p
	vector<pair<int, int>> positions; 
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]=='P'){
				positions.emplace_back(make_pair(j, i));
				//cout << "found " << j << i << endl;
			}
		}
	}

	pos_pair pos_init = make_pair(positions[0], positions[1]);

	//cout << pos_init.first.first;
	//cout << pos_init.first.second;
	//cout << pos_init.second.first;
	//cout << pos_init.second.second;
	//cout << endl;


	//BFS
	queue<pair<int, pos_pair>> q;
	q.push(make_pair(0, pos_init));

	unordered_set<unsigned int> s;
	s.insert(decode(pos_init));
	//cout << "dec " << decode(pos_init) << endl;

	while(!q.empty()){
		auto cur = q.front().second;
		auto count = q.front().first;
		q.pop();

		//cout << count;
		//cout << cur.first.first;
		//cout << cur.first.second;
		//cout << cur.second.first;
		//cout << cur.second.second;
		//cout << endl;

		if(is_same_pos(cur)){
			cout << count << endl;
			return 0;
		}

		//up
		{
			const auto next = move(matrix, cur, 'U');
			if(!s.contains(decode(next))){
				q.push(make_pair(count+1, next));
				s.insert(decode(next));
			}
		}

		//right
		{
			const auto next = move(matrix, cur, 'R');
			if(!s.contains(decode(next))){
				q.push(make_pair(count+1, next));
				s.insert(decode(next));
			}
		}

		//down
		{
			const auto next = move(matrix, cur, 'D');
			if(!s.contains(decode(next))){
				q.push(make_pair(count+1, next));
				s.insert(decode(next));
			}
		}

		//left
		{
			const auto next = move(matrix, cur, 'L');
			if(!s.contains(decode(next))){
				q.push(make_pair(count+1, next));
				s.insert(decode(next));
			}
		}

		//cout << "qsize" << q.size() << endl;
	}

	cout << -1 << endl;
	return 0;
}
