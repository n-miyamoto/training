#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;

    int cleanPlain = 0, cleanLogo = 0;
	int ans = 0;

    for (char day : S) {
		switch (day)
		{
		case '0':
    		cleanPlain = 0, cleanLogo = 0;
			break;

		case '1':
			if (cleanPlain==M){
				cleanLogo++;
			}else{
				cleanPlain++;
			}
			break;

		case '2':
			cleanLogo++;
			break;
		
		default:
			break;
		}

		ans = max(ans, cleanLogo);
    }

    cout << ans << endl;
    return 0;
}