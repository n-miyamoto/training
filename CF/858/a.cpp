#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

long long  n,k;
void input(void){
	cin >> n >>k;
}

int main(void){
	input();

	long long c2=0,c5=0;
	long long  tmp=n;
	while(1){
		if(tmp%2==0){
			c2++;
			tmp=tmp/2;
		}else{
			break;
		}
	}
	tmp=n;
	while(1){
		if(tmp%5==0){
			c5++;
			tmp=tmp/5;
		}else{
			break;
		}
	}

	//cout <<c2 << c5;

	if(c2>k) c2=k;
	if(c5>k) c5=k;

	int ans =1;
	for(int i=0;i<k-c2;i++) ans*=2;
	for(int i=0;i<k-c5;i++) ans*=5;

	cout << n*ans << endl;
	return 0;

}
