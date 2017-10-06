#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (2005)

int n;
int x[BUF];
int y[BUF];
void input(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> x[i];
	for(int i=1;i<=n;i++) cin >> y[i];
}

int main(void){
	input();

	int cnt=0;

	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){

		int temp = (int)(x[i]^y[j]);
		int flag = 0;
		int min = 1;
		int max = n; 
		int ptr ;
		
		while(min<=max){
			ptr = (min+max)/2;
			if(temp==x[ptr]){
				flag = 1;
				break;
			}else if(temp<x[ptr]){
				max = ptr-1;
			}else{
				min = ptr+1;
			}

		}
		if(flag ==1){
			cnt++;
			//cout<< "1" << i << j << endl;
		}

		min = 1;
		max = n;
		ptr = n/2;
		while(min<=max){

			ptr = (min+max)/2;
			if(temp==y[ptr]){
				flag = 1;
				break;
			}else if(temp<y[ptr]){
				max = ptr-1;
			}else{
				min = ptr+1;
			}
		}

		if(flag == 1){
			cnt++;
			//cout<< "2" << i << j << endl;
		}
	}
	
	if(0==(cnt)%2) cout <<"Karen" <<endl;
	else cout << "Koyomi" <<endl;

//	cout << cnt;
	return 0;
}
