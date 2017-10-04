#include <stdio.h>
#include <string.h>

#define BUF (100005)

char s[BUF];
void input(void){
	scanf("%s",s);
}

int main(void){
	input();

	char tmp[BUF]="";
	int cnt=0;
	for(int i=0;i<strlen(s);i++){
		if(i%2==0){
			tmp[cnt] = s[i];
			cnt++;
		}
	}
	printf("%s\n",tmp);
	return 0;
}
