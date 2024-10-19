#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main(void){
	int n;
	string s;
	cin >> n >> s;

	vector<ll> dp_r(n);
	vector<ll> dp_p(n);
	vector<ll> dp_s(n);

	//initialize
	switch (s[0])
	{
	case 'R':
		dp_r[0] = 0;
		dp_p[0] = 1;
		dp_s[0] = -1;
		break;
	case 'P':
		dp_r[0] = -1;
		dp_p[0] = 0;
		dp_s[0] = 1;
		break;
	case 'S':
		dp_r[0] = 1;
		dp_p[0] = -1;
		dp_s[0] = 0;
		break;

	default:
		// error
		break;
	}

	for (int i = 1; i < n; i++)
	{
		switch (s[i])
		{
		case 'R':
			dp_r[i] = max(dp_p[i-1], dp_s[i-1]);
			dp_p[i] = max(dp_r[i-1], dp_s[i-1]) + 1;
			dp_s[i] = -1;
			break;
		case 'P':
			dp_r[i] = -1;
			dp_p[i] = max(dp_r[i-1], dp_s[i-1]);
			dp_s[i] = max(dp_r[i-1], dp_p[i-1]) + 1;
			break;
		case 'S':
			dp_r[i] = max(dp_p[i-1], dp_s[i-1]) + 1;
			dp_p[i] = -1;
			dp_s[i] = max(dp_r[i-1], dp_p[i-1]);
			break;

		default:
			// error
			break;
		}
	}

	cout << max(dp_r[n-1], max(dp_p[n-1], dp_s[n-1])) << endl;

	return 0;
}
