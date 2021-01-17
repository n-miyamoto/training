#define WIDTH 640
#define KERNEL_SIZE 9

__kernel void vadd(__global float* src, __global float* dst, __global float* kn)
{
    int id= get_global_id(0);
    int idx = id%WIDTH;
    int idy = id/WIDTH;

    float sum = 0;
	for(int ky=0;ky<KERNEL_SIZE;ky++){
		for(int kx=0;kx<KERNEL_SIZE;kx++){
			float tmp = src[(WIDTH+ky)*idy+idx+kx];
			sum += kn[ky*KERNEL_SIZE + kx]*tmp;
		}
	}

    dst[id] = sum;
}
 