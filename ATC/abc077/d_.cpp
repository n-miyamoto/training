#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)

#define ll long long 

int k;

vector<int> v[BUF];
vector<int> v_[BUF];
int d[BUF];

int main(void){
	cin >> k;
	for(int i=1;i<k;i++){
		v[i].push_back((i+1)%k);
		v_[i].push_back((10*i)%k);
	}


	deque<int> q;
	q.push_front(1);
	d[1] = 1;	

	while(1){
		int p=q.front();
		q.pop_front();
		if(p==0) break;
		for(auto x: v_[p]){
			if(d[x]==0 || d[x]>d[p]){
				q.push_front(x);
				d[x]=d[p];
			}
		}

		for(auto x: v[p]){
			if(d[x]==0 || d[x]>d[p]+1){
				q.push_back(x);
				d[x]=d[p]+1;
			}
		}
	}

	cout << d[0] << endl;

	return 0;
}
