#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define BUF (105)

int n;
int a[BUF];
void input(void){
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
}

int main(void){
	input();
	int flg[BUF];
	for(int i=0;i<BUF;i++)flg[i]=0;


	int max=0,sec=0;
	int max_ind=0;
	int sec_ind=0;
	for(int i=0;i<n;i++){
		flg[a[i]]+=1;	
	}

	int ttl=0;
	for(int i=0;i<BUF;i++){
		if(flg[i]>0){
			ttl++;
		}
	}

	if(ttl!=2){
		cout << "NO\n";
		return 0;
	}


	for(int i=0;i<BUF;i++){
		if(flg[i]>=max){
			sec = max;
			sec_ind = max_ind;
			max = flg[i];
			max_ind = i;
		}
	}	

	int P=0;
	int V=0;
	int p,v;	

	sort(flg,flg+BUF,greater<int>());

	
	for(int i=0;i<BUF;i++){

	}

	for(int i=0;i<BUF;i++){
		//cout << flg[i] <<endl ;

		if(i%2==0){
			P+=flg[i];
		}else{
			V+=flg[i];
		}
	}


	if(P==0 || V==0){	
		cout << "NO" << endl;
		return 0;
	}
	if(P==V){
		cout << "YES\n" ; 
		cout << max_ind << " " << sec_ind << endl;
	
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
