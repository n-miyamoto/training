#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (200005)

int N,M;
int D[BUF];
int T[BUF];
void input(void){
	cin >> N;
	for(int i=1;i<=N;i++ ) cin >> D[i];
	cin >> M;
	for(int i=1;i<=M;i++ ) cin >> T[i];
}

int main(void){
	input();

	if(N<M){ 
		cout << "NO" << endl;
		return 0;
	}

	sort(D+1,D+N+1);
	sort(T+1,T+M+1);

	int pn=1,pm=1;
	for(int i=1;i<=N;i++){
	//	cout << D[i] << " " << T[pm] << endl;
		if(T[pm]==D[i]){
			pm++;
		}else if(T[pm]<D[i]){
			cout << "NO" <<endl;
			return 0;
		}		

		if(pm>M){
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
	return 0;
}
