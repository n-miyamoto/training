#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)

char s[4];
int A,B,C,D;

int main(void){
	cin >> s;
	A = s[0]-0x30;
	B = s[1]-0x30;
	C = s[2]-0x30;
	D = s[3]-0x30;

	int ans;
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++){
		ans = A + (2*i-1)*B + (2*j-1)*C + (2*k-1)*D;
		if(ans==7){
			cout << A;
			i==0 ? cout << "-" : cout << "+";
			cout << B;
			j==0 ? cout << "-" : cout << "+";
			cout << C;
			k==0 ? cout << "-" : cout << "+";
			cout << D << "=7\n"; 
			return 0;
		}
	}	
	return 0;
}
