#include <arm_neon.h>
#include <iostream>
#include <time.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define KERNEL_SIZE 9

#define MOD 123456789

float src[(WIDTH+KERNEL_SIZE/2*2)*(HEIGHT+KERNEL_SIZE/2*2)];
float dst[WIDTH*HEIGHT];
float dst_opt[WIDTH*HEIGHT];

float kn[KERNEL_SIZE*KERNEL_SIZE];

int main(int argc, char** argv)
{
	//initialize data
	srand(0);
	for(int y=0;y<HEIGHT;y++){
		for(int x=0;x<WIDTH;x++){
			src[(WIDTH+KERNEL_SIZE/2)*y+x+KERNEL_SIZE/2] = (float)rand()/RAND_MAX;		
		}
	}
	for(int k=0;k<KERNEL_SIZE*KERNEL_SIZE;k++){
		kn[k] = (float)rand()/RAND_MAX;		
	}

	//naive convolution
	clock_t c_start, c_end;
	c_start = clock();
	for(int y=0;y<HEIGHT;y++){
		for(int x=0;x<WIDTH;x++){
			float sum = 0;
			for(int ky=0;ky<KERNEL_SIZE;ky++){
				for(int kx=0;kx<KERNEL_SIZE;kx++){
					float tmp = src[(WIDTH+ky)*y+x+kx];
					sum += kn[ky*KERNEL_SIZE + kx]*tmp;
				}
			}
			dst[WIDTH*y+x] = sum;
		}
	}
	c_end = clock();
	printf("naive exec : %f[s]\n", (double)(c_end - c_start) / CLOCKS_PER_SEC);

	//optimized convolution 
	c_start = clock();
	const int block_x = 8; //640, 1,2,4,8,16,32,64
	const int block_y = 8; //480, 1,2,4,8,16,32
	const int x_stride = WIDTH/block_x;
	const int y_stride = HEIGHT/block_y;
	for(int by=0;by<block_y;by++){
		for(int bx=0;bx<block_x;bx++){
			for(int y=0;y<y_stride;y++){
				int index_y = (by*y_stride+y);
				for(int x=0;x<x_stride;x++){
					float sum1 = 0;
					float sum2 = 0;
					float sum3 = 0;
					const int index_x = (bx*x_stride+x);
					const float z[4] = {0,0,0,0};

					float32x4_t vsum1  = vld1q_f32(z);
					float32x4_t vsum2  = vld1q_f32(z);
					float32x4_t vsum3  = vld1q_f32(z);

					for(int ky=0;ky<KERNEL_SIZE;ky+=3){
						const int k1 = ky*KERNEL_SIZE;
						const int k2 = k1 + KERNEL_SIZE;
						const int k3 = k2 + KERNEL_SIZE;

						const int w1 = (WIDTH+ky)*index_y;
						const int w2= w1 + index_y;
						const int w3= w2 + index_y;

						float32x4_t vkn1  = vld1q_f32(&kn[k1]);
						float32x4_t vsrc1 = vld1q_f32(&src[w1 + index_x]);
						vsum1 = vmlaq_f32(vsum1, vkn1, vsrc1);

						float32x4_t vkn2  = vld1q_f32(&kn[k1 + 4]);
						float32x4_t vsrc2 = vld1q_f32(&src[w1 + index_x+ 4]);
						vsum1 = vmlaq_f32(vsum1, vkn2, vsrc2);

						float32x4_t vkn3  = vld1q_f32(&kn[k2]);
						float32x4_t vsrc3 = vld1q_f32(&src[w2+ index_x]);
						vsum2 = vmlaq_f32(vsum2, vkn3, vsrc3);

						float32x4_t vkn4  = vld1q_f32(&kn[k2 + 4]);
						float32x4_t vsrc4 = vld1q_f32(&src[w2+ index_x + 4]);
						vsum2 = vmlaq_f32(vsum2, vkn4, vsrc4);

						float32x4_t vkn5  = vld1q_f32(&kn[k3]);
						float32x4_t vsrc5 = vld1q_f32(&src[w3 + index_x]);
						vsum3 = vmlaq_f32(vsum3, vkn5, vsrc5);

						float32x4_t vkn6  = vld1q_f32(&kn[k3 + 4]);
						float32x4_t vsrc6 = vld1q_f32(&src[w3 + index_x+ 4]);
						vsum3 = vmlaq_f32(vsum3, vkn6, vsrc6);
						sum1 += kn[k1+ 8]*src[w1+index_x+8];

						sum2 += kn[k2+ 8]*src[w2+index_x+8];
						sum3 += kn[k3+ 8]*src[w3+index_x+8];
					}

					dst_opt[WIDTH*index_y+index_x] = vaddvq_f32(vsum1) + vaddvq_f32(vsum2) + vaddvq_f32(vsum3) +
									 sum1 + sum2 + sum3;
				}
			}
		}
	}
	c_end = clock();
	printf("opt exec : %f [s] \n", (double)(c_end - c_start) / CLOCKS_PER_SEC);

	int check = 1;
	for(int y=0;y<HEIGHT;y++){
		for(int x=0;x<WIDTH;x++){
			if(fabs(dst[y*WIDTH+x]-dst_opt[y*WIDTH+x]) > 1e-4 ){
			       	check=0;
			}
		}
	}

	if(!check) printf("NG!!!\n");
	else printf("OK!!!\n");
	return 0;
}

