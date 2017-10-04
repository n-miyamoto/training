#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <queue>

using namespace std;
#define BUF (100005)


int N,S;
int  s[BUF],a[BUF],b[BUF];

void input(void){
	cin >> N >> S;
}

int main(void){
	input();

	vector< pair<int,int> > vp1,vp2;
	long long  s1=0,s2=0;
	long long  c1=0,c2=0;


	for(int i=1;i<=N;i++){
		int a,b,s;
		cin >> s >> a >> b;
		if(a>b){
			c1+=s*(long long)a;
			s1+=s;
				vp1.push_back(make_pair(a-b,s));
		}else{
			c2+=s*(long long)b;
			s2+=s;
				vp2.push_back(make_pair(b-a,s));
		}		
	}

	if(s1%S+s2%S>S) //need to get more 2S slices. chose both
	{
		cout << c1+c2 <<endl;
	}else{			//need to get 1S slices, chose Aor BENIGN_RACE_BEGIN 
		long long  maxA=c1+c2;
		long long  maxB=c1+c2;
		int  tmp1=s1%S;
		int  tmp2=s2%S;
		sort(vp1.begin(), vp1.end());
		int cnt=0;
		for(int i=0;i<tmp1;i++){
		//	cout << maxA << endl;
			if(vp1[cnt].second >0){
				maxA-=(long long)vp1[cnt].first;
				vp1[cnt].second--;
			}else{
				cnt++;
				maxA-=(long long)vp1[cnt].first;
				vp1[cnt].second--;
			}
		}
		cnt = 0;
		sort(vp2.begin(), vp2.end());
		for(int i=0;i<tmp2;i++){
			if(vp2[cnt].second >0){
				maxB-=(long long)vp2[cnt].first;
				vp2[cnt].second--;
			}else{
				cnt++;
				maxB-=(long long)vp2[cnt].first;
				vp2[cnt].second--;
			}
		}
//		cout << maxA << maxB << endl;
		if(maxA>maxB) cout << maxA <<endl;
		else cout << maxB << endl;
	} 
	return 0;
}
