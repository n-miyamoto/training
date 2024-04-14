#include <iostream>
#include <vector>

using namespace std;


int main(void){
	int n;
	cin >> n;
	vector<int> vx(n), vy(n);

	for(int i=0;i<n;i++) cin >> vx[i] >> vy[i];

	vector<vector<int>> mat(n, vector<int>(n, 0));

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mat[i][j] = (vx[i]-vx[j])*(vx[i]-vx[j]) + (vy[i]-vy[j])*(vy[i]-vy[j]);

	for(const auto x: mat){
		int min = 0;
		int index = 0;
		for(int i=0;i<n;i++){
			if(min<x[i]){
				min = x[i]; 
				index=i;
			}
		}

		cout << index + 1 << "\n";
	}

	return 0;
}
