#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 

int n;
int T1[BUF];
int T2[BUF];
char s[BUF];
vector<int> v1[BUF]; 
vector<int> v2[BUF];
set<pair<int,int>> s1; 

int main(void){
	int cnt=0;
	cin >> n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		pair<int,int> p1 = make_pair(a,b);
		pair<int,int> p2 = make_pair(b,a);
		s1.insert(p1);
		s1.insert(p2);
	}
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		pair<int,int> p1 = make_pair(a,b);
		pair<int,int> p2 = make_pair(b,a);
		if(s1.find(p1)!=s1.end())cnt++;
		if(s1.find(p2)!=s1.end())cnt++;

	}

	cout << cnt/2 << endl;

	return 0;
}
