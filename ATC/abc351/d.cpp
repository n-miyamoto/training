#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


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

			auto a=i+1;auto b=j;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='#') mat[i][j] = 'M';

			a=i-1;b=j;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='#') mat[i][j] = 'M';

			
			a=i;b=j+1;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='#') mat[i][j] = 'M';

			a=i;b=j-1;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='#') mat[i][j] = 'M';
		}
	}

	//show(mat);

	UnionFind uf(h*w);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(mat[i][j]=='#') continue;
			if(mat[i][j]=='M') continue;

			auto a=i-1;auto b=j;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='.'){
				uf.unite(w*i+j, w*a+b);
			}

			a=i;b=j-1;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='.'){
				uf.unite(w*i+j, w*a+b);
			} 
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

			auto a=i-1;auto b=j;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='.') um_set[uf.find(a*w+b)].insert(i*w+j);

			a=i+1;b=j;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='.') um_set[uf.find(a*w+b)].insert(i*w+j);

			a=i;b=j-1;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='.') um_set[uf.find(a*w+b)].insert(i*w+j);

			a=i;b=j+1;
			if (a>=0 && a<h && b>=0 && b<w && mat[a][b]=='.') um_set[uf.find(a*w+b)].insert(i*w+j);

		}
	}

	auto ans = 0;
	for(const auto& s : um_set){
		//cout << s.first << " size: " << s.second.size() << endl;
		if(ans < s.second.size()) ans = s.second.size();
	}

	cout << ans << endl; 
	
	return 0;
}
