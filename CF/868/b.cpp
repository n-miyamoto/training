#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define BUF (1000)

int h,m,s,t1,t2;
void input(void){
	cin >> h >> m >> s >> t1 >> t2;
}

int main(void){
	input();

	h*=5;;
	t1*=5;
	t2*=5;

	h =( h-t1+60)%60;
	m =( m-t1+60)%60;
	s =( s-t1+60)%60;
	t2=(t2-t1+60)%60;

	if(t2<=m && t2<=s && t2 <=h){
		cout << "YES" << endl;
		return 0;
	}

	
	if(t2>m && t2>s && t2 >h){		
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" <<endl;
	return 0;
}
