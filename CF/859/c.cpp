#include <stdio.h>
#include <iostream>

#define BUF (100)

int N;
int a[BUF];
void input(void){
	std::cin >> N;
	for(int i=0;i<N;i++) std::cin >> a[i];	
}


int x[BUF];
int y[BUF];
int main(void){
	input();

	//init
	x[N-1]=a[N-1];
	y[N-1]=0;

	for(int i=N-2;i>=0;i--){
		if(x[i+1]>y[i+1]+a[i]){
			x[i] = x[i+1];
			y[i] = y[i+1]+a[i];
		}else{
			x[i] = y[i+1]+a[i];
			y[i] =  x[i+1];
		}
	}

	std::cout << y[0] << " " << x[0] << "\n";
	return 0;
}
