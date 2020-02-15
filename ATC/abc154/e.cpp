#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long

int k;

ll solve1(string n)
{
	int m = n.length();
	ll ans = 9 * (m - 1) + n.at(0) - 0x30;
	return ans;
}

ll solve2(string n)
{
	int top = 0;
	int m = n.length();
	int second = 1;
	while (second < m && n.at(second) == 0x30)
	{
		second++;
	}

	ll ans = 0;
	for (int i = 1; i < m; i++)
	{
		ans += 81 * (i - 1);
	}

	ans += (n.at(0) - 0x31) * (m - 1) * 9;
	if (second != m)
	{
		ans += n.at(second) - 0x30;
		ans += 9 * (m - second - 1);
	}
	return ans;
}

ll solve3(string n)
{
	int top = 0;
	int m = n.length();
	int second = 1;
	while (second < m && n.at(second) == 0x30)
	{
		second++;
	}

	ll ans = 0;
	for (int i = 1; i < m; i++)
	{
		ans += 9 * 9 * 9 * (i - 1) * (i - 2) / 2;
	}

	ans += (n.at(0) - 0x31) * (m - 1) * (m - 2) / 2 * 9 * 9;

	string s = n.substr(second, m - second);
	if (second != m)
		ans += solve2(s);

	return ans;
}

int main(void)
{
	string n;
	cin >> n;
	cin >> k;

	ll ans;
	switch (k)
	{
	case 1:
		ans = solve1(n);
		break;
	case 2:
		ans = solve2(n);
		break;
	case 3:
		ans = solve3(n);
		break;
	}

	cout << ans << endl;
	return 0;
}
