#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define BUF (200005)

int n;
int a[BUF];
int b[BUF];
priority_queue<int, vector<int>, greater<int> > q;

void input(void){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
}

int main(void){
	input();

	int f[BUF];
	for(int i=1;i<=n;i++)f[i]=0;
	for(int i=1;i<=n;i++)f[a[i]]++;
	for(int i=1;i<=n;i++)if(f[i]==0) q.push(i);
	for(int i=1;i<=n;i++)if(f[a[i]]==1)b[i]=a[i];

	for(int i=1;i<=n;i++){
		if(b[i]==0){
			if(f[a[i]]==1){
				b[i] = a[i];
			}else if(f[a[i]]==-1){
				if(!q.empty()){
					b[i]=q.top();
					q.pop();
				}else{
					b[i] = a[i];
				}
			}else{
				if(q.top()<a[i]){
						b[i] = q.top();
						q.pop();
						f[a[i]]--;
				}else{
					b[i] = a[i];
					f[a[i]] = -1;
				}
			}
		}
	}

	int c=0;
	for(int i=1;i<=n;i++) if(a[i]!=b[i]) c++;
	cout << c << endl;
	for(int i=1;i<=n;i++) cout << b[i]  << " ";
	cout << endl;
	return 0;
}
