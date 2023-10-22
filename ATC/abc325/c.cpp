#include <bits/stdc++.h>

using namespace std;
#define BUF (1000005)
#define ll long long

ll h, w;

static ll N;
ll p[BUF]; // parentp
ll d[BUF]; // depth

void uf_init(ll n)
{
	N = n;
	for (ll i = 0; i < n; i++)
		p[i] = i, d[i] = 0;
}

ll find(ll x)
{
	if (p[x] == x)
		return x;
	else
	{
		p[x] = find(p[x]);
		return p[x];
	}
}

void unite(ll x, ll y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	if (d[x] < d[y])
	{
		p[x] = y;
	}
	else if (d[x] > d[y])
	{
		p[y] = x;
	}
	else
	{
		p[y] = x;
		d[x]++;
	}
}

bool same(ll x, ll y)
{
	return find(x) == find(y);
}

void show_alld(void)
{
	cout << "depth  : ";
	for (ll i = 0; i < N; i++)
		cout << d[i] << " ";
	cout << "\n";
}
void show_allp(void)
{
	cout << "parent : ";
	for (ll i = 0; i < N; i++)
		cout << p[i] << " ";
	cout << "\n";
}
ll show_parent(ll i)
{
	return p[i];
}

ll show_depth(ll i)
{
	return d[i];
}

ll show_groups()
{
	vector<ll> vt(N, 0);
	for (ll i = 0; i < N; i++)
	{
		auto par = find(i);
		vt[par] = 1;
	}

	auto ans = std::accumulate(vt.begin(), vt.end(), 0LL);
	return ans;
}

int main(void)
{
	cin >> h >> w;
	vector<ll> v(h * w);

	ll k = 0;
	for (ll y = 0; y < h; y++)
	{
		for (ll x = 0; x < w; x++)
		{
			char temp;
			cin >> temp;
			switch (temp)
			{
			case '.':
				v[y * w + x] = -1;
				break;
			case '#':
				v[y * w + x] = k;
				k++;
				break;
			default:
				cout << "aaa" << (int)temp;
				break;
			}
		}
	}

	// for (ll y = 0; y < h; y++)
	//{
	//	for (ll x = 0; x < w; x++)
	//	{
	//		auto base_index = y*w+x;
	//		cout << v[base_index] << "   ";
	//	}
	//	cout << endl;
	// }

	uf_init(k);

	for (ll y = 0; y < h; y++)
	{
		for (ll x = 0; x < w; x++)
		{
			auto base_index = y * w + x;
			if (v[base_index] >= 0)
			{
				// check x-1, y-1
				{
					auto temp_index = (y - 1) * w + x - 1;
					if ((y - 1) >= 0 && (x - 1) >= 0 && temp_index >= 0)
					{
						if (v[temp_index] >= 0)
						{
							unite(v[base_index], v[temp_index]);
						}
					}
				}

				// check x  , y-1
				{
					auto temp_index = (y - 1) * w + x;
					if ((y - 1) >= 0 && temp_index >= 0)
					{
						if (v[temp_index] >= 0)
						{
							unite(v[base_index], v[temp_index]);
						}
					}
				}

				// check x+1, y-1
				{
					auto temp_index = (y - 1) * w + x + 1;
					if ((y - 1) >= 0 && (x + 1) < w && temp_index >= 0)
					{
						if (v[temp_index] >= 0)
						{
							unite(v[base_index], v[temp_index]);
						}
					}
				}

				// check x-1, y
				{
					auto temp_index = (y + 0) * w + x - 1;
					if ((x - 1) >= 0 && temp_index >= 0)
					{
						if (v[temp_index] >= 0)
						{
							unite(v[base_index], v[temp_index]);
						}
					}
				}
			}
		}
	}

	// cout << "------" << k << endl;
	// show_allp();
	// show_alld();
	cout << show_groups() << endl;

	return 0;
}
