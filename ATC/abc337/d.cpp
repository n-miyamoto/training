#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

const int MAX = 200005;
int h, w, k;
vector<string> grid;


int solve_horizontal(){
	int ans = MAX;

	if(w<k){
		return ans;
	}

	//horizontal scan
	for (const auto& row: grid){
		int count_o=0;
		int count_x=0;
		int count_p=0;
		// initialize
		for (int i = 0; i < k; i++)
		{
			switch (row[i])
			{
				case '.': count_p++; break;
				case 'o': count_o++; break;
				case 'x': count_x++; break;
				default : /* error */break;
			}
		}

		if (count_x==0){
			ans = min(ans, count_p);
		}

		for(int i=1;i<=w-k;i++){
			switch (row[i-1])
			{
				case '.': count_p--; break;
				case 'o': count_o--; break;
				case 'x': count_x--; break;
				default : /* error */break;
			}
			switch (row[i+k-1])
			{
				case '.': count_p++; break;
				case 'o': count_o++; break;
				case 'x': count_x++; break;
				default : /* error */break;
			}

			if (count_x == 0)
			{
				ans = min(ans, count_p);
			}
		}
	}
	return ans;
}

int solve_vertical(){
	int ans = MAX;

	if(h<k){
		return ans;
	}

	//vertical scan
	for (int l=0;l<w;l++){
		int count_o=0;
		int count_x=0;
		int count_p=0;
		// initialize
		for (int i = 0; i < k; i++)
		{
			switch (grid[i][l])
			{
				case '.': count_p++; break;
				case 'o': count_o++; break;
				case 'x': count_x++; break;
				default : /* error */break;
			}
		}

		if (count_x==0){
			ans = min(ans, count_p);
		}

		for(int i=1;i<=h-k;i++){
			switch (grid[i-1][l])
			{
				case '.': count_p--; break;
				case 'o': count_o--; break;
				case 'x': count_x--; break;
				default : /* error */break;
			}
			switch (grid[i+k-1][l])
			{
				case '.': count_p++; break;
				case 'o': count_o++; break;
				case 'x': count_x++; break;
				default : /* error */break;
			}

			if (count_x == 0)
			{
				ans = min(ans, count_p);
			}
		}
	}

	return ans;
}

int main(void){
	cin >> h >> w >> k;
	
	grid.resize(h);
	for (auto& x: grid){
		cin >> x;
	}

	int ans = solve_horizontal();
	ans = min(ans, solve_vertical());

	if (ans == MAX){
		cout << -1 <<endl;
		return 0;
	}
	cout << ans << endl;

	return 0;
}
