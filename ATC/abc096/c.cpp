#include <bits/stdc++.h>

using namespace std;
#define BUF (100)
#define ll long long 

int h,w;

char s[BUF][BUF];

int main(void){
	cin >> h >> w;

    for(int y=0;y<=h+1;++y){
		for(int x=0;x<=w+1;++x){
			s[y][x]='.';
		}
	}


    for(int y=1;y<=h;++y){
		for(int x=1;x<=w;++x){
			cin >> s[y][x];
		}
	}

	for(int y=1;y<=h;++y){
		for(int x=1;x<=w;++x){
			if(s[y][x]=='#'){
				if(s[y+1][x]=='.' && s[y][x+1]=='.' && s[y-1][x]=='.' && s[y][x-1]=='.' ){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}


	cout << "Yes" << endl;

	return 0;
}
