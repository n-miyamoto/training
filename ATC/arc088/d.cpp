#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
char s[BUF];

int main(void){
	cin >> s;
	n=strlen(s);

	int z=1;
	int o=1;
	int left,right;
	left=n/2;
	right=n/2-1+n%2;

	int k=s[left];
	while(s[left]==k && s[right]==k){
		k=s[left];
		
		left++;
		right--;
		if(left>n-1)break;
		if(right<0 )break;
	}
	cout << left << endl;
	return 0;
}
		

