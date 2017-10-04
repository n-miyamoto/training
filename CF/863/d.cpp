#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define BUF (200005)

int n,q,m;
int a[BUF];
typedef struct {
        int t;
        int l;
        int r;
}Q;
Q qr[BUF];
int b[BUF];
void input(void){
        cin >> n >> q >> m;
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=1;i<=q;i++)cin >> qr[i].t >> qr[i].l >> qr[i].r ;
        for(int i=1;i<=m;i++)cin >> b[i];
}

int main(void){
	input();

	for(int i=1;i<=m;i++){
		for(int j=q;j>=1;j--){
			if(qr[j].l<=b[i] && qr[j].r>=b[i]){
				if(qr[j].t == 1){
					if(b[i]==qr[j].l) b[i] = qr[j].r;
					else b[i]-=1;
				}else{
					b[i] = qr[j].l+qr[j].r-b[i];
				}
			}
		}		
	}

	for(int i=1;i<=m;i++) cout << a[b[i]] << " ";
	cout << endl;
	return 0;
}
