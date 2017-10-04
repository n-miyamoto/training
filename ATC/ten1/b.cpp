#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (100005)

int n;
int A[BUF];
int B[BUF];
void input(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> A[i] >> B[i];
}

int main(void){
	input();

	int max =0;
	int max_ind = 0;
	for(int i=1;i<=n;i++){
		if(A[i]>max){
			max = A[i];
			max_ind = i;
		}
	}

	cout << A[max_ind] + B[max_ind] <<endl ;
	return 0;
}
