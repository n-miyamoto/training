#include <bits/stdc++.h>

using namespace std;
using ll=long long;

double calc_dist(double x1, double y1, double x2, double y2){
	return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double calc_total_dist(
	const vector<int> & perm,
	const int bits,
	const vector<vector<int>> &xv,
	const vector<vector<int>> &yv, 
	int n, int s, int t)
{
	double cur_x = 0, cur_y=0, total=0;
	for(int i=0;i<n;i++){
		auto index = perm[i];
		total += calc_dist(
			cur_x, cur_y, 
			xv[(bits>>index)&1][index],
			yv[(bits>>index)&1][index])/(double)s;

		total += calc_dist(xv[0][index], yv[0][index], xv[1][index], yv[1][index])/(double)t;

		cur_x = xv[((bits>>index)&1)^1][index];
		cur_y = yv[((bits>>index)&1)^1][index];
		//cout << cur_x << "," << cur_y << " ";
	}

	return total;
}

int main(void){
	int n, s, t;
	cin >> n >> s >> t;
	vector<vector<int>> xv(2, vector<int>(n));
	vector<vector<int>> yv(2, vector<int>(n));

	for(int i=0;i<n;i++){
		cin >> xv[0][i] >> yv[0][i];
		cin >> xv[1][i] >> yv[1][i];
	}

	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);

	double ans = 3000*12;

    do {
		for(int i = 0;i< 1<<n ; ++i){
			auto dist = calc_total_dist(p, i, xv, yv, n, s, t);
			ans = min(ans, dist);
			//cout << dist << endl;
		}
    } while (std::next_permutation(p.begin(), p.end()));

	std::cout << std::setprecision(std::numeric_limits<double>::max_digits10);
	cout << ans << endl;

	return 0;
}
