#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define BUF (1000)

char s[10];
void input(void){
	cin >> s;
}

int a[10];
int main(void){
	input();

	int size = strlen(s);

	int cnt = size-1;
	while(1){
		if(s[cnt]=='0'){
			size--;
			cnt--;
		}else{
			break;
		}		
	}

//	cout << s << size;

	for(int i=0;i<size;i++){
		if(s[i]!=s[size-1-i]){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl; 

	return 0;
}
