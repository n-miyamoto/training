#define WIDTH 640
#define KERNEL_SIZE 9

float conv(__global float* src, __constant float* kn, int idx, int idy){
    float sum = 0;
    const int a = (WIDTH)*idy+idx;
	for(int ky=0;ky<KERNEL_SIZE;ky+=1){
        const int k = ky*KERNEL_SIZE;
        const int w = a + ky*idy;
		sum += kn[k    ]*src[w  ];
		sum += kn[k + 1]*src[w+1];
		sum += kn[k + 2]*src[w+2];
		sum += kn[k + 3]*src[w+3];
		sum += kn[k + 4]*src[w+4];
		sum += kn[k + 5]*src[w+5];
		sum += kn[k + 6]*src[w+6];
		sum += kn[k + 7]*src[w+7];
		sum += kn[k + 8]*src[w+8];
	}
    return sum;
}

__kernel void vadd(__global float* src, __global float* dst, __constant float* kn)
{
    const int idx = get_global_id(0);
    const int idy = get_global_id(1);
    const int id = idx+ WIDTH*idy;

    dst[id] = conv(src, kn, idx, idy);
}
 