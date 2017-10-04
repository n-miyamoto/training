#include <stdio.h>
#include <iostream>

using namespace std;

int a,b,f,k;
void input(void){
	cin >> a >> b >> f >> k;
}

int main(void){
	input();

	int ans=0;
	int cnt=0;
	int F=b;
	for(int i=1; i<=k;i++){
		if(F<0){
			ans = -1;
			break;
		}
//		cout << F << endl;
		//not last
		if (i != k)
		{
			if (i % 2 == 1)
			{
				//->
				if (F - f < 0)
				{
					ans = -1;
					break;
				}
				else
				{
					if ((F - 2 * a + f) < 0)
					{
						F = b + f;
						cnt++;
					}
				}
				F -= a;
			}
			else
			{
				//<-
				if (F - a + f < 0)
				{
					ans = -1;
					break;
				}
				else
				{
					if ((F - a - f) < 0)
					{
						F = b + a - f;
						cnt++;
					}
				}
				F -= a;
			}
		}else{
//			cout << "last";
			//last
			if(i%2 ==1){
				if(F - f<0){
					ans = -1;
					break;
				}else{
					if((F-a)<0){
						F = b+f;
						cnt++;
					}
				}
				F-=a;
			}else{

//				cout <<"here";
				if(F-a+f<0){
					ans = -1;
					break;
				}else{
					if(F-a<0){
						F = b+a-f;
						cnt++;
					}
				}
				F -=a;
			}
		}
	}

	
	if(ans==-1 || F<0 ) {
		ans = -1;
		cout << ans <<endl;
		return 0;
	}

	ans = cnt;

	cout << ans << endl;

	return 0;
}
