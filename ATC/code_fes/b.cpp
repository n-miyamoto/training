#include <stdio.h>
#include <iostream>

using namespace std;

int N,M,K;
void input(void){
	cin >> N >> M >> K;
}

void show(void){
	cout << N << M << K;
}

int main(void){
	input();

	int flg = 0;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if(K==(j*(N-i)+i*(M-j))){
				flg = 1;
			}
		}
	}

	if(flg){
		cout << "Yes";
	}else{
		cout << "No";
	}

	cout << endl;


	return 0;
}
