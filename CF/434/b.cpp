#include <stdio.h>
#include <iostream>
#include <vector>

#define BUF (70005)

char pn[BUF][10];
int N;
std::vector<int> u[BUF];
std::vector<int> v[BUF];

void input(void){
	std::cin >> N;
	for(int i=0;i<N;i++){
		std::cin >> pn[i];
	}	
}

void show(void){
	for(int i=0;i<N;i++){
		std::cout << pn[i];
	}	
}

int main(void){
	input();
	show();
	return 0;
}
