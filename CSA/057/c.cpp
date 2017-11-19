#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)

int n,k;

int f[BUF],h[BUF];
int v[BUF];

int main(void){
	cin >> n >> k;
	for(int i=0;i<k;i++){
		int tmp;
		cin >> tmp;
		f[tmp] = 1;
	}
	for(int i=0;i<k;i++){
		int tmp;
		cin >> tmp;
		h[tmp] = 1;
	}

	int cnt = 0;

	for(int i=1;i<=n;i++){
		if(f[i]==0)continue;

		if(i==1){
			if(h[n]==1&&h[2]==0){
				cnt++;
				f[1]=0;
				h[n]=0;
			}else if(h[2]==1&&h[n]==0){
				cnt++;
				f[1]=0;
				h[2]=0;
			}
		}else if(i==n){
			if(h[n-1]==1&&h[1]==0){
				cnt++;
				f[n]=0;
				h[n-1]=0;
			}else if(h[1]==1&&h[n-1]==0){
				cnt++;
				f[n]=0;
				h[1]=0;
			}
		}else {
			if(h[i-1]==1&&h[i+1]==0){
				cnt++;
				f[i]=0;
				h[i-1]=0;
			}else if(h[i+1]==1&&h[i-1]==0){
				cnt++;
				f[i]=0;
				h[i+1]=0;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(f[i]==0)continue;

		if(i==1){
			if(h[n]==1&&h[2]==0){
				cnt++;
				f[1]=0;
				h[n]=0;
			}else if(h[2]==1&&h[n]==0){
				cnt++;
				f[1]=0;
				h[2]=0;
			}
		}else if(i==n){
			if(h[n-1]==1&&h[1]==0){
				cnt++;
				f[n]=0;
				h[n-1]=0;
			}else if(h[1]==1&&h[n-1]==0){
				cnt++;
				f[n]=0;
				h[1]=0;
			}
		}else {
			if(h[i-1]==1&&h[i+1]==0){
				cnt++;
				f[i]=0;
				h[i-1]=0;
			}else if(h[i+1]==1&&h[i-1]==0){
				cnt++;
				f[i]=0;
				h[i+1]=0;
			}
		}
	}


	for(int i=1;i<=n;i++){
		if(f[i]==0)continue;

		if(i==1){
			if(h[n]==1){
				cnt++;
				f[1]=0;
				h[n]=0;
			}else if(h[2]==1){
				cnt++;
				f[1]=0;
				h[2]=0;
			}
		}else if(i==n){
			if(h[n-1]==1){
				cnt++;
				f[n]=0;
				h[n-1]=0;
			}else if(h[1]==1){
				cnt++;
				f[n]=0;
				h[1]=0;
			}
		}else {
			if(h[i-1]==1){
				cnt++;
				f[i]=0;
				h[i-1]=0;
			}else if(h[i+1]==1){
				cnt++;
				f[i]=0;
				h[i+1]=0;
			}
		}
	}

	for(int i=1;i<=n;i++){
		if(f[i]==1) cnt+=2;
	}

/*
	//0 -> 0 , right only -> 1 left only -> 2 , both 3;
	for(int i=1;i<=n;i++){
		if(f[i]==0) continue;

		if(i==1){
			v[1] = 2*h[n] + h[2];			
		}else if(i==n){
			v[n] = 2*h[n-1]+h[1];
		}else{
			v[i] = 2*h[i-1]+h[i+1];
		}
	}


	//ikko
	int cnt = 0;
	for(int i=1;i<n;i++){
		if(v[i]==1&&h[i+1]==1){
			cnt++;
			f[i]=0;
			h[i+1]=0;
		}
	}
	for(int i=2;i<=n;i++){
		if(v[i]==2&&h[i-1]==1){
			cnt++;
			f[i]=0;
			h[i-1]=0;
		}
	}

	//nokori	
	for(int i=1;i<=n;i++){
		if(f[i]==0) continue;

		if(i==1){
			if(h[n]==1){
				cnt++;
				h[n]=0;
				f[1]=0;
			}else if(h[2]==1){
				cnt++;
				h[2]=0;
				f[1]=0;
			}
		}else if(i==n){
			if(h[1]==1){
				cnt++;
				h[1]=0;
				f[n]=0;
			}else if(h[n-1]==1){
				cnt++;
				h[n-1]=0;
				f[n]=0;
			}
		}else{
			if(h[i-1]==1){
				cnt++;
				h[i-1]=0;
				f[i]=0;
			}else if(h[i+1]==1){
				cnt++;
				f[i+1]=0;
				f[i]=0;
			}
		}

	}

	for(int i=1;i<=n;i++){
		if(f[i]==1) cnt+=2;
	}
*/
	cout << cnt << endl;	

	return 0;
}
