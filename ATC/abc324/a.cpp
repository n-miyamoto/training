#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long

int n;

int main(void)
{
	cin >> n;
	vector<int> v(n);
	for (auto &x : v)
	{
		cin >> x;
	}

	const auto ref = v[0];
	for (const auto &x : v)
	{
		if (x != ref)
		{
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}
