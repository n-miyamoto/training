#include <arm_neon.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <CL/cl.h>

#define WIDTH 640
#define HEIGHT 480
#define KERNEL_SIZE 9
#define MAX_SOURCE_SIZE 10000

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

    cl_device_id device_id = NULL;
    cl_context context = NULL;
    cl_command_queue command_queue = NULL;
    cl_program program = NULL;
    cl_kernel kernel = NULL;
    cl_platform_id platform_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    cl_int ret;

    /* OpenCL setup */
	FILE *kernel_file;
	char *kernel_source;
	size_t kernel_size;

	kernel_file = fopen("conv_kernel.cl", "r");
	if (!kernel_file) {
		fprintf(stderr, "No file named vecAddKernel.cl was found\n");
		exit(-1);
	}

	kernel_source = (char*)malloc(MAX_SOURCE_SIZE);
	kernel_size = fread(kernel_source, 1, MAX_SOURCE_SIZE, kernel_file);
	fclose(kernel_file);

	ret = clGetPlatformIDs(1,&platform_id, &ret_num_platforms);
    if(ret != CL_SUCCESS)
    {
        printf("Error : clGetPlatformIDs() %d\n", ret);
        return -1;
    }
	std::cout << "platform id : "<< platform_id << std::endl;
	std::cout << "platform num: " << ret_num_platforms << std::endl;
	
    ret = clGetDeviceIDs(platform_id,CL_DEVICE_TYPE_DEFAULT,1,
        &device_id,&ret_num_devices);
    if(ret != CL_SUCCESS)
    {
        printf("Error : clGetDeviceIDs()\n");
        return -1;
    }
	std::cout << "device id : "<< device_id << std::endl;
	std::cout << "device num: "<< ret_num_devices << std::endl;

    context = clCreateContext(NULL,1,&device_id,NULL,NULL,&ret);
    command_queue = clCreateCommandQueue(context,device_id,0,&ret);
    program = clCreateProgramWithSource(context,1,
        (const char **)&kernel_source,(const size_t *)&kernel_size,&ret);
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
    if(ret != CL_SUCCESS)
    {
        size_t len;
        char buffer[2048];
        printf("Error : clBuildProgram()\n");
        clGetProgramBuildInfo(program,device_id,CL_PROGRAM_BUILD_LOG,
            sizeof(buffer),buffer, &len);
        printf("\t%s\n",buffer);
        exit(1);
    }
    kernel = clCreateKernel(program, "vadd",&ret);
    if(ret != CL_SUCCESS)
    {
        printf("Error : clCreateKernel()\n");
        exit(1);
    }

	//Memory buffers for each array
	cl_mem src_memobj = clCreateBuffer(context, CL_MEM_READ_ONLY, (WIDTH+KERNEL_SIZE/2*2)*(HEIGHT+KERNEL_SIZE/2*2) * sizeof(float), NULL, &ret);
	cl_mem dst_memobj = clCreateBuffer(context, CL_MEM_WRITE_ONLY,  WIDTH * HEIGHT * sizeof(float), NULL, &ret);
	cl_mem kn_memobj  = clCreateBuffer(context, CL_MEM_READ_ONLY, KERNEL_SIZE * KERNEL_SIZE *sizeof(float), NULL, &ret);

	// Copy lists to memory buffers

	ret = clEnqueueWriteBuffer(command_queue, src_memobj, CL_TRUE, 0, (WIDTH+KERNEL_SIZE/2*2) * (HEIGHT+KERNEL_SIZE/2*2) * sizeof(float), src, 0, NULL, NULL);;
	ret = clEnqueueWriteBuffer(command_queue, kn_memobj , CL_TRUE, 0, KERNEL_SIZE*KERNEL_SIZE* sizeof(float), kn, 0, NULL, NULL);

    ret  = clSetKernelArg(kernel,0,sizeof(cl_mem),(void *)&src_memobj);
    ret |= clSetKernelArg(kernel,1,sizeof(cl_mem),(void *)&dst_memobj);
    ret |= clSetKernelArg(kernel,2,sizeof(cl_mem),(void *)&kn_memobj);
    if(ret != CL_SUCCESS)
    {
        printf("Error : clSetKernelArg()\n");
        exit(1);
    }
    /* execute kernel */
    size_t globalWorkSize[] = {WIDTH*HEIGHT};
    size_t localWorkSize[] = {1};
	c_start = clock();
	{
    	ret = clEnqueueNDRangeKernel(command_queue,kernel,1,NULL,
        		globalWorkSize,localWorkSize,0,NULL,NULL);
	}
	c_end = clock();
    if(ret != CL_SUCCESS)
    {
        printf("Error : executing kernel\n");
        exit(1);
    }
    /* reading result */
    ret = clEnqueueReadBuffer(command_queue,dst_memobj,CL_TRUE,0,
        WIDTH*HEIGHT*sizeof(float),dst_opt ,0,NULL,NULL);



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

