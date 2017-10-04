#include <stdio.h>

#define BUF (100)
#define INF (1000000)

int N, Ma, Mb;
int a[BUF], b[BUF], c[BUF];
void input(void) {
	scanf("%d %d %d",&N,&Ma,&Mb);
	int i = 0;
	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}
}


int min(int A, int B) {
	if (A> B )return B;
	if (B > A)return A;
}

int f(int A, int B, int i) {
	//printf("%d,%d,%d\r\n", A, B, i);
	if (i == N)return INF;
	if (A != 0 && Ma*B == Mb*A) {
		return 0;
	}
	int k = f(A, B, i + 1);
	int j = f(A + a[i], B + b[i], i + 1);
	return min(k, j + c[i]);
}

int main(void){
	input();
	int ret = f(0, 0, 0);
	if(ret>=INF)ret = -1;
	printf("%d", ret);
	return 0;
}
