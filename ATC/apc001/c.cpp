#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
char s[BUF]; 

int main(void){
	cin >> n;

	//first query.
	cout << 0 << "\n";	
	char res[BUF];
	cin >> res;
	if(res[0]=='V') return 0;
	s[0]=res[0];



	int bgn=0;
	int end=n-1;	
	while(1){
		int mid = (bgn+end+1)/2;
		cout << mid << "\n";
		cin >> res;
		if(res[0]=='V') return 0;

		s[mid]=res[0];

		if((bgn-mid)%2==0){
			if(s[bgn]!=s[mid]) end = mid;			
			else bgn = mid;
		}else{
			if(s[bgn]!=s[mid]) bgn = mid;			
			else end = mid;
			
		}
	}


	return 0;
}
