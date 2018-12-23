#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
int v[BUF];
int v_odd[BUF];
int v_even[BUF];

int odd1, even1;
int odd2, even2;
int odd_max, odd_second;
int even_max, even_second;
int ans;

int main(void){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> v[i];
		if(i%2) v_odd[v[i]]++;
		else   v_even[v[i]]++;
	}

	for(int i=0;i<BUF;i++){
		if(v_odd[i]>odd_max){
			odd_second = odd_max;
			odd_max = v_odd[i];
			odd2 = odd1;
			odd1 = i;
		}else if(v_odd[i]>odd_second){
			odd_second = v_odd[i]; 
			odd2 = i;
		}
		
		if(v_even[i]>even_max){
			even_second = even_max;
			even_max = v_even[i];
			even2 = even1;
			even1 = i;
		}else if(v_even[i]>even_second){
			even_second = v_even[i]; 
			even2 = i;
		}
	}


	if(odd1!=even1){
		cout << n-odd_max - even_max << endl;
	}else{
		cout << n-max(odd_max+even_second, odd_second+even_max) << endl;
	}

	return 0;
}

