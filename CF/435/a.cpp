#include <stdio.h>
#include <iostream>
#define BUF (105)

int N;
int M;
int a[BUF];
int f[BUF];
void input(void){
	std::cin >> N;
	std::cin >> M;

	for(int i=0;i<N;i++) std::cin >> a[i];
}

int main(void){
	input();
	for(int i=0;i<N;i++){
		f[i] = 0; //init
	}
	for(int i=0;i<N;i++){	
		f[a[i]]=1;
	}

	int cnt = 0;
	for(int i=0;i<M;i++){
		if(f[i]==0){
			f[i]=1;
			cnt++;
		}
	}

	if(f[M]==1){
		cnt++;
	}

	std::cout <<  cnt << "\n";

	return 0;
}
