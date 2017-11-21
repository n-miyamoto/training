#include <bits/stdc++.h>
//#include <stdio.h>
//#include <iostream>
//#include <algorithm>

using namespace std;
#define BUF (1000)

int H,W;
char s[52][52];

typedef struct{
	int row;
	int col;
} P;

vector<P> p;

int main(void){
	cin >> H >> W;
	for(int i=0;i<H;i++){
		 cin >> s[i];
		 for(int j=0;j<W;j++){
			 if('#'==s[i][j]){
				P temp;
				temp.row = i;
				temp.col = j;
				p.push_back(temp);
			}else{
				s[i][j]='0';
			}
		}
	}
	while(!p.empty()){
		for(int i=max(0,p.back().row-1);i<=min(H-1,p.back().row+1);i++){
			for(int j=max(0,p.back().col-1);j<=min(W-1,p.back().col+1);j++){
				if(s[i][j]!='#') s[i][j]++;
			}	
		}
		p.pop_back();
	}
	for(int i=0;i<H;i++){
		cout << s[i] << "\n";
	}
	return 0;
}
