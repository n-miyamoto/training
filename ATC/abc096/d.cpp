#include <bits/stdc++.h>

using namespace std;
#define BUF (55560)
#define ll long long 

int n;

char f[BUF];
vector<int> v;


bool isprm(int num)
{
    double sqnum = sqrt(num+1);
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
	cin >> n;
	int cnt = 0;
	
	for(int i=11;i<BUF;i+=10){
		if(isprm(i)==true && i%5==1){
			v.push_back(i);
			cnt++;
		}
		if(cnt==n) break;
	}
	for(int i=0;i<n;i++){
		cout << v[i] << " ";  
	}
	cout << endl;
	return 0;
}
