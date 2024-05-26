#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ull calc_upper_left(ull x, ull y)
{
	const std::vector<std::vector<ull>> matrix = {
		{0, 0, 0, 0},
		{0, 2, 3, 3},
		{0, 3, 6, 7},
		{0, 5, 9, 10}};

	return matrix[y][x];
}

ull calc_area_from_origin(ull x, ull y)
{
	const ull x_block = x / 4;
	const ull y_block = y / 4;
	const ull x_mod = x % 4;
	const ull y_mod = y % 4;

	const ull main_block = 2 * x_block * y_block * 8;
	const ull upper_block = 2 * x_block * y_mod * 2;
	const ull left_block = 2 * y_block * (x_mod < 3 ? x_mod * 3 : 7);
	const ull upper_left_block = calc_upper_left(x_mod, y_mod);

	return main_block + upper_block + left_block + upper_left_block;
}

int main(void)
{
	ll A, B, C, D;
	cin >> A >> B >> C >> D;

	const ull a = A + 1000000000;
	const ull b = B + 1000000000;
	const ull c = C + 1000000000;
	const ull d = D + 1000000000;

	cout << calc_area_from_origin(c, d) 
		+ calc_area_from_origin(a, b) 
		- calc_area_from_origin(a, d) 
		- calc_area_from_origin(c, b) << endl;

	return 0;
}
