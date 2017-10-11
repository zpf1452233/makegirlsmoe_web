
#include <metal_stdlib>
using namespace metal;

#define OPTIMIZE 1

kernel void sgemm_81e90e8b08464e9a44e7910ad875fd886afeba4c8b6adf24eec65a4b(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint index[[thread_index_in_threadgroup]],
                          uint2 group_position[[threadgroup_position_in_grid]])
{
#define TRANSPOSE_A 1
#define TRANSPOSE_B 1
#define M_DIVIDABLE_BY_64 0
#define N_DIVIDABLE_BY_64 1
#define K_DIVIDABLE_BY_8 0

#if TRANSPOSE_A
    #define A_STRIDE_K 1
    #define A_STRIDE_M K
#else
    #define A_STRIDE_K M
    #define A_STRIDE_M 1
#endif

#if TRANSPOSE_B
    #define B_STRIDE_K N
    #define B_STRIDE_N 1
#else
    #define B_STRIDE_K 1
    #define B_STRIDE_N K
#endif

#if K_DIVIDABLE_BY_8 && M_DIVIDABLE_BY_64  && N_DIVIDABLE_BY_64 && !TRANSPOSE_A && TRANSPOSE_B && OPTIMIZE
    const device float4 *load_target4 = (index & 32) 
        ? (const device float4 *)((static_buffer + meta_buffer[1])) 
        : (const device float4 *)((static_buffer + meta_buffer[0]));
#else
    const device float *load_target = (index & 32) 
        ? ((static_buffer + meta_buffer[1])) 
        : ((static_buffer + meta_buffer[0]));
#endif

    const int M = meta_buffer[3];
    const int N = meta_buffer[4];

    const int K = meta_buffer[5];

    threadgroup float4 shared4[32 * 8 * 2];

    const int stride_k = (index & 32) ? B_STRIDE_K : A_STRIDE_K;
    const int stride_mn = (index & 32) ? B_STRIDE_N : A_STRIDE_M;

    const int m_offset = index & 7;
    const int n_offset = index >> 3;

    const int mn_load_offset = ((index & 32) ? group_position.y : group_position.x) * 64 + (index & 15) * 4;
    const int k_load_offset = ((index & 16) ? 1 : 0);

    int track0 = mn_load_offset * stride_mn + (k_load_offset + 0) * stride_k;
    int track2 = track0 + 2 * stride_k;
    int track4 = track0 + 4 * stride_k;
    int track6 = track0 + 6 * stride_k;

#if !OPTIMIZE || !M_DIVIDABLE_BY_64 || !N_DIVIDABLE_BY_64
    const int max_MN = (index & 32) ? N : M;
#endif

    int shared_offset4 = ((index & 32) ? 16 : 0) + k_load_offset * 32 + (index & 15);
    int read_A_offset4 = m_offset * 2;
    int read_B_offset4 = n_offset * 2 + 16;

    float4 result[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int k = 0;

    while (k < K)
    {
        {
#if OPTIMIZE && K_DIVIDABLE_BY_8
    #if OPTIMIZE && M_DIVIDABLE_BY_64 && N_DIVIDABLE_BY_64
        #if OPTIMIZE && !TRANSPOSE_A && TRANSPOSE_B
            shared4[shared_offset4 + 32 * 0] = load_target4[track0 >> 2];
            shared4[shared_offset4 + 32 * 2] = load_target4[track2 >> 2];
            shared4[shared_offset4 + 32 * 4] = load_target4[track4 >> 2];
            shared4[shared_offset4 + 32 * 6] = load_target4[track6 >> 2];
        #else
            shared4[shared_offset4 + 32 * 0] = float4(
                load_target[track0 + stride_mn * 0],
                load_target[track0 + stride_mn * 1],
                load_target[track0 + stride_mn * 2],
                load_target[track0 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 2] = float4(
                load_target[track2 + stride_mn * 0],
                load_target[track2 + stride_mn * 1],
                load_target[track2 + stride_mn * 2],
                load_target[track2 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 4] = float4(
                load_target[track4 + stride_mn * 0],
                load_target[track4 + stride_mn * 1],
                load_target[track4 + stride_mn * 2],
                load_target[track4 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 6] = float4(
                load_target[track6 + stride_mn * 0],
                load_target[track6 + stride_mn * 1],
                load_target[track6 + stride_mn * 2],
                load_target[track6 + stride_mn * 3]
            ); 
        #endif
    #else
            shared4[shared_offset4 + 32 * 0] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track0 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track0 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track0 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track0 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 2] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track2 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track2 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track2 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track2 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 4] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track4 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track4 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track4 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track4 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 6] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track6 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track6 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track6 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track6 + stride_mn * 3]
            ); 
    #endif

            k += 8;
#else
    #if OPTIMIZE && M_DIVIDABLE_BY_64 && N_DIVIDABLE_BY_64
            shared4[shared_offset4 + 32 * 0] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 2] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 4] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 6] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 3]
            ); 
            k += 2;
    #else
            shared4[shared_offset4 + 32 * 0] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track0 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track0 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track0 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track0 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 2] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track2 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track2 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track2 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track2 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 4] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track4 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track4 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track4 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track4 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 6] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track6 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track6 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track6 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track6 + stride_mn * 3]
            ); 
            k += 2;
    #endif
#endif
        }

        threadgroup_barrier(mem_flags::mem_threadgroup);

        {
            for (int k_sub = 0; k_sub < 8; k_sub++)
            {
                float4 a00 = shared4[32 * k_sub + read_A_offset4 + 0];
                float4 a01 = shared4[32 * k_sub + read_A_offset4 + 1];
                float4 b00 = shared4[32 * k_sub + read_B_offset4 + 0];
                float4 b01 = shared4[32 * k_sub + read_B_offset4 + 1];

                result[4][0]  += b00[0] * a00[2];
                result[4][1]  += b00[1] * a00[2];
                result[0][1]  += b00[1] * a00[0];
                result[0][0]  += b00[0] * a00[0];
                result[6][0]  += b00[0] * a00[3];
                result[6][1]  += b00[1] * a00[3];
                result[2][1]  += b00[1] * a00[1];
                result[2][0]  += b00[0] * a00[1];
                result[12][0] += b00[0] * a01[2];
                result[12][1] += b00[1] * a01[2];
                result[8][1]  += b00[1] * a01[0];
                result[8][0]  += b00[0] * a01[0];
                result[14][0] += b00[0] * a01[3];
                result[14][1] += b00[1] * a01[3];
                result[10][1] += b00[1] * a01[1];
                result[10][0] += b00[0] * a01[1];

                result[14][2] += b00[2] * a01[3];
                result[14][3] += b00[3] * a01[3];
                result[10][3] += b00[3] * a01[1];
                result[10][2] += b00[2] * a01[1];
                result[12][2] += b00[2] * a01[2];
                result[12][3] += b00[3] * a01[2];
                result[8][3]  += b00[3] * a01[0];
                result[8][2]  += b00[2] * a01[0];
                result[6][2]  += b00[2] * a00[3];
                result[6][3]  += b00[3] * a00[3];
                result[2][3]  += b00[3] * a00[1];
                result[2][2]  += b00[2] * a00[1];
                result[4][2]  += b00[2] * a00[2];
                result[4][3]  += b00[3] * a00[2];
                result[0][3]  += b00[3] * a00[0];
                result[0][2]  += b00[2] * a00[0];

                result[5][0]  += b01[0] * a00[2];
                result[5][1]  += b01[1] * a00[2];
                result[1][1]  += b01[1] * a00[0];
                result[1][0]  += b01[0] * a00[0];
                result[7][0]  += b01[0] * a00[3];
                result[7][1]  += b01[1] * a00[3];
                result[3][1]  += b01[1] * a00[1];
                result[3][0]  += b01[0] * a00[1];
                result[13][0] += b01[0] * a01[2];
                result[13][1] += b01[1] * a01[2];
                result[9][1]  += b01[1] * a01[0];
                result[9][0]  += b01[0] * a01[0];
                result[15][0] += b01[0] * a01[3];
                result[15][1] += b01[1] * a01[3];
                result[11][1] += b01[1] * a01[1];
                result[11][0] += b01[0] * a01[1];

                result[15][2] += b01[2] * a01[3];
                result[15][3] += b01[3] * a01[3];
                result[11][3] += b01[3] * a01[1];
                result[11][2] += b01[2] * a01[1];
                result[13][2] += b01[2] * a01[2];
                result[13][3] += b01[3] * a01[2];
                result[9][3]  += b01[3] * a01[0];
                result[9][2]  += b01[2] * a01[0];
                result[7][2]  += b01[2] * a00[3];
                result[7][3]  += b01[3] * a00[3];
                result[3][3]  += b01[3] * a00[1];
                result[3][2]  += b01[2] * a00[1];
                result[5][2]  += b01[2] * a00[2];
                result[5][3]  += b01[3] * a00[2];
                result[1][3]  += b01[3] * a00[0];
                result[1][2]  += b01[2] * a00[0];
            }
        }

        shared_offset4 ^= 32 * 8;
        read_A_offset4 ^= 32 * 8;
        read_B_offset4 ^= 32 * 8;
        track0 += stride_k * 8;
        track2 += stride_k * 8;
        track4 += stride_k * 8;
        track6 += stride_k * 8;
    }

    {
    
#if OPTIMIZE && N_DIVIDABLE_BY_64
        device float4 *C4 = (device float4 *)((static_buffer + meta_buffer[2]));
        const int N4 = N >> 2;
        int m = group_position.x * 64 + m_offset * 8;
        for (int m_sub = 0; m_sub < 8; m_sub++)
        {

    #if !M_DIVIDABLE_BY_64
            if (m >= M) continue;
    #endif

            const int n = group_position.y * 16 + n_offset * 2;
            float4 result0 = result[m_sub * 2 + 0];
            float4 result1 = result[m_sub * 2 + 1];

            C4[m * N4 + n + 0] = result0;
            C4[m * N4 + n + 1] = result1;
            
            m++;
        }
#else
        device float *C = (static_buffer + meta_buffer[2]);
        int m = group_position.x * 64 + m_offset * 8;
        for (int m_sub = 0; m_sub < 8; m_sub++)
        {
            int n = group_position.y * 64 + n_offset * 8;

            for (int n_sub1 = 0; n_sub1 < 2; n_sub1++)
            {
                for (int n_sub2 = 0; n_sub2 < 4; n_sub2++)
                {

    #if OPTIMIZE && M_DIVIDABLE_BY_64
                    (         n < N) ? (C[m * N + n] = result[m_sub * 2 + n_sub1][n_sub2]) : 0;
    #else
                    (m < M && n < N) ? (C[m * N + n] = result[m_sub * 2 + n_sub1][n_sub2]) : 0;
    #endif
                    n++;
                }
            }
            
            m++;
        }
#endif

    }


#undef M_DIVIDABLE_BY_64
#undef N_DIVIDABLE_BY_64
#undef K_DIVIDABLE_BY_8
#undef TRANSPOSE_A
#undef TRANSPOSE_B
#undef A_STRIDE_K
#undef B_STRIDE_K
#undef A_STRIDE_M
#undef A_STRIDE_M
}


kernel void fusedelementwise_e054e9592c688e900d43b4539f1d0b3418c031049a14901242973384(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3867 shape=(16384,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a1cfe10>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3770 shape=(1, 16384), order=[N, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a8d0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3771 shape=(1, 16384), order=[N, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a898>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 16384
    const int D0 = meta_buffer[3];
    int d0;
    for (d0 = gid; d0 < D0; d0 += num_threads) {
        //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3867 shape=(16384,), order=[C]>, 'x0': <Variable Variable3770 shape=(1, 16384), order=[N, C]>}, outputs={'y': <Variable Variable13 shape=(1, 16384), order=[N, C]>}>
        const float v4 = v1[d0];
        const float v5 = v2[d0];
        float v6;
        {
            v6 = v5 + v4;
        }
        //<Relu inputs={'x0': <Variable Variable13 shape=(1, 16384), order=[N, C]>}, outputs={'y': <Variable Variable3771 shape=(1, 16384), order=[N, C]>}>
        float v7;
        {
            v7 = v6 > 0 ? v6 : 0;
        }
        v3[d0] = v7;
    }
}


kernel void reshape_16bccba9a464498806aabf37d42e7f652af6d3922196b61ef1ee5108(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint index[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    const device float *x = (static_buffer + meta_buffer[0]);
    device float *y = (static_buffer + meta_buffer[1]);

    const int N = meta_buffer[2];

    for (int gid = index; gid < N; gid += num_threads) {
        y[gid] = x[gid];
    }
}


kernel void transpose_01d732c2a0b27fbd1cc7efa543dbe6ae628408b156c4c76eaaeda903(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<Variable Variable15 shape=(1, 64, 16, 16), order=[N, C, H, W]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a208>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3417 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a710>
    device float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256
    const int v3 = meta_buffer[2];
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int D0 = meta_buffer[4];
    //load: 256
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable15 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3417 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


kernel void im2col_dd5a967a90f95059d05657fb827f839569ee043c5e56cbfeb987f6f8(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint index_thread[[thread_position_in_threadgroup]],
                          uint index_group[[threadgroup_position_in_grid]])
{
#define SH_EQUAL_1 1
#define SW_EQUAL_1 1
#define DH_EQUAL_1 1
#define DW_EQUAL_1 1
#define C1_DIVIDABLE_BY_4 1


#if OPTIMIZE && C1_DIVIDABLE_BY_4
    const device float4 *im4 = (const device float4 *)((static_buffer + meta_buffer[0]));
    device float4 *col4 = (device float4 *)((static_buffer + meta_buffer[1]));
    const int C1_4 = (meta_buffer[3]) >> 2;
#else
    const device float *im = (static_buffer + meta_buffer[0]);
    device float *col = (static_buffer + meta_buffer[1]);
    const int C1 = meta_buffer[3];
#endif

    const int H1 = meta_buffer[4];
    const int W1 = meta_buffer[5];
    const int H2 = meta_buffer[6];
    const int W2 = meta_buffer[7];
    const int KH = meta_buffer[8];
    const int KW = meta_buffer[9];
#if !DH_EQUAL_1
    const int DH = meta_buffer[10];
#endif
#if !DW_EQUAL_1
    const int DW = meta_buffer[11];
#endif
    const int PH = meta_buffer[14];
    const int PW = meta_buffer[15];

#if !OPTIMIZE || !SH_EQUAL_1
    const int SH = meta_buffer[12];
#endif

#if !OPTIMIZE || !SW_EQUAL_1
    const int SW = meta_buffer[13];
#endif

    const int H1P = H1 + 2 * PH;
    const int W1P = W1 + 2 * PW;

    const int w1 = (index_group % W1P) - PW;
    const int h1 = (index_group / W1P % H1P) - PH;
    const int  n = index_group / W1P / H1P;

#if OPTIMIZE && C1_DIVIDABLE_BY_4
    for (int c1_4 = index_thread; c1_4 < C1_4; c1_4 += 64) {
        const float4 v4 = (h1 < 0 || h1 >= H1 || w1 < 0 || w1 >= W1) ? 0 : im4[((n * H1 + h1) * W1 + w1) * C1_4 + c1_4];
#else
    for (int c1 = index_thread; c1 < C1; c1 += 64) {
        const float v = (h1 < 0 || h1 >= H1 || w1 < 0 || w1 >= W1) ? 0 : im[((n * H1 + h1) * W1 + w1) * C1 + c1];
#endif

#if OPTIMIZE && SH_EQUAL_1
        for (int kh = 0; kh < KH; kh++) {
    #if DH_EQUAL_1
            const int h2 = h1 + PH - kh;
    #else
            const int h2 = h1 + PH - kh * DH;
    #endif
    
#else
        for (int kh = (h1 + PH) % SH; kh < KH; kh += SH) {
    #if DH_EQUAL_1
            const int h2 = (h1 + PH - kh) / SH;
    #else
            const int h2 = (h1 + PH - kh * DH) / SH;
    #endif
#endif
            if (h2 < 0 || h2 >= H2) continue;

#if OPTIMIZE && SH_EQUAL_1
            for (int kw = 0; kw < KW; kw++) {
    #if DW_EQUAL_1
                const int w2 = w1 + PW - kw;
    #else
                const int w2 = w1 + PW - kw * DW;
    #endif
#else
            for (int kw = (w1 + PW) % SW; kw < KW; kw += SW) {
    #if DW_EQUAL_1
                const int w2 = (w1 + PW - kw) / SW;
    #else
                const int w2 = (w1 + PW - kw * DW) / SW;
    #endif
#endif
                if (w2 < 0 || w2 >= W2) continue;

#if OPTIMIZE && C1_DIVIDABLE_BY_4
                col4[((((n * H2 + h2) * W2 + w2) * KH + kh) * KW + kw) * C1_4 + c1_4] = v4;
#else
                col[((((n * H2 + h2) * W2 + w2) * KH + kh) * KW + kw) * C1 + c1] = v;
#endif
            }
        }
    }


#undef SH_EQUAL_1
#undef SW_EQUAL_1
#undef DH_EQUAL_1
#undef DW_EQUAL_1
#undef C1_DIVIDABLE_BY_4
}


kernel void sgemm_94f0c54b77dcb1fbad06f386c4665ef898e786f3080ae97e8195afb1(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint index[[thread_index_in_threadgroup]],
                          uint2 group_position[[threadgroup_position_in_grid]])
{
#define TRANSPOSE_A 1
#define TRANSPOSE_B 1
#define M_DIVIDABLE_BY_64 1
#define N_DIVIDABLE_BY_64 1
#define K_DIVIDABLE_BY_8 1

#if TRANSPOSE_A
    #define A_STRIDE_K 1
    #define A_STRIDE_M K
#else
    #define A_STRIDE_K M
    #define A_STRIDE_M 1
#endif

#if TRANSPOSE_B
    #define B_STRIDE_K N
    #define B_STRIDE_N 1
#else
    #define B_STRIDE_K 1
    #define B_STRIDE_N K
#endif

#if K_DIVIDABLE_BY_8 && M_DIVIDABLE_BY_64  && N_DIVIDABLE_BY_64 && !TRANSPOSE_A && TRANSPOSE_B && OPTIMIZE
    const device float4 *load_target4 = (index & 32) 
        ? (const device float4 *)((static_buffer + meta_buffer[1])) 
        : (const device float4 *)((static_buffer + meta_buffer[0]));
#else
    const device float *load_target = (index & 32) 
        ? ((static_buffer + meta_buffer[1])) 
        : ((static_buffer + meta_buffer[0]));
#endif

    const int M = meta_buffer[3];
    const int N = meta_buffer[4];

    const int K = meta_buffer[5];

    threadgroup float4 shared4[32 * 8 * 2];

    const int stride_k = (index & 32) ? B_STRIDE_K : A_STRIDE_K;
    const int stride_mn = (index & 32) ? B_STRIDE_N : A_STRIDE_M;

    const int m_offset = index & 7;
    const int n_offset = index >> 3;

    const int mn_load_offset = ((index & 32) ? group_position.y : group_position.x) * 64 + (index & 15) * 4;
    const int k_load_offset = ((index & 16) ? 1 : 0);

    int track0 = mn_load_offset * stride_mn + (k_load_offset + 0) * stride_k;
    int track2 = track0 + 2 * stride_k;
    int track4 = track0 + 4 * stride_k;
    int track6 = track0 + 6 * stride_k;

#if !OPTIMIZE || !M_DIVIDABLE_BY_64 || !N_DIVIDABLE_BY_64
    const int max_MN = (index & 32) ? N : M;
#endif

    int shared_offset4 = ((index & 32) ? 16 : 0) + k_load_offset * 32 + (index & 15);
    int read_A_offset4 = m_offset * 2;
    int read_B_offset4 = n_offset * 2 + 16;

    float4 result[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int k = 0;

    while (k < K)
    {
        {
#if OPTIMIZE && K_DIVIDABLE_BY_8
    #if OPTIMIZE && M_DIVIDABLE_BY_64 && N_DIVIDABLE_BY_64
        #if OPTIMIZE && !TRANSPOSE_A && TRANSPOSE_B
            shared4[shared_offset4 + 32 * 0] = load_target4[track0 >> 2];
            shared4[shared_offset4 + 32 * 2] = load_target4[track2 >> 2];
            shared4[shared_offset4 + 32 * 4] = load_target4[track4 >> 2];
            shared4[shared_offset4 + 32 * 6] = load_target4[track6 >> 2];
        #else
            shared4[shared_offset4 + 32 * 0] = float4(
                load_target[track0 + stride_mn * 0],
                load_target[track0 + stride_mn * 1],
                load_target[track0 + stride_mn * 2],
                load_target[track0 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 2] = float4(
                load_target[track2 + stride_mn * 0],
                load_target[track2 + stride_mn * 1],
                load_target[track2 + stride_mn * 2],
                load_target[track2 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 4] = float4(
                load_target[track4 + stride_mn * 0],
                load_target[track4 + stride_mn * 1],
                load_target[track4 + stride_mn * 2],
                load_target[track4 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 6] = float4(
                load_target[track6 + stride_mn * 0],
                load_target[track6 + stride_mn * 1],
                load_target[track6 + stride_mn * 2],
                load_target[track6 + stride_mn * 3]
            ); 
        #endif
    #else
            shared4[shared_offset4 + 32 * 0] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track0 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track0 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track0 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track0 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 2] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track2 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track2 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track2 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track2 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 4] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track4 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track4 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track4 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track4 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 6] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track6 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track6 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track6 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track6 + stride_mn * 3]
            ); 
    #endif

            k += 8;
#else
    #if OPTIMIZE && M_DIVIDABLE_BY_64 && N_DIVIDABLE_BY_64
            shared4[shared_offset4 + 32 * 0] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 2] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 4] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 6] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 3]
            ); 
            k += 2;
    #else
            shared4[shared_offset4 + 32 * 0] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track0 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track0 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track0 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track0 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 2] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track2 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track2 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track2 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track2 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 4] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track4 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track4 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track4 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track4 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 6] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track6 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track6 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track6 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track6 + stride_mn * 3]
            ); 
            k += 2;
    #endif
#endif
        }

        threadgroup_barrier(mem_flags::mem_threadgroup);

        {
            for (int k_sub = 0; k_sub < 8; k_sub++)
            {
                float4 a00 = shared4[32 * k_sub + read_A_offset4 + 0];
                float4 a01 = shared4[32 * k_sub + read_A_offset4 + 1];
                float4 b00 = shared4[32 * k_sub + read_B_offset4 + 0];
                float4 b01 = shared4[32 * k_sub + read_B_offset4 + 1];

                result[4][0]  += b00[0] * a00[2];
                result[4][1]  += b00[1] * a00[2];
                result[0][1]  += b00[1] * a00[0];
                result[0][0]  += b00[0] * a00[0];
                result[6][0]  += b00[0] * a00[3];
                result[6][1]  += b00[1] * a00[3];
                result[2][1]  += b00[1] * a00[1];
                result[2][0]  += b00[0] * a00[1];
                result[12][0] += b00[0] * a01[2];
                result[12][1] += b00[1] * a01[2];
                result[8][1]  += b00[1] * a01[0];
                result[8][0]  += b00[0] * a01[0];
                result[14][0] += b00[0] * a01[3];
                result[14][1] += b00[1] * a01[3];
                result[10][1] += b00[1] * a01[1];
                result[10][0] += b00[0] * a01[1];

                result[14][2] += b00[2] * a01[3];
                result[14][3] += b00[3] * a01[3];
                result[10][3] += b00[3] * a01[1];
                result[10][2] += b00[2] * a01[1];
                result[12][2] += b00[2] * a01[2];
                result[12][3] += b00[3] * a01[2];
                result[8][3]  += b00[3] * a01[0];
                result[8][2]  += b00[2] * a01[0];
                result[6][2]  += b00[2] * a00[3];
                result[6][3]  += b00[3] * a00[3];
                result[2][3]  += b00[3] * a00[1];
                result[2][2]  += b00[2] * a00[1];
                result[4][2]  += b00[2] * a00[2];
                result[4][3]  += b00[3] * a00[2];
                result[0][3]  += b00[3] * a00[0];
                result[0][2]  += b00[2] * a00[0];

                result[5][0]  += b01[0] * a00[2];
                result[5][1]  += b01[1] * a00[2];
                result[1][1]  += b01[1] * a00[0];
                result[1][0]  += b01[0] * a00[0];
                result[7][0]  += b01[0] * a00[3];
                result[7][1]  += b01[1] * a00[3];
                result[3][1]  += b01[1] * a00[1];
                result[3][0]  += b01[0] * a00[1];
                result[13][0] += b01[0] * a01[2];
                result[13][1] += b01[1] * a01[2];
                result[9][1]  += b01[1] * a01[0];
                result[9][0]  += b01[0] * a01[0];
                result[15][0] += b01[0] * a01[3];
                result[15][1] += b01[1] * a01[3];
                result[11][1] += b01[1] * a01[1];
                result[11][0] += b01[0] * a01[1];

                result[15][2] += b01[2] * a01[3];
                result[15][3] += b01[3] * a01[3];
                result[11][3] += b01[3] * a01[1];
                result[11][2] += b01[2] * a01[1];
                result[13][2] += b01[2] * a01[2];
                result[13][3] += b01[3] * a01[2];
                result[9][3]  += b01[3] * a01[0];
                result[9][2]  += b01[2] * a01[0];
                result[7][2]  += b01[2] * a00[3];
                result[7][3]  += b01[3] * a00[3];
                result[3][3]  += b01[3] * a00[1];
                result[3][2]  += b01[2] * a00[1];
                result[5][2]  += b01[2] * a00[2];
                result[5][3]  += b01[3] * a00[2];
                result[1][3]  += b01[3] * a00[0];
                result[1][2]  += b01[2] * a00[0];
            }
        }

        shared_offset4 ^= 32 * 8;
        read_A_offset4 ^= 32 * 8;
        read_B_offset4 ^= 32 * 8;
        track0 += stride_k * 8;
        track2 += stride_k * 8;
        track4 += stride_k * 8;
        track6 += stride_k * 8;
    }

    {
    
#if OPTIMIZE && N_DIVIDABLE_BY_64
        device float4 *C4 = (device float4 *)((static_buffer + meta_buffer[2]));
        const int N4 = N >> 2;
        int m = group_position.x * 64 + m_offset * 8;
        for (int m_sub = 0; m_sub < 8; m_sub++)
        {

    #if !M_DIVIDABLE_BY_64
            if (m >= M) continue;
    #endif

            const int n = group_position.y * 16 + n_offset * 2;
            float4 result0 = result[m_sub * 2 + 0];
            float4 result1 = result[m_sub * 2 + 1];

            C4[m * N4 + n + 0] = result0;
            C4[m * N4 + n + 1] = result1;
            
            m++;
        }
#else
        device float *C = (static_buffer + meta_buffer[2]);
        int m = group_position.x * 64 + m_offset * 8;
        for (int m_sub = 0; m_sub < 8; m_sub++)
        {
            int n = group_position.y * 64 + n_offset * 8;

            for (int n_sub1 = 0; n_sub1 < 2; n_sub1++)
            {
                for (int n_sub2 = 0; n_sub2 < 4; n_sub2++)
                {

    #if OPTIMIZE && M_DIVIDABLE_BY_64
                    (         n < N) ? (C[m * N + n] = result[m_sub * 2 + n_sub1][n_sub2]) : 0;
    #else
                    (m < M && n < N) ? (C[m * N + n] = result[m_sub * 2 + n_sub1][n_sub2]) : 0;
    #endif
                    n++;
                }
            }
            
            m++;
        }
#endif

    }


#undef M_DIVIDABLE_BY_64
#undef N_DIVIDABLE_BY_64
#undef K_DIVIDABLE_BY_8
#undef TRANSPOSE_A
#undef TRANSPOSE_B
#undef A_STRIDE_K
#undef B_STRIDE_K
#undef A_STRIDE_M
#undef A_STRIDE_M
}


kernel void fusedelementwise_d591cfd54eea27b8d1f8e05c3912da13d92a08f854eeef2de58a8b1b(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3866 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a1cf6d8>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3768 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130992390>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3769 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130992390>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3768 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3866 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable24 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable24 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3769 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_c4989f403d12993de160ea6426054d7b560c52c20869203d82b999f1(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3865 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a1cf5c0>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3765 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a5f8>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3766 shape=(1, 64, 16, 16), order=[N, C, H, W]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a208>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3767 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a5f8>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 256
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3765 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3766 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3366 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0*v6 + d1];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3366 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3865 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3767 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_af06c698ff27a8c95bc48eec864ddb426b28164ad37bc7bbf1f898e5(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3864 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a1cf518>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3763 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a0f0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3764 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a0f0>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3763 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3864 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable44 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable44 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3764 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_e616cea79df9c359d1f493a90120c12ee8e0bee0a66ac5a75223c22c(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3863 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a1cf588>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3760 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a5f8>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3761 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2af98>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3762 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a630>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <Variable Variable3760 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x0': <Variable Variable3761 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3368 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v10 + v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3368 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3863 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3762 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_7b95cfdcb940be175412172729d1234f711e0caeb52f4c4234871453(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3862 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a1d29e8>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3758 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a978>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3759 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139ef0>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3862 shape=(64,), order=[C]>, 'x0': <Variable Variable3758 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable64 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable64 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3759 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_27b7f62170de2068a663c89c82ec001ee73e994e743316ac22807e49(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3861 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a1d2828>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3755 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a630>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3756 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139940>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3757 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a630>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <Variable Variable3755 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x0': <Variable Variable3756 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3370 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v10 + v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3370 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3861 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3757 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_d0b8b793bd82169cd3f03b75c4e9a189e2ef6d165c195b40561cb5a9(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3860 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a1ebf98>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3753 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x1311391d0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3754 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139160>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3860 shape=(64,), order=[C]>, 'x0': <Variable Variable3753 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable84 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable84 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3754 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_4a5f8de8062e780cbfc1bcf0a5c515dac42b6efc0771c5f2bd5944de(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3859 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131156160>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3750 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x1311392b0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3751 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c2a630>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3752 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x1311392b0>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3750 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3751 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3372 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3372 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3859 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3752 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_5e906dddd1bc8784b84efa2f4178ccae76a9a05cb3a2ce9271f348fe(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3858 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x1198c4828>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3748 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139b70>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3749 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139b70>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3748 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3858 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable104 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable104 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3749 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_67d40644d11849a317e2f3c3633367105ab6a448ce476a4a50f2f43b(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3857 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x1198f7080>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3745 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139b00>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3746 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x1311392b0>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3747 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139240>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3745 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3746 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3374 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3374 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3857 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3747 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_76e76544f9dbf6b667ddc1e61f527e9ff8a4aa16154bbe17a74a294b(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3856 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fd5ecf8>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3743 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x1311390b8>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3744 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x1311390b8>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3743 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3856 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable124 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable124 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3744 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_87516e893cfb5161a4a319defa3d3d0422eb9626e634106c5624ee81(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3855 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x118e6e1d0>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3740 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fd4e1d0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3741 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139240>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3742 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fd4e1d0>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3740 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3741 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3376 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3376 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3855 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3742 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_2b3bef144a0f2a9d493a55415664821ba0c45522efdbb0f621a5a44e(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3854 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b61be0>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3738 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139860>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3739 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139978>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3854 shape=(64,), order=[C]>, 'x0': <Variable Variable3738 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable144 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable144 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3739 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_009daceb9d502043da6c0e86e64bc04b5a4ce5865e8a4521fc508b97(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3853 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b61978>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3735 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fd4e1d0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3736 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x131139f60>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3737 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fd4e1d0>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <Variable Variable3735 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x0': <Variable Variable3736 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3378 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v10 + v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3378 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3853 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3737 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_282ef2d0a47478deb180a5ae52b83ba67b289eee78663ec2a20e49bb(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3852 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b61438>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3733 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fd4ebe0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3734 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61fd0>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3852 shape=(64,), order=[C]>, 'x0': <Variable Variable3733 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable164 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable164 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3734 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_7854360c15e27bdf792da15b694129dff1363fbe2f3330ed2a59d2b9(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3851 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b61dd8>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3730 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fd4e1d0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3731 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61748>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3732 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fd4e1d0>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <Variable Variable3730 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x0': <Variable Variable3731 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3380 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v10 + v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3380 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3851 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3732 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_aa7c22a069d41286b2fdbad534806578df6b914241e98d1ec5f35728(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3850 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b61e80>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3728 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61eb8>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3729 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61eb8>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3728 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3850 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable184 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable184 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3729 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_3c53069c7847a5946182c14004dc8ad1a126dec1d1d2af9576713f0f(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3849 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b610b8>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3725 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fd4e1d0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3726 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61a90>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3727 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f614e0>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <Variable Variable3725 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x0': <Variable Variable3726 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3382 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v10 + v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3382 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3849 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3727 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_f5e2cb7ef239d0c8f4995851d45167a2c1b12bfb4c19c1e56decff3c(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3848 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b619b0>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3723 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61780>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3724 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61e10>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3848 shape=(64,), order=[C]>, 'x0': <Variable Variable3723 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable204 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable204 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3724 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_16c82ae84703a535da65318db10807b4cbab6f8f88c5e5ec90aebd8a(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3847 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b61470>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3720 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f615f8>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3721 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f614e0>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3722 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61588>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3720 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3721 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3384 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3384 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3847 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3722 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_c2510b8d53b1c94ae803d0df69f82ca9822a5647ef41e2f11947f1a3(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3846 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b616d8>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3718 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61128>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3719 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f610b8>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3846 shape=(64,), order=[C]>, 'x0': <Variable Variable3718 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable224 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable224 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3719 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_6b073d673988cbbfaf1ddb05f29b25daed95e45c92bee5d99630a1cf(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3845 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130b61748>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3715 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f619b0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3716 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61588>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3717 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61550>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3715 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3716 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3386 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3386 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3845 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3717 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_3215e7f561eef757d1bb2d4a699fb0a7c4871d8a91277b9ed683fa33(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3844 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x13089f588>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3713 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61e48>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3714 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61b00>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3844 shape=(64,), order=[C]>, 'x0': <Variable Variable3713 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable244 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable244 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3714 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_5995b42ec143db185040151cd04e327ad317c17c90ed4442b9a84a63(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3843 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x13089fb00>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3710 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f537b8>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3711 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61550>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3712 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53dd8>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3710 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3711 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3388 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3388 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3843 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3712 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_c7ca163d3f63a473d70354d305c6451051557fc755865f35236bfb2d(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3842 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x13089fc88>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3708 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61668>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3709 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f61668>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3708 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3842 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable264 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable264 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3709 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_2367b95474a9e0d765ad986225ec2765c8367c74ae997799a10483ae(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3841 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x13089fb38>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3705 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53160>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3706 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53dd8>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3707 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53160>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3705 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3706 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3390 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3390 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3841 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3707 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_f2292bc48b333f5102e7c08e9a9e9ad1a81c77f17d47410e5bb25b09(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3840 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x13089f390>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3703 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53358>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3704 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f535c0>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3840 shape=(64,), order=[C]>, 'x0': <Variable Variable3703 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable284 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable284 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3704 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_48ec03d2e3487206f0fd2ca221b5dce39c51390b33a34263b3edad55(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3839 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x13089f400>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3700 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f534a8>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3701 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53160>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3702 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53080>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3700 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3701 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3392 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3392 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3839 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3702 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_27ea93bfcf67ecd5271712f8bf20b06164a152c992b715478afc7166(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3838 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40160>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3698 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53278>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3699 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53278>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3698 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3838 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable304 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable304 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3699 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_34c9ce4e02b861188033419626b713421cfd53b16d25b1bca2369e8b(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3837 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c405f8>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3695 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130f53080>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3696 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97c50>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3697 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97860>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <Variable Variable3695 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x0': <Variable Variable3696 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3394 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v10 + v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3394 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3837 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3697 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_ae3432b23808a28ee83f372ec22037a974fd0573791d9b9b7d484f5c(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3836 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40080>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3693 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97710>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3694 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97710>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3693 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3836 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable324 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable324 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3694 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void fusedelementwise_48e9362c61aa189cf53511ac1d2b945c87a5ace79a63cdc212d96508(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3835 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40390>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3690 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97d68>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3691 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97860>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3692 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97da0>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int v7 = meta_buffer[6];
    //load: 64
    const int D0 = meta_buffer[7];
    //load: 256
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v8 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x0': <Variable Variable3690 shape=(1, 16, 16, 64), order=[N, H, W, C]>, 'x1': <Variable Variable3691 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3396 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v9 = v2[d0 + d1*v5];
            const float v10 = v3[d0 + d1*v6];
            float v11;
            {
                v11 = v9 + v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3396 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3835 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3692 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 + v8;
            }
            v4[d0 + d1*v7] = v12;
        }
    }
}


kernel void fusedelementwise_5972479bea958b3cb173aae274682e34ee913502e564d46fe2193d1d(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3834 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c406d8>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3688 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97160>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3689 shape=(1, 16, 16, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7cef0>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 64
    const int v4 = meta_buffer[3];
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3834 shape=(64,), order=[C]>, 'x0': <Variable Variable3688 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable344 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Relu inputs={'x0': <Variable Variable344 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3689 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


kernel void elementwiseadd_a000ac957635042b40125802f38371401a54e3b7c6f98cdcac292aee(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable76 shape=(256,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c401d0>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3517 shape=(1, 16, 16, 256), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97358>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable347 shape=(1, 16, 16, 256), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c97358>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 256
    const int v4 = meta_buffer[3];
    //load: 256
    const int v5 = meta_buffer[4];
    //load: 256
    const int D0 = meta_buffer[5];
    //load: 256
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable76 shape=(256,), order=[C]>, 'x0': <Variable Variable3517 shape=(1, 16, 16, 256), order=[N, H, W, C]>}, outputs={'y': <Variable Variable347 shape=(1, 16, 16, 256), order=[N, H, W, C]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            v3[d0 + d1*v5] = v8;
        }
    }
}


kernel void depth2space_80400f914882037720ae1b1a8c35fd1640e44514f2d25ba012fd9f6f(device float * static_buffer[[buffer(0)]],
                     device float * dynamic_buffer[[buffer(1)]],
                     const device int * meta_buffer[[buffer(2)]],
                     uint index[[thread_position_in_grid]],
                     uint num_threads[[threads_per_grid]])
{
    const device float *x = (static_buffer + meta_buffer[0]);
    device float *y = (static_buffer + meta_buffer[1]);
    const int r = meta_buffer[2];

    const int N = meta_buffer[3];
    const int C1 = meta_buffer[4];
    const int C2 = meta_buffer[5];
    const int H1 = meta_buffer[6];
    const int H2 = meta_buffer[7];
    const int W1 = meta_buffer[8];
    const int W2 = meta_buffer[9];

    for (int gid = index; gid < N*H2*W2*C2; gid += num_threads) {
        const int c2 = gid % C2;
        const int w2 = gid / C2 % W2;
        const int h2 = gid / C2 / W2 % H2;
        const int n = gid / C2 / W2 / H2;
        const int w1 = w2 / r;
        const int h1 = h2 / r;
        const int c1 = c2 + (w2 % r) * C2 + (h2 % r) * C2 * r;
        y[gid] = x[((n*H1+h1)*W1+w1)*C1+c1];
    }
}


kernel void fusedelementwise_2b6c3a3ec4c969b750b4de3bf5d809d449723efe8c3968597f04e9d5(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3832 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a1cf630>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<ConstantVariable ConstantVariable3833 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40dd8>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3686 shape=(1, 32, 32, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7cc18>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3687 shape=(1, 32, 32, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7cc18>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int D0 = meta_buffer[6];
    //load: 1024
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseMul inputs={'x0': <Variable Variable3686 shape=(1, 32, 32, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3833 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3185 shape=(1, 64, 32, 32), order=[N, C, H, W]>}>
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9 * v8;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3185 shape=(1, 64, 32, 32), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3832 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable355 shape=(1, 64, 32, 32), order=[N, C, H, W]>}>
            float v11;
            {
                v11 = v10 + v7;
            }
            //<Relu inputs={'x0': <Variable Variable355 shape=(1, 64, 32, 32), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3687 shape=(1, 32, 32, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 > 0 ? v11 : 0;
            }
            v4[d0 + d1*v6] = v12;
        }
    }
}


kernel void elementwiseadd_032f577171c682895fe644f54eb957eba5fa0fbae473244eeedc2041(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable84 shape=(256,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40e80>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3523 shape=(1, 32, 32, 256), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7c278>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable358 shape=(1, 32, 32, 256), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7c278>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 256
    const int v4 = meta_buffer[3];
    //load: 256
    const int v5 = meta_buffer[4];
    //load: 256
    const int D0 = meta_buffer[5];
    //load: 1024
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable84 shape=(256,), order=[C]>, 'x0': <Variable Variable3523 shape=(1, 32, 32, 256), order=[N, H, W, C]>}, outputs={'y': <Variable Variable358 shape=(1, 32, 32, 256), order=[N, H, W, C]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            v3[d0 + d1*v5] = v8;
        }
    }
}


kernel void fusedelementwise_6b37344c95ea25858495e9315f5b958eefebfb4b82d6db4bcf1b9e3a(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3830 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40f60>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<ConstantVariable ConstantVariable3831 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40748>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3684 shape=(1, 64, 64, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7ca58>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3685 shape=(1, 64, 64, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7ccc0>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int D0 = meta_buffer[6];
    //load: 4096
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseMul inputs={'x1': <ConstantVariable ConstantVariable3830 shape=(64,), order=[C]>, 'x0': <Variable Variable3684 shape=(1, 64, 64, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable3182 shape=(1, 64, 64, 64), order=[N, C, H, W]>}>
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3182 shape=(1, 64, 64, 64), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3831 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable366 shape=(1, 64, 64, 64), order=[N, C, H, W]>}>
            float v11;
            {
                v11 = v10 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable366 shape=(1, 64, 64, 64), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3685 shape=(1, 64, 64, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 > 0 ? v11 : 0;
            }
            v4[d0 + d1*v6] = v12;
        }
    }
}


kernel void elementwiseadd_ecbabea27458df228a18b77bbd1bb799f37b52c50d61076bf366dc81(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable92 shape=(256,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40ba8>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3529 shape=(1, 64, 64, 256), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7ccf8>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable369 shape=(1, 64, 64, 256), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7ccf8>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 256
    const int v4 = meta_buffer[3];
    //load: 256
    const int v5 = meta_buffer[4];
    //load: 256
    const int D0 = meta_buffer[5];
    //load: 4096
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable92 shape=(256,), order=[C]>, 'x0': <Variable Variable3529 shape=(1, 64, 64, 256), order=[N, H, W, C]>}, outputs={'y': <Variable Variable369 shape=(1, 64, 64, 256), order=[N, H, W, C]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            v3[d0 + d1*v5] = v8;
        }
    }
}


kernel void fusedelementwise_b0013a13ccd213aecb394c7a527044a160de4f0269eca48b64b8de1e(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3828 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40c88>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<ConstantVariable ConstantVariable3829 shape=(64,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c409b0>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3682 shape=(1, 128, 128, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7c860>
    const device float * v3 = (static_buffer + meta_buffer[2]);
    //
    //<Variable Variable3683 shape=(1, 128, 128, 64), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c7c860>
    device float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64
    const int v5 = meta_buffer[4];
    //load: 64
    const int v6 = meta_buffer[5];
    //load: 64
    const int D0 = meta_buffer[6];
    //load: 16384
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseMul inputs={'x0': <Variable Variable3682 shape=(1, 128, 128, 64), order=[N, H, W, C]>, 'x1': <ConstantVariable ConstantVariable3828 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable3179 shape=(1, 64, 128, 128), order=[N, C, H, W]>}>
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable3179 shape=(1, 64, 128, 128), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable3829 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable377 shape=(1, 64, 128, 128), order=[N, C, H, W]>}>
            float v11;
            {
                v11 = v10 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable377 shape=(1, 64, 128, 128), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3683 shape=(1, 128, 128, 64), order=[N, H, W, C]>}>
            float v12;
            {
                v12 = v11 > 0 ? v11 : 0;
            }
            v4[d0 + d1*v6] = v12;
        }
    }
}


kernel void sgemm_2f5fb17c61936ed97c3b40058a42f14de9b21cb6b4208d457114dbc7(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint index[[thread_index_in_threadgroup]],
                          uint2 group_position[[threadgroup_position_in_grid]])
{
#define TRANSPOSE_A 1
#define TRANSPOSE_B 1
#define M_DIVIDABLE_BY_64 1
#define N_DIVIDABLE_BY_64 0
#define K_DIVIDABLE_BY_8 1

#if TRANSPOSE_A
    #define A_STRIDE_K 1
    #define A_STRIDE_M K
#else
    #define A_STRIDE_K M
    #define A_STRIDE_M 1
#endif

#if TRANSPOSE_B
    #define B_STRIDE_K N
    #define B_STRIDE_N 1
#else
    #define B_STRIDE_K 1
    #define B_STRIDE_N K
#endif

#if K_DIVIDABLE_BY_8 && M_DIVIDABLE_BY_64  && N_DIVIDABLE_BY_64 && !TRANSPOSE_A && TRANSPOSE_B && OPTIMIZE
    const device float4 *load_target4 = (index & 32) 
        ? (const device float4 *)((static_buffer + meta_buffer[1])) 
        : (const device float4 *)((static_buffer + meta_buffer[0]));
#else
    const device float *load_target = (index & 32) 
        ? ((static_buffer + meta_buffer[1])) 
        : ((static_buffer + meta_buffer[0]));
#endif

    const int M = meta_buffer[3];
    const int N = meta_buffer[4];

    const int K = meta_buffer[5];

    threadgroup float4 shared4[32 * 8 * 2];

    const int stride_k = (index & 32) ? B_STRIDE_K : A_STRIDE_K;
    const int stride_mn = (index & 32) ? B_STRIDE_N : A_STRIDE_M;

    const int m_offset = index & 7;
    const int n_offset = index >> 3;

    const int mn_load_offset = ((index & 32) ? group_position.y : group_position.x) * 64 + (index & 15) * 4;
    const int k_load_offset = ((index & 16) ? 1 : 0);

    int track0 = mn_load_offset * stride_mn + (k_load_offset + 0) * stride_k;
    int track2 = track0 + 2 * stride_k;
    int track4 = track0 + 4 * stride_k;
    int track6 = track0 + 6 * stride_k;

#if !OPTIMIZE || !M_DIVIDABLE_BY_64 || !N_DIVIDABLE_BY_64
    const int max_MN = (index & 32) ? N : M;
#endif

    int shared_offset4 = ((index & 32) ? 16 : 0) + k_load_offset * 32 + (index & 15);
    int read_A_offset4 = m_offset * 2;
    int read_B_offset4 = n_offset * 2 + 16;

    float4 result[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int k = 0;

    while (k < K)
    {
        {
#if OPTIMIZE && K_DIVIDABLE_BY_8
    #if OPTIMIZE && M_DIVIDABLE_BY_64 && N_DIVIDABLE_BY_64
        #if OPTIMIZE && !TRANSPOSE_A && TRANSPOSE_B
            shared4[shared_offset4 + 32 * 0] = load_target4[track0 >> 2];
            shared4[shared_offset4 + 32 * 2] = load_target4[track2 >> 2];
            shared4[shared_offset4 + 32 * 4] = load_target4[track4 >> 2];
            shared4[shared_offset4 + 32 * 6] = load_target4[track6 >> 2];
        #else
            shared4[shared_offset4 + 32 * 0] = float4(
                load_target[track0 + stride_mn * 0],
                load_target[track0 + stride_mn * 1],
                load_target[track0 + stride_mn * 2],
                load_target[track0 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 2] = float4(
                load_target[track2 + stride_mn * 0],
                load_target[track2 + stride_mn * 1],
                load_target[track2 + stride_mn * 2],
                load_target[track2 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 4] = float4(
                load_target[track4 + stride_mn * 0],
                load_target[track4 + stride_mn * 1],
                load_target[track4 + stride_mn * 2],
                load_target[track4 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 6] = float4(
                load_target[track6 + stride_mn * 0],
                load_target[track6 + stride_mn * 1],
                load_target[track6 + stride_mn * 2],
                load_target[track6 + stride_mn * 3]
            ); 
        #endif
    #else
            shared4[shared_offset4 + 32 * 0] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track0 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track0 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track0 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track0 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 2] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track2 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track2 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track2 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track2 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 4] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track4 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track4 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track4 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track4 + stride_mn * 3]
            ); 
            shared4[shared_offset4 + 32 * 6] = float4(
                (mn_load_offset + 0 >= max_MN) ? 0 : load_target[track6 + stride_mn * 0],
                (mn_load_offset + 1 >= max_MN) ? 0 : load_target[track6 + stride_mn * 1],
                (mn_load_offset + 2 >= max_MN) ? 0 : load_target[track6 + stride_mn * 2],
                (mn_load_offset + 3 >= max_MN) ? 0 : load_target[track6 + stride_mn * 3]
            ); 
    #endif

            k += 8;
#else
    #if OPTIMIZE && M_DIVIDABLE_BY_64 && N_DIVIDABLE_BY_64
            shared4[shared_offset4 + 32 * 0] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track0 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 2] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track2 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 4] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track4 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 6] = float4(
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 0],
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 1],
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 2],
                (k + k_load_offset >= K) ? 0 : load_target[track6 + stride_mn * 3]
            ); 
            k += 2;
    #else
            shared4[shared_offset4 + 32 * 0] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track0 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track0 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track0 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track0 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 2] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track2 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track2 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track2 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track2 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 4] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track4 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track4 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track4 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track4 + stride_mn * 3]
            ); 
            k += 2;

            shared4[shared_offset4 + 32 * 6] = float4(
                (k + k_load_offset >= K || mn_load_offset + 0 >= max_MN) ? 0 : load_target[track6 + stride_mn * 0],
                (k + k_load_offset >= K || mn_load_offset + 1 >= max_MN) ? 0 : load_target[track6 + stride_mn * 1],
                (k + k_load_offset >= K || mn_load_offset + 2 >= max_MN) ? 0 : load_target[track6 + stride_mn * 2],
                (k + k_load_offset >= K || mn_load_offset + 3 >= max_MN) ? 0 : load_target[track6 + stride_mn * 3]
            ); 
            k += 2;
    #endif
#endif
        }

        threadgroup_barrier(mem_flags::mem_threadgroup);

        {
            for (int k_sub = 0; k_sub < 8; k_sub++)
            {
                float4 a00 = shared4[32 * k_sub + read_A_offset4 + 0];
                float4 a01 = shared4[32 * k_sub + read_A_offset4 + 1];
                float4 b00 = shared4[32 * k_sub + read_B_offset4 + 0];
                float4 b01 = shared4[32 * k_sub + read_B_offset4 + 1];

                result[4][0]  += b00[0] * a00[2];
                result[4][1]  += b00[1] * a00[2];
                result[0][1]  += b00[1] * a00[0];
                result[0][0]  += b00[0] * a00[0];
                result[6][0]  += b00[0] * a00[3];
                result[6][1]  += b00[1] * a00[3];
                result[2][1]  += b00[1] * a00[1];
                result[2][0]  += b00[0] * a00[1];
                result[12][0] += b00[0] * a01[2];
                result[12][1] += b00[1] * a01[2];
                result[8][1]  += b00[1] * a01[0];
                result[8][0]  += b00[0] * a01[0];
                result[14][0] += b00[0] * a01[3];
                result[14][1] += b00[1] * a01[3];
                result[10][1] += b00[1] * a01[1];
                result[10][0] += b00[0] * a01[1];

                result[14][2] += b00[2] * a01[3];
                result[14][3] += b00[3] * a01[3];
                result[10][3] += b00[3] * a01[1];
                result[10][2] += b00[2] * a01[1];
                result[12][2] += b00[2] * a01[2];
                result[12][3] += b00[3] * a01[2];
                result[8][3]  += b00[3] * a01[0];
                result[8][2]  += b00[2] * a01[0];
                result[6][2]  += b00[2] * a00[3];
                result[6][3]  += b00[3] * a00[3];
                result[2][3]  += b00[3] * a00[1];
                result[2][2]  += b00[2] * a00[1];
                result[4][2]  += b00[2] * a00[2];
                result[4][3]  += b00[3] * a00[2];
                result[0][3]  += b00[3] * a00[0];
                result[0][2]  += b00[2] * a00[0];

                result[5][0]  += b01[0] * a00[2];
                result[5][1]  += b01[1] * a00[2];
                result[1][1]  += b01[1] * a00[0];
                result[1][0]  += b01[0] * a00[0];
                result[7][0]  += b01[0] * a00[3];
                result[7][1]  += b01[1] * a00[3];
                result[3][1]  += b01[1] * a00[1];
                result[3][0]  += b01[0] * a00[1];
                result[13][0] += b01[0] * a01[2];
                result[13][1] += b01[1] * a01[2];
                result[9][1]  += b01[1] * a01[0];
                result[9][0]  += b01[0] * a01[0];
                result[15][0] += b01[0] * a01[3];
                result[15][1] += b01[1] * a01[3];
                result[11][1] += b01[1] * a01[1];
                result[11][0] += b01[0] * a01[1];

                result[15][2] += b01[2] * a01[3];
                result[15][3] += b01[3] * a01[3];
                result[11][3] += b01[3] * a01[1];
                result[11][2] += b01[2] * a01[1];
                result[13][2] += b01[2] * a01[2];
                result[13][3] += b01[3] * a01[2];
                result[9][3]  += b01[3] * a01[0];
                result[9][2]  += b01[2] * a01[0];
                result[7][2]  += b01[2] * a00[3];
                result[7][3]  += b01[3] * a00[3];
                result[3][3]  += b01[3] * a00[1];
                result[3][2]  += b01[2] * a00[1];
                result[5][2]  += b01[2] * a00[2];
                result[5][3]  += b01[3] * a00[2];
                result[1][3]  += b01[3] * a00[0];
                result[1][2]  += b01[2] * a00[0];
            }
        }

        shared_offset4 ^= 32 * 8;
        read_A_offset4 ^= 32 * 8;
        read_B_offset4 ^= 32 * 8;
        track0 += stride_k * 8;
        track2 += stride_k * 8;
        track4 += stride_k * 8;
        track6 += stride_k * 8;
    }

    {
    
#if OPTIMIZE && N_DIVIDABLE_BY_64
        device float4 *C4 = (device float4 *)((static_buffer + meta_buffer[2]));
        const int N4 = N >> 2;
        int m = group_position.x * 64 + m_offset * 8;
        for (int m_sub = 0; m_sub < 8; m_sub++)
        {

    #if !M_DIVIDABLE_BY_64
            if (m >= M) continue;
    #endif

            const int n = group_position.y * 16 + n_offset * 2;
            float4 result0 = result[m_sub * 2 + 0];
            float4 result1 = result[m_sub * 2 + 1];

            C4[m * N4 + n + 0] = result0;
            C4[m * N4 + n + 1] = result1;
            
            m++;
        }
#else
        device float *C = (static_buffer + meta_buffer[2]);
        int m = group_position.x * 64 + m_offset * 8;
        for (int m_sub = 0; m_sub < 8; m_sub++)
        {
            int n = group_position.y * 64 + n_offset * 8;

            for (int n_sub1 = 0; n_sub1 < 2; n_sub1++)
            {
                for (int n_sub2 = 0; n_sub2 < 4; n_sub2++)
                {

    #if OPTIMIZE && M_DIVIDABLE_BY_64
                    (         n < N) ? (C[m * N + n] = result[m_sub * 2 + n_sub1][n_sub2]) : 0;
    #else
                    (m < M && n < N) ? (C[m * N + n] = result[m_sub * 2 + n_sub1][n_sub2]) : 0;
    #endif
                    n++;
                }
            }
            
            m++;
        }
#endif

    }


#undef M_DIVIDABLE_BY_64
#undef N_DIVIDABLE_BY_64
#undef K_DIVIDABLE_BY_8
#undef TRANSPOSE_A
#undef TRANSPOSE_B
#undef A_STRIDE_K
#undef B_STRIDE_K
#undef A_STRIDE_M
#undef A_STRIDE_M
}


kernel void fusedelementwise_db92a9b864c8e69ca24c2446096c9e9aa889cf870858d0f2c7478d60(device float * static_buffer[[buffer(0)]],
                          device float * dynamic_buffer[[buffer(1)]],
                          const device int * meta_buffer [[buffer(2)]],
                          uint gid[[thread_position_in_grid]],
                          uint num_threads[[threads_per_grid]])
{
    //<ConstantVariable ConstantVariable3827 shape=(3,), order=[C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40f98>
    const device float * v1 = (static_buffer + meta_buffer[0]);
    //
    //<Variable Variable3680 shape=(1, 128, 128, 3), order=[N, H, W, C]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130992f98>
    const device float * v2 = (static_buffer + meta_buffer[1]);
    //
    //<Variable Variable3681 shape=(1, 3, 128, 128), order=[N, C, H, W]>
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130c40e10>
    device float * v3 = (static_buffer + meta_buffer[2]);
    //load: 3
    const int v4 = meta_buffer[3];
    //load: 16384
    const int v5 = meta_buffer[4];
    //load: 3
    const int D0 = meta_buffer[5];
    //load: 16384
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((num_threads > 8) ? (gid % (num_threads / 8)) : 0); d0 < D0; d0 += ((num_threads > 8) ? (num_threads / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((num_threads > 8) ? (gid / (num_threads / 8)) : 0); d1 < D1; d1 += ((num_threads > 8) ? 8 : 1)) {
            //<ElementwiseAdd inputs={'x1': <ConstantVariable ConstantVariable3827 shape=(3,), order=[C]>, 'x0': <Variable Variable3680 shape=(1, 128, 128, 3), order=[N, H, W, C]>}, outputs={'y': <Variable Variable380 shape=(1, 3, 128, 128), order=[N, C, H, W]>}>
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            //<Tanh inputs={'x0': <Variable Variable380 shape=(1, 3, 128, 128), order=[N, C, H, W]>}, outputs={'y': <Variable Variable3681 shape=(1, 3, 128, 128), order=[N, C, H, W]>}>
            float v9;
            {
                v9 = (v8 >= 10.0 ? 1.0 : tanh(v8));
            }
            v3[d0*v5 + d1] = v9;
        }
    }
}
