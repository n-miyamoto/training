#include <bits/stdc++.h>

using namespace std;
using ll=long long;



int main(void){
	int q;
	cin >> q;

	vector<int> bag(1'000'001);
	int ball_kind=0;
	for(int i = 0;i<q;i++){
		int query_type, ball_id;
		cin >> query_type;

		switch (query_type)
		{
		case 1:
			cin >> ball_id;
			bag[ball_id]++;
			if(bag[ball_id]==1) ball_kind++;
			break;

		case 2:
			cin >> ball_id;
			bag[ball_id]--;
			if(bag[ball_id]==0) ball_kind--;
			break;

		case 3:
			cout << ball_kind << endl;
			break;
		
		default:
			break;
		}
	}
	
	return 0;
}
