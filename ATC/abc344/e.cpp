#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


int main(void){
	int n;
	cin >> n;
	list<int> l;
	unordered_map<int, list<int>::iterator> map;

	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		l.push_back(a);
		map[a] = --l.end();
	}

	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int t;
		cin >> t;

		switch (t){
		case 1: /* constant-expression */
			/* code */
			{
				int x, y;
				cin >> x >> y;
				auto it = map[x];
				l.insert(next(it,1), y);
				map[y] = next(it,1);
			}

			break;
		case 2:
			{
				int x;
				cin >> x;
				auto it = map[x];
				l.erase(it);
				map.erase(x);
			}
			break;
		
		default:
			break;
		}
	}

	for(auto x : l){
		cout << x << " ";
	}
	cout << endl;
	
	return 0;
}
