// ========== Vector Types ==========
charN, ucharN, shortN, ushortN, intN, uintN, longN, ulongN, floatN      // N is 1,2,3 or 4
// components accessible as var.x, var.y, var.z, var.w
// constructor is make_<type>( x, ... ), e.g. float2 xx = make_float2( 1., 2. )

dim3 var                    // components accessible as var.x, var.y, var.z
dim3 blocks1D(5      );     // makes 1D block
dim3 blocks2D(5, 5   );     // makes 2D block
dim3 blocks3D(5, 5, 5);     // makes 3D block



// ========== Streams ==========
cudaStream_t *pStream;                              // declaration of a stream pStream

cudaStreamCreate(cudaStream_t* pStream);            // creates an asynchronous stream and stores it in pStream

cudaStreamCreateWithFlags(cudaStream_t* pStream,    // creates an asynchronous stream with flags and stores it in pStream
                          unsigned int  flags);     // cudaStreamDefault: default stream creation flag
                                                    // cudaStreamNonBlocking: work running in the created stream may run concurrently with
                                                    //  ...stream 0 (the NULL stream), and no implicit synchronization with stream 0 is performed

cudaStreamCreateWithPriority(cudaStream_t* pStream, // creates an asynchronous stream with the specified priority
                             unsigned int  flags,   // as above
                             int  priority);        // priority, lower numbers represent higher priorities

cudaDeviceGetStreamPriorityRange(int* leastPriority, int* greatestPriority);    // returns least and greatest stream priorities

cudaStreamSynchronize(cudaStream_t stream);         // waits for stream tasks to complete

cudaStreamDestroy(cudaStream_t stream);             // destroys a stream



// ========== Memory Management ==========
// Declaring variables inside a kernel (*.cu)
__device__      // declares a device variable in global memory, accessible from all threads, with lifetime of application
__constant__    // declares a device variable in constant memory, accessible from all threads, with lifetime of application
__shared__      // declares a device varibale in block's shared memory, accessible from all threads within a block, with lifetime of block
__restrict__    // standard C definition that pointers are not aliased

// Examples
__device__ float d_arr[N];          // declared in the GPU's global memory,   only one instance per kernel run, shared by all threads
__shared__ float sh_arr[N];         // declared in the block's shared memory, every block has its own copy,     shared by threads in a block
float t_arr[N];                     // declared in the thread's local memory, every thread has its own copy,    shared by no threads

extern __shared__ float sh_arr[];   // size is passed as an argument to kernel call: kernel<<< gridSize, blockSize, sh_arrSize >>>(d_out, d_in);


// Declaring global GPU variables in the host program (*.cpp)
float h_ptr[ARRAY_SIZE];                                // host (CPU) memory allocation usually starts with 'h_'
float* d_ptr;                                           // declares a pointer for device (GPU) memory

cudaMalloc(void** d_ptrptr, size_t size);               // allocates memory on GPU

cudaMemset(void* d_ptr, int value, size_t count);       // initializes or sets device memory to a value

cudaMemcpy(void* dst, const void* src, size_t count,    // count is in bytes, e.g. ARRAY_SIZE * sizeof(float)
           cudaMemcpyKind kind);                        // kind is one of:  cudaMemcpyHostToHost = 0,   cudaMemcpyHostToDevice = 1,
                                                        //                  cudaMemcpyDeviceToHost = 2, cudaMemcpyDeviceToDevice = 3,
                                                        //                  cudaMemcpyDefault = 4 (requires unified virtual addressing)

cudaMemcpyAsync(void* dst, const void* src, size_t count,   // as above, just assigned to a stream
                cudaMemcpyKind kind, cudaStream_t stream=0);


cudaFree(void* d_ptr);                                  // frees memory on GPU

cudaHostAlloc(void** h_ptrptr, size_t size,             // allocates pinned/page-locked (not swapped to disc) memory on CPU
              unsigned int flags);                      // cudaHostAllocDefault: emulates cudaMallocHost()
                                                        // cudaHostAllocPortable: considered as pinned memory by all CUDA contexts
                                                        // cudaHostAllocMapped: maps the allocation into the CUDA address space
                                                        // cudaHostAllocWriteCombined: write-combined (WC) memory, can be transferred across
                                                        //  ...the PCI Express bus more quickly, but cannot be read efficiently by most CPUs;
                                                        //  ...a good option for buffers that will be written by the CPU and read by the device
                                                        //  ...via mapped pinned memory or host->device transfers.

cudaHostRegister(void* h_ptr, size_t size,              // registers an existing host memory range for use by CUDA
                 unsigned int  flags);                  // cudaHostRegisterPortable: considered as pinned memory by all CUDA contexts
                                                        // cudaHostRegisterMapped: maps the allocation into the CUDA address space
                                                        // cudaHostRegisterDefault: system with unified virtual addressing -> mapped and
                                                        //  ...portable; system with no unified virtual addressing -> neither mapped nor portable
                                                        // cudaHostRegisterIoMemory: the passed memory pointer is treated as pointing to some
                                                        //  ...memory-mapped I/O space, and it will marked as non cache-coherent and contiguous

cudaHostGetDevicePointer(void** d_ptrptr, void* h_ptr,  // returns d_ptr of mapped host memory obtained by cudaHostAlloc or cudaHostRegister
                         unsigned int  flags);          // for future releases

cudaFreeHost(void* h_ptr);                              // frees the memory allocated by cudaHostAlloc



// ========== Declaring Functions/Kernels ==========
__global__          // declares kernel, which is called on host and executed on device
__device__          // declares device function, which is called and executed on device
__host__            // declares host function, which is called and executed on host
__noinline__        // to avoid inlining
__forceinline__     // to force inlining

__global__ void kernel(float* d_out, float* d_in) {/*...*/};    // specifier __global__ says it's a cuda kernel not a normal code



// ========== Pre-Defined Variables in Kernels ==========
dim3  gridDim       // dimensions of grid of blocks;    blockIdx  refers to the coordinates in grid
dim3  blockDim      // dimensions of block of threads;  threadIdx refers to the coordinates in block

uint3 blockIdx      // block index within grid          min is 0,0,0 and max is gridDim  - (1,1,1)
uint3 threadIdx     // thread index within block        min is 0,0,0 and max is blockDim - (1,1,1)

int   warpSize      // number of threads in warp



// ========== Thread Management ==========
__threadfence_block();      // wait until memory accesses are visible to block
__threadfence();            // wait until memory accesses are visible to block and device
__threadfence_system();     // wait until memory accesses are visible to block and device and host (2.x)
__syncthreads();            // wait until all threads reach sync



// ========== Atomic Functions ==========
// for elements in global or shared memory, all the functions return the old value of *address
atomicAdd(TYPE* address, TYPE val);     // TYPE in {int, unsigned int, unsigned long long int, float, double};  *address += val
atomicSub(TYPE* address, TYPE val);     // TYPE in {int, unsigned int};                                         *address -= val
atomicExch(TYPE* address, TYPE val);    // TYPE in {int, unsigned int, unsigned long long int, float};          *address  = val

atomicMin(TYPE* address, TYPE val);     // TYPE in {int, unsigned int, unsigned long long int}                  *address = minimum{*address, val}
atomicMax(TYPE* address, TYPE val);     // TYPE in {int, unsigned int, unsigned long long int}                  *address = maximum{*address, val}

atomicInc(TYPE* address, TYPE val);     // TYPE in {unsigned int}   *address = ( (*address >= val) ? 0 : (*address + 1) )
atomicDec(TYPE* address, TYPE val);     // TYPE in {unsigned int}   *address = ( ( (*address == 0) || (*address > val) ) ? val : (*address - 1) )

atomicCAS(TYPE* address, TYPE compare, TYPE val);   // TYPE in {int, unsigned int, unsigned long long int, unsigned short int}
                                                    // *address = ( *address == compare ? val : *address )

atomicAnd(TYPE* address, TYPE val);     // TYPE in {int, unsigned int, unsigned long long int} *address = ( *address & val )
atomicOr(TYPE* address, TYPE val);      // TYPE in {int, unsigned int, unsigned long long int} *address = ( *address | val )
atomicXor(TYPE* address, TYPE val);     // TYPE in {int, unsigned int, unsigned long long int} *address = ( *address ^ val )



// ========== Launching Functions/Kernels ==========

__global__ void kernel(float* d_out, float* d_in) {/*...*/};
dim3 gridDim( mx, my, mz );
dim3 blockDim( nx, ny, nz );
kernel<<< gridDim, blockDim >>>(d_out, d_in);           // d_out, d_in are both variables living in the global GPU memory
kernel<<< gridDim, blockDim, sh_memSize, stream >>>();  // signature of kernel launch
