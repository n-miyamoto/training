#include <bits/stdc++.h>

using namespace std;
#define buf (1000)
#define ll unsigned long long

unsigned int n;
string t;
int l = 0;

// case 1 : same
bool check0(string str)
{
	if (t == str)
		return true;
	return false;
}

// case 2 : add a char
bool check1(string str)
{
	if (str.length() + 1 == l)
	{
		for (int i = 0, j = 0; i < l; i++)
		{
			if (str[i - j] != t[i])
			{
				j++;
			}
			if (j > 1)
				return false;
		}
		return true;
	}
	return false;
}

// case 3 : remove a char
bool check2(string str)
{
	if (str.length() - 1 == l)
	{
		for (int i = 0, j = 0; i < str.length(); i++)
		{
			if (t[i - j] != str[i])
			{
				j++;
			}
			if (j > 1)
				return false;
		}
		return true;
	}
	return false;
}

// case 4 : change a char
bool check3(string str)
{
	if (str.length() == l)
	{
		for (int i = 0, j = 0; i < str.length(); i++)
		{
			if (t[i] != str[i])
			{
				j++;
			}
			if (j > 1)
				return false;
		}
		return true;
	}
	return false;
}

int main(void)
{
	cin >> n >> t;
	l = t.length();
	vector<int> ans;

	for (int i = 1; i <= n; i++)
	{
		string t;
		cin >> t;
		if (check0(t))
		{
			ans.push_back(i);
			continue;
		};
		if (check1(t))
		{
			ans.push_back(i);
			continue;
		};
		if (check2(t))
		{
			ans.push_back(i);
			continue;
		};
		if (check3(t))
		{
			ans.push_back(i);
			continue;
		};
	}

	cout << ans.size() << endl;
	for (const auto &x : ans)
	{
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
