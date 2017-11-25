#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

char s[BUF] ;

int main(void){
	cin >> s;

	char str[16][BUF] = {
		"KIHBR",
		"KIHBRA",
		"KIHBAR",
		"KIHBARA",
		"KIHABR",
		"KIHABRA",
		"KIHABAR",
		"KIHABARA",
		"AKIHBR",
		"AKIHBRA",
		"AKIHBAR",
		"AKIHBARA",
		"AKIHABR",
		"AKIHABRA",
		"AKIHABAR",
		"AKIHABARA",
		};

	for(int i=0;i<16;i++){
		if(0==strcmp(s,str[i])){
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}

