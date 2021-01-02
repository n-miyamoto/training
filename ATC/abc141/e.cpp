#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

int N;
std::string S;

int zalgo(std::string& s){
	int ret = 0;
	int n = s.length();
	vector<int> z(n,0);

	int L=0, R=0;

	for(int i=1;i<n;i++){
		if(i>R){
			L=R=i;
			while(R<n && s[R-L] == s[R]) R++;
			z[i] = R-L;
			R--;
		}else{
			int k=i-L;
			if(z[k]<R-i+1) z[i] = z[k];
			else{
				L=i;
				while(R<n && s[R-L] == s[R]) R++;
				z[i] = R-L;
				R--;
			}
		}
		//ret = std::max(ret, z[i]);
	}

	for(int i=1;i<n;i++){
		ret = std::max(ret, std::min(z[i],i));
	}
	return ret;
}

int main(void){
	cin >> N;
	cin >> S;
	int ret = 0;
	for(int i=0;i<N;i++){
		std::string sub = S.substr(i,N-i);
		ret = std::max(ret, zalgo(sub));
	}

	if(ret<=0) cout << 0 << endl;
	else cout << ret << endl;

	return 0;
}
