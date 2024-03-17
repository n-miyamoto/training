#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, H, W;

using tile = pair<int, int>;
vector<tile> tiles;
vector<vector<bool>> grid;
int total=0;

bool fits(int h, int w, int i, int j) {
    for (int x = 0; x < h; ++x) {
        for (int y = 0; y < w; ++y) {
            //if (i + x >= H || j + y >= W || grid[i + x][j + y]) return false;
            if (grid[i + x][j + y]) return false;
        }
    }
    return true;
}

void place(int h, int w, int i, int j, bool value) {
    for (int x = 0; x < h; ++x) {
        for (int y = 0; y < w; ++y) {
            grid[i + x][j + y] = value;
        }
    }
}

vector<bool> used;

bool backtrack() {
	//cout << "bt " << "total " << total << endl; 
	if(total==H*W) return true;
	if(total>H*W) return false;
	if(std::all_of(used.begin(), used.end(), [](bool val) { return val; })){
		return false;
	}

	//find open grid
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(!grid[i][j]){
				for(int tile_id=0;tile_id<N;tile_id++){
					if(!used[tile_id]){
						auto [h, w] = tiles[tile_id];
						//place w x h
						if(W-j>=w && H-i>=h && fits(h, w, i, j)){

							used[tile_id] = true;
							place(h, w, i, j, true);
							total+=h*w;
							if (backtrack()) return true;
							used[tile_id] = false;
							place(h, w, i, j, false);
							total-=h*w;
						}

						//place h x w
						if(W-j>=h && H-i>=w && fits(w, h, i, j)) {
							used[tile_id] =true; 
							place(w, h, i, j, true);
							total+=h*w;
							if (backtrack()) return true;
							used[tile_id] =false; 
							place(w, h, i, j, false);
							total-=h*w;
						}
					}
				}
				return false;
			}
		}
	}

	return false;
}


int main() {
    cin >> N >> H >> W;
    tiles.resize(N);
    grid.assign(H, vector<bool>(W, false));

	int totalArea = 0;
    for (int i = 0; i < N; ++i) {
        cin >> tiles[i].first >> tiles[i].second;
		totalArea += tiles[i].first * tiles[i].second;
    }

	if (totalArea < H * W) {
        cout << "No" << endl;
        return 0;
    }


	used.assign(N, false);
    if (backtrack()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}