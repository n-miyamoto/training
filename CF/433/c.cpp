#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define BUF (300005)

int n,k;
int  c[BUF];
void input(void){
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> c[i];
}

vector<int> v;
int main(void){
	input();

	int t[BUF];
	long long ct=0;
	for(int i=1;i<=k;i++) v.push_back(c[i]);
	for(int i=k+1;i<=k+n;i++){
		v.push_back(c[i]);
		int ind = 1+distance(v.begin(),max_element(v.begin(), v.end()));
		//cout << ind << " " << i;
		ct+=v[ind-1]*(i-ind);
		v[ind -1 ]= 0;
		//v.erase(v.begin() + ind-1);
		t[ind] = i;
	}

	cout << ct << endl;
	for(int i=1;i<=n;i++) cout << t[i] << " ";
	cout << endl;
	return 0;
}
