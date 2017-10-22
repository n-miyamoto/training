#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)

char s[BUF]; 

int main(void){
	cin >> s;

	for(int i=0;i<strlen(s)-1;i++){
		if(s[i] == 'A' && s[i+1] == 'C' ){
			 cout << "Yes" << endl;
			 return 0; 
		}
	}


	cout << "No" << endl;
	
	return 0;
}
