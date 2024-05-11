#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void show(vector<string> &mat){
	for(auto& line : mat) cout << line << endl;
}

class UnionFind {
private:
    vector<int> parent;
    vector<int> depth;
    int size;

public:
    UnionFind(int n) : parent(n), depth(n, 0), size(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (depth[x] < depth[y]) {
                parent[x] = y;
            } else {
                parent[y] = x;
                if (depth[x] == depth[y]) depth[x]++;
            }
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

bool is_valid(int x, int y, int h, int w) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

int main(void){
	int h, w;
	cin >> h >> w;

	vector<string> mat(h);

	for(auto& line : mat){
		cin >> line;
	}

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(mat[i][j]=='#') continue;

			vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto [dx, dy] : directions) {
                int ni = i + dx, nj = j + dy;
                if (is_valid(ni, nj, h, w) && mat[ni][nj] == '#') {
                    mat[i][j] = 'M';
                }
            }
		}
	}

	//show(mat);

	UnionFind uf(h*w);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(mat[i][j]=='#') continue;
			if(mat[i][j]=='M') continue;

			auto a=i-1;auto b=j;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='.') uf.unite(w*i+j, w*a+b);

			a=i;b=j-1;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='.') uf.unite(w*i+j, w*a+b);
		}
	}

	unordered_map<int, set<int>> um_set;

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(mat[i][j]=='#') continue;
			if(mat[i][j]=='.'){
				um_set[uf.find(i*w+j)].insert(i*w+j);
				continue;
			}

			//mat[i][j]=='M' case
			um_set[uf.find(i*w+j)].insert(i*w+j);

			vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto [dx, dy] : directions) {
                int ni = i + dx, nj = j + dy;
                if (is_valid(ni, nj, h, w) && mat[ni][nj] == '.') {
					um_set[uf.find(ni*w+nj)].insert(i*w+j);
                }
            }
		}
	}

	int ans = 0;
	for(const auto& s : um_set){
		ans = std::max(ans, static_cast<int>(s.second.size()));
	}

	cout << ans << endl; 
	
	return 0;
}
