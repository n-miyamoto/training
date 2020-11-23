#include <bits/stdc++.h>

using namespace std;
#define BUF (1505)
#define ll long long 

int H,W,N,M;
char m[BUF][BUF];
char d[BUF][BUF];

template<typename T>
void show(T* ptr){
	for(int i=0; i<H;i++){
		for(int j=0; j<W;j++){
			cout << ptr[BUF * i + j];
			cout << " ";
		}
		cout << "\n";
	}
}

int main(void){
	//input HWNM
	cin >> H >> W >> N >> M;

	//initialize map
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			d[i][j] = '.';
			m[i][j] = '.';
		}
	}

	// input axis
	for(int i=0;i<N;i++){
		int A,B;
		cin >> A >> B;
		m[A-1][B-1] = 'l';
	}

	for(int i=0;i<M;i++){
		int C,D;
		cin >> C >> D;
		m[C-1][D-1] = 'b';
	}

	//right direction scan
	for(int i=0;i<H;i++){
		bool is_blight = false;
		for(int j=0;j<W;j++){
			if(m[i][j] == 'l') is_blight = true;
			else if(m[i][j] == 'b') is_blight = false;

			if(is_blight) d[i][j] = 'B';
		}
	}

	//left direction scan
	for(int i=0;i<H;i++){
		bool is_blight = false;
		for(int j=W-1;j>=0;j--){
			if(m[i][j] == 'l') is_blight = true;
			else if(m[i][j] == 'b') is_blight = false;

			if(is_blight) d[i][j] = 'B';
		}
	}

	//down direction scan
	for(int j=0;j<W;j++){
		bool is_blight = false;
		for(int i=0;i<H;i++){
			if(m[i][j] == 'l') is_blight = true;
			else if(m[i][j] == 'b') is_blight = false;

			if(is_blight) d[i][j] = 'B';
		}
	}
	
	//up direction scan
	for(int j=0;j<W;j++){
		bool is_blight = false;
		for(int i=H-1;i>=0;i--){
			if(m[i][j] == 'l') is_blight = true;
			else if(m[i][j] == 'b') is_blight = false;

			if(is_blight) d[i][j] = 'B';
		}
	}
	
	//count all blight cell
	int ans = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(d[i][j] == 'B') ans++;
		}
	}

	cout << ans << endl;

	//show<char>((char*)m);
	//show<char>((char*)d);
	
	return 0;
}
