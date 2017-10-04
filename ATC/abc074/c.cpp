#include <stdio.h>

int A,B,C,D,E,F;
void input(void){
	scanf("%d %d %d %d %d %d",&A,&B,&C,&D,&E,&F);
}

#define BUF (3005)


int main(void){
	input();
	int x[BUF];
	int y[BUF];
	for(int i=0;i<BUF;i++){
		x[i] = 0;
		y[i] = 0;
	}

	for(int i=0;i<=F;i++){
		for(int j=0;j<=F;j++){
			int w = (A*i+B*j)*100;
			if(w<F){
				x[w]=1;
			}

			int s = C*i+D*j;
			if(s<F){
				y[s]=1;
			}
		}
	}
	

	int max_w=0;
	int max_s=0;
	for(int i=1;i<=F;i++){
		for(int j=1;j<=F;j++){
			if(x[i] && y[j]){
				//printf("%d %d\n",i,j);
				if(i+j<=F){
					if(100*j<=E*i){
						if(max_w==0){
							max_w = i+j;
							max_s = j;
						}
						else if(max_s*(j+i)<j*max_w){
							max_w = i+j;
							max_s = j;
						}
					}
				}	
			}
		}
	}	
	printf("%d %d\r\n",max_w,max_s);
	return 0;
}