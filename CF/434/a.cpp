#include <stdio.h>
#include <iostream>
#include <string.h>

#define BUF (10005)

char str[BUF];
void input(void){
	std::cin >> str;
}

int main(void){
	input();

	int sz = strlen(str);
	char tmp[BUF];
	int cnt=0;
	int flag=0;
	for(int i=0;i<sz;i++){
		switch(str[i]){
			case 'a':
				flag = 0;	
				break;
			case 'i':
				flag=0;
				break;
			case 'u':
				flag = 0;
				break;
			case 'e':
				flag = 0;
				break;
			case 'o':
				flag = 0;
				break;
			default:
				if(flag>=2){
					if(str[i-2]==str[i] && str[i-1]==str[i]){
						flag++;
					}else{
						tmp[cnt]=' ';
						cnt++;
						flag = 1;
					}
				}else{
					flag++;
				}
				break;
		}
		tmp[cnt] = str[i];
		tmp[cnt+1] = '\0';
		cnt++;
	}

	std::cout << tmp <<"\n";
	return 0;
}
