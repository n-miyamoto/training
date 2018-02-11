#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int N;
long long T[BUF];
void input(void){
	cin >> N;
	for(int i=1;i<=N;i++) cin >> T[i];
}

long long gcd(long long a, long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}

long long lcm(long long a,long long b){
	long long g = gcd(a,b);
	return a/g*b;
}

int main(void){
	input();

	long long  ans=1;
	for(int i=1;i<=N;i++){
		ans = lcm(ans,T[i]);
	}
	cout << ans << endl;
/*	sort(T+1,T+N+1);

	long long b = T[N];
	long long cnt = 1;
	while(1){
		int f=1;
		for(int i=N-1;i>0;i--){
			if(((long long)cnt*b)%T[i]!=0){
				f=0;
				break;
			}			
		}
		if(f==1) break;
		cnt++;
	}
	cout << (long long)cnt*b << endl;
*/
	return 0;
}
