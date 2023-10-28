#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll n;

int main(void)
{
	cin >> n;

	while (n % 2 == 0)
	{
		n /= 2;
	}
	while (n % 3 == 0)
	{
		n /= 3;
	}

	if (n == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
