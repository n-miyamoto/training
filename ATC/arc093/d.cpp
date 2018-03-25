#include <bits/stdc++.h>

using namespace std;
#define BUF (105)
#define ll long long 

int a;
int b;
char A[BUF][BUF];

int main(void){
	cin >> a >> b;

	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++) {
			if(j<50) A[i][j]='.';
			else A[i][j] ='#';
		}
	}

	a--;
	b--;
	int cnt = 0;
	while(b>cnt){
		A[ 2*(cnt%50)][2*(cnt/50) ] = '#';
		cnt++;
	}

	cnt=0;
	while(a>cnt){
		A[ 2*(cnt%50)][99-2*(cnt/50) ] = '.';
		cnt++;
	}
	
	cout << 100 << "  " << 100 << "\n";
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++) {
			cout << A[i][j];
		}
		cout << "\n";
	}

	return 0;
}
