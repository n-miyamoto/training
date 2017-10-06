#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define BUF (101)
#define g (10)

int N,H,R,T;
float x[BUF];
float period;
std::vector<float> v;

void input(void){
	scanf("%d",&N);
	scanf("%d",&H);
	scanf("%d",&R);
	scanf("%d",&T);
}

void show(void){
	printf("N:%d, H:%d, R:%d, T:%d \r\n",N,H,R,T);
}

void calc_period(void){
	period = sqrt(2*H/g);
}

float height(float t){
	float height =0;
	float t_;
       t_= fmod(t,2*period);
	if(t_<period){
		height=-0.5*g*t_*t_ +H;
	}else{
		height=-0.5*g*(t_-2*period)*(t_-2*period)+H;
	}
	return height;
}

int solve(void){
	int i=0;
	for(i=0;i<N;i++){
		v.push_back(height(T-i));
		
	}
	
	std::sort(v.begin(),v.end());
	
	for(i=0;i<N;i++){
		v[i]+=2*R*i;
		printf("%d;%f\r\n",i,v[i]);
	}	

	return 0;
}



int main(void){
	input();
	show();
	calc_period();
	height(1);
	solve();
	
	return 0;
}

