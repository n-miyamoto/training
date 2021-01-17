#define WIDTH 640
#define KERNEL_SIZE 9

__kernel void vadd(__global float* src, __global float* dst, __global float* kn)
{
    int id= get_global_id(0);
    int idx = id%WIDTH;
    int idy = id/WIDTH;

    float sum = 0;
	for(int ky=0;ky<KERNEL_SIZE;ky++){
		sum += kn[ky*KERNEL_SIZE + 0]*src[(WIDTH+ky)*idy+idx+0];
		sum += kn[ky*KERNEL_SIZE + 1]*src[(WIDTH+ky)*idy+idx+1];
		sum += kn[ky*KERNEL_SIZE + 2]*src[(WIDTH+ky)*idy+idx+2];
		sum += kn[ky*KERNEL_SIZE + 3]*src[(WIDTH+ky)*idy+idx+3];
		sum += kn[ky*KERNEL_SIZE + 4]*src[(WIDTH+ky)*idy+idx+4];
		sum += kn[ky*KERNEL_SIZE + 5]*src[(WIDTH+ky)*idy+idx+5];
		sum += kn[ky*KERNEL_SIZE + 6]*src[(WIDTH+ky)*idy+idx+6];
		sum += kn[ky*KERNEL_SIZE + 7]*src[(WIDTH+ky)*idy+idx+7];
		sum += kn[ky*KERNEL_SIZE + 8]*src[(WIDTH+ky)*idy+idx+8];
	}

    dst[id] = sum;
}
 