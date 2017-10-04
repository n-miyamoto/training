#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int N;
void input(void){
	cin >> N;
}

int main(void){
	input();

	for(int h=1;h<=3500;h++){ //h>n>w	
		for(int n=1;n<=3500;n++){
			long long cu = (long long)N*h*n;
			long long cd = (long long)4*h*n-(long long)h*N-(long long)n*N;
			long long w;
		//	cout << cu << cd ;
			if(cd==0) break;
			
			if(cu%cd==0 && cu/cd>0) {
				w=cu/cd;
				cout <<h << " " << n << " " << w << endl;
				return 0;
			}
		}
	}


	return 0;
}
