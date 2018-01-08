#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int q;
bool pn[BUF];
int  cnt[BUF];
bool n17[BUF];

bool isprm(int num)
{
    double sqnum = sqrt(num);
    for (int i = 3; i <= sqnum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


int main(void){
	pn[2]=1;
	for(int i=3;i<BUF;i+=2){
		pn[i] = isprm(i);	
		if(pn[i] && pn[(i+1)/2]) n17[i]=true;
	}

	int c=0;
	for(int i=0;i<=BUF;i++){
		if(n17[i])c++;
		cnt[i] = c;
	}

	
	cin >> q;
	for(int i=0;i<q;i++){
		int l,r;
		cin >> l >> r;

		cout << cnt[r] - cnt[l-1] << "\n";
	}
	return 0;
}
