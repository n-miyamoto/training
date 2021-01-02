#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int n;

#define MOD 1001

typedef int key;
key make_key(int i, int j){
	int a,b;
	if(i<j){
		a=i;b=j;
	}else{
		a=j;b=i;
	}
	return  a*MOD+b;
}

typedef struct node{
	key index;
	int pointed_count;
	std::vector<key> to;
	bool is_new; 
	bool is_exist;
} NODE;

std::vector<NODE> NODES(MOD*MOD);

std::vector<bool> is_used(MOD*MOD);
std::vector<int> cache(MOD*MOD, -1);



bool is_dag(key k){
	if(cache[k]==0) return false;
	if(cache[k]==1) return true;
	//cout << k << " ";
	is_used[k]=true;
	for(auto x : NODES[k].to){
		if(is_used[x]){
			cache[k] = 0;
			return false;
		}
		if(!is_dag(x)){
			cache[k] = 0;
			return false;
		}
	}
	is_used[k]=false;
	cache[k] = 1;
	return true;
}

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		int prev = 0;
		for(int j=1;j<=n-1;j++){
			int tmp;
			cin >> tmp;

			NODES[make_key(i,tmp)].is_exist = true;
			NODES[make_key(i,tmp)].index = make_key(i,tmp);

			//cout << tmp << i << " " <<  make_key(i,tmp) << " "   << endl;
			if(prev!=0){
				//cout << prev << endl;
				NODES[make_key(i,tmp)].pointed_count++;
				NODES[make_key(i,prev)].to.push_back(make_key(i,tmp));
			}
			prev = tmp;
		}
	}


	std::vector<key> root_nodes;
	for(auto nd : NODES){
		if(nd.is_exist&& nd.pointed_count==0){
			root_nodes.push_back(nd.index);
			//cout << nd.index << endl;
		}
	}
	
	if(root_nodes.empty()){
		cout << -1 << endl;
		return 0;
	}

	// check dag or not
	for(auto nd : root_nodes){
		if(!is_dag(nd))
		{
			cout << -1 << endl;
			return 0;
		}
	}



	int ret = 1;
	while(1){
		vector<int> tmp;
		for(auto nd : root_nodes){
			for(auto x : NODES[nd].to){
				NODES[x].pointed_count--;
				if(0==NODES[x].pointed_count) tmp.push_back(x);
			}
			NODES[nd].is_exist = false;
		}
		if(tmp.empty()) break;
		ret++;
		root_nodes.clear();
		root_nodes.resize(tmp.size());
		int l=0;
		for(auto x : tmp){
			root_nodes[l]=x;
			l++;
		}
	}

	cout << ret << endl;
	return 0;
}
