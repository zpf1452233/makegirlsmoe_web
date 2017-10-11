
#include <stdlib.h>
#include <math.h>

float static_buffer[90333797];
float* dynamic_buffer = nullptr;

int meta_buf_0[] = {90333635,0,7659971,1,16384,162};
int meta_buf_1[] = {2654208,7659971,7659971,16384};
int meta_buf_2[] = {7659971,7561667,16384};
int meta_buf_3[] = {7561667,7545283,256,64,64,256};
int meta_buf_4[] = {7545283,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_5[] = {7299523,2670592,7545283,256,64,576};
int meta_buf_6[] = {2707520,2707456,7545283,7512515,64,64,64,256};
int meta_buf_7[] = {7512515,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_8[] = {7299523,2707584,7659971,256,64,576};
int meta_buf_9[] = {2744448,2744512,7659971,7561667,7709123,64,256,256,64,256};
int meta_buf_10[] = {7709123,7758275,256,64,64,256};
int meta_buf_11[] = {7758275,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_12[] = {7299523,2744576,7545283,256,64,576};
int meta_buf_13[] = {2781440,2781504,7545283,7545283,64,64,64,256};
int meta_buf_14[] = {7545283,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_15[] = {7299523,2781568,7659971,256,64,576};
int meta_buf_16[] = {2818432,2818496,7659971,7709123,7725507,64,256,256,64,256};
int meta_buf_17[] = {7725507,7741891,256,64,64,256};
int meta_buf_18[] = {7741891,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_19[] = {7299523,2818560,7692739,256,64,576};
int meta_buf_20[] = {2855424,2855488,7692739,7676355,64,64,64,256};
int meta_buf_21[] = {7676355,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_22[] = {7299523,2855552,7709123,256,64,576};
int meta_buf_23[] = {2892480,2892416,7725507,7709123,7725507,256,64,256,64,256};
int meta_buf_24[] = {7725507,7758275,256,64,64,256};
int meta_buf_25[] = {7758275,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_26[] = {7299523,2892544,7659971,256,64,576};
int meta_buf_27[] = {2929472,2929408,7659971,7659971,64,64,64,256};
int meta_buf_28[] = {7659971,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_29[] = {7299523,2929536,7692739,256,64,576};
int meta_buf_30[] = {2966464,2966400,7692739,7725507,7709123,64,256,256,64,256};
int meta_buf_31[] = {7709123,7692739,256,64,64,256};
int meta_buf_32[] = {7692739,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_33[] = {7299523,2966528,7676355,256,64,576};
int meta_buf_34[] = {3003456,3003392,7676355,7659971,64,64,64,256};
int meta_buf_35[] = {7659971,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_36[] = {7299523,3003520,7676355,256,64,576};
int meta_buf_37[] = {3040448,3040384,7709123,7676355,7709123,256,64,256,64,256};
int meta_buf_38[] = {7709123,7676355,256,64,64,256};
int meta_buf_39[] = {7676355,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_40[] = {7299523,3040512,7676355,256,64,576};
int meta_buf_41[] = {3077440,3077376,7676355,7676355,64,64,64,256};
int meta_buf_42[] = {7676355,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_43[] = {7299523,3077504,7545283,256,64,576};
int meta_buf_44[] = {3114432,3114368,7709123,7545283,7627203,256,64,256,64,256};
int meta_buf_45[] = {7627203,7659971,256,64,64,256};
int meta_buf_46[] = {7659971,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_47[] = {7299523,3114496,7594435,256,64,576};
int meta_buf_48[] = {3151424,3151360,7594435,7610819,64,64,64,256};
int meta_buf_49[] = {7610819,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_50[] = {7299523,3151488,7643587,256,64,576};
int meta_buf_51[] = {3188352,3188416,7627203,7643587,7627203,256,64,256,64,256};
int meta_buf_52[] = {7627203,7561667,256,64,64,256};
int meta_buf_53[] = {7561667,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_54[] = {7299523,3188480,7545283,256,64,576};
int meta_buf_55[] = {3225408,3225344,7545283,7528899,64,64,64,256};
int meta_buf_56[] = {7528899,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_57[] = {7299523,3225472,7512515,256,64,576};
int meta_buf_58[] = {3262336,3262400,7627203,7512515,7528899,256,64,256,64,256};
int meta_buf_59[] = {7528899,7659971,256,64,64,256};
int meta_buf_60[] = {7659971,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_61[] = {7299523,3262464,7545283,256,64,576};
int meta_buf_62[] = {3299392,3299328,7545283,7545283,64,64,64,256};
int meta_buf_63[] = {7545283,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_64[] = {7299523,3299456,7578051,256,64,576};
int meta_buf_65[] = {3336384,3336320,7578051,7528899,7561667,64,256,256,64,256};
int meta_buf_66[] = {7561667,7545283,256,64,64,256};
int meta_buf_67[] = {7545283,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_68[] = {7299523,3336448,7578051,256,64,576};
int meta_buf_69[] = {3373376,3373312,7578051,7512515,64,64,64,256};
int meta_buf_70[] = {7512515,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_71[] = {7299523,3373440,7659971,256,64,576};
int meta_buf_72[] = {3410368,3410304,7561667,7659971,7643587,256,64,256,64,256};
int meta_buf_73[] = {7643587,7659971,256,64,64,256};
int meta_buf_74[] = {7659971,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_75[] = {7299523,3410432,7528899,256,64,576};
int meta_buf_76[] = {3447296,3447360,7528899,7528899,64,64,64,256};
int meta_buf_77[] = {7528899,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_78[] = {7299523,3447424,7627203,256,64,576};
int meta_buf_79[] = {3484352,3484288,7643587,7627203,7578051,256,64,256,64,256};
int meta_buf_80[] = {7578051,7594435,256,64,64,256};
int meta_buf_81[] = {7594435,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_82[] = {7299523,3484416,7659971,256,64,576};
int meta_buf_83[] = {3521344,3521280,7659971,7659971,64,64,64,256};
int meta_buf_84[] = {7659971,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_85[] = {7299523,3521408,7545283,256,64,576};
int meta_buf_86[] = {3558272,3558336,7578051,7545283,7578051,256,64,256,64,256};
int meta_buf_87[] = {7578051,7545283,256,64,64,256};
int meta_buf_88[] = {7545283,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_89[] = {7299523,3558400,7709123,256,64,576};
int meta_buf_90[] = {3595264,3595328,7709123,7725507,64,64,64,256};
int meta_buf_91[] = {7725507,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_92[] = {7299523,3595392,7758275,256,64,576};
int meta_buf_93[] = {3632320,3632256,7758275,7578051,7692739,64,256,256,64,256};
int meta_buf_94[] = {7692739,7659971,256,64,64,256};
int meta_buf_95[] = {7659971,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_96[] = {7299523,3632384,7725507,256,64,576};
int meta_buf_97[] = {3669248,3669312,7725507,7676355,64,64,64,256};
int meta_buf_98[] = {7676355,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_99[] = {7299523,3669376,7676355,256,64,576};
int meta_buf_100[] = {3706240,3706304,7676355,7692739,7741891,64,256,256,64,256};
int meta_buf_101[] = {7741891,7709123,256,64,64,256};
int meta_buf_102[] = {7709123,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_103[] = {7299523,3706368,7610819,256,64,576};
int meta_buf_104[] = {3743232,3743296,7610819,7610819,64,64,64,256};
int meta_buf_105[] = {7610819,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_106[] = {7299523,3743360,7758275,256,64,576};
int meta_buf_107[] = {3780288,3780224,7741891,7758275,7741891,256,64,256,64,256};
int meta_buf_108[] = {7741891,7758275,256,64,64,256};
int meta_buf_109[] = {7758275,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_110[] = {7299523,3780352,7676355,256,64,576};
int meta_buf_111[] = {3817216,3817280,7676355,7692739,64,64,64,256};
int meta_buf_112[] = {7692739,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_113[] = {7299523,3817344,7676355,256,64,576};
int meta_buf_114[] = {3854208,3854272,7676355,7741891,7692739,64,256,64,64,256};
int meta_buf_115[] = {7692739,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_116[] = {7299523,3854336,7676355,256,64,576};
int meta_buf_117[] = {3891200,3891264,7676355,7676355,64,64,64,256};
int meta_buf_118[] = {7676355,7299523,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_119[] = {7299523,3891328,7446979,256,256,576};
int meta_buf_120[] = {4038784,7446979,7446979,256,256,256,256};
int meta_buf_121[] = {7446979,7512515,2,1,256,64,16,32,16,32};
int meta_buf_122[] = {4039104,4039040,7512515,7512515,64,64,64,1024};
int meta_buf_123[] = {7512515,6709699,1,64,32,32,32,32,3,3,1,1,1,1,1,1};
int meta_buf_124[] = {6709699,4039168,7299523,1024,256,576};
int meta_buf_125[] = {4186624,7299523,7299523,256,256,256,1024};
int meta_buf_126[] = {7299523,6709699,2,1,256,64,32,64,32,64};
int meta_buf_127[] = {4186944,4186880,6709699,6709699,64,64,64,4096};
int meta_buf_128[] = {6709699,4350403,1,64,64,64,64,64,3,3,1,1,1,1,1,1};
int meta_buf_129[] = {4350403,4187008,6709699,4096,256,576};
int meta_buf_130[] = {4334464,6709699,4350403,256,256,256,4096};
int meta_buf_131[] = {4350403,5398979,2,1,256,64,64,128,64,128};
int meta_buf_132[] = {4334784,4334720,5398979,89285059,64,64,64,16384};
int meta_buf_133[] = {89285059,4350403,1,64,128,128,128,128,9,9,1,1,1,1,4,4};
int meta_buf_134[] = {4350403,4334848,89285059,16384,3,5184};
int meta_buf_135[] = {4350400,89285059,7512515,3,16384,3,16384};
int* meta_buffers[] = {meta_buf_0,meta_buf_1,meta_buf_2,meta_buf_3,meta_buf_4,meta_buf_5,meta_buf_6,meta_buf_7,meta_buf_8,meta_buf_9,meta_buf_10,meta_buf_11,meta_buf_12,meta_buf_13,meta_buf_14,meta_buf_15,meta_buf_16,meta_buf_17,meta_buf_18,meta_buf_19,meta_buf_20,meta_buf_21,meta_buf_22,meta_buf_23,meta_buf_24,meta_buf_25,meta_buf_26,meta_buf_27,meta_buf_28,meta_buf_29,meta_buf_30,meta_buf_31,meta_buf_32,meta_buf_33,meta_buf_34,meta_buf_35,meta_buf_36,meta_buf_37,meta_buf_38,meta_buf_39,meta_buf_40,meta_buf_41,meta_buf_42,meta_buf_43,meta_buf_44,meta_buf_45,meta_buf_46,meta_buf_47,meta_buf_48,meta_buf_49,meta_buf_50,meta_buf_51,meta_buf_52,meta_buf_53,meta_buf_54,meta_buf_55,meta_buf_56,meta_buf_57,meta_buf_58,meta_buf_59,meta_buf_60,meta_buf_61,meta_buf_62,meta_buf_63,meta_buf_64,meta_buf_65,meta_buf_66,meta_buf_67,meta_buf_68,meta_buf_69,meta_buf_70,meta_buf_71,meta_buf_72,meta_buf_73,meta_buf_74,meta_buf_75,meta_buf_76,meta_buf_77,meta_buf_78,meta_buf_79,meta_buf_80,meta_buf_81,meta_buf_82,meta_buf_83,meta_buf_84,meta_buf_85,meta_buf_86,meta_buf_87,meta_buf_88,meta_buf_89,meta_buf_90,meta_buf_91,meta_buf_92,meta_buf_93,meta_buf_94,meta_buf_95,meta_buf_96,meta_buf_97,meta_buf_98,meta_buf_99,meta_buf_100,meta_buf_101,meta_buf_102,meta_buf_103,meta_buf_104,meta_buf_105,meta_buf_106,meta_buf_107,meta_buf_108,meta_buf_109,meta_buf_110,meta_buf_111,meta_buf_112,meta_buf_113,meta_buf_114,meta_buf_115,meta_buf_116,meta_buf_117,meta_buf_118,meta_buf_119,meta_buf_120,meta_buf_121,meta_buf_122,meta_buf_123,meta_buf_124,meta_buf_125,meta_buf_126,meta_buf_127,meta_buf_128,meta_buf_129,meta_buf_130,meta_buf_131,meta_buf_132,meta_buf_133,meta_buf_134,meta_buf_135};

extern "C" void init() {
    //static_buffer = (float*)malloc(90333797 * sizeof(float));
}

extern "C" float* get_static_buffer(void) {
    return static_buffer;
}

extern "C" float* allocate_dynamic_buffer(int count) {
    if (dynamic_buffer) {
        free(dynamic_buffer);
        dynamic_buffer = nullptr;
    }
    dynamic_buffer = (float*)malloc(count * sizeof(float));
    return dynamic_buffer;
}

extern "C" float* get_dynamic_buffer(void) {
    return dynamic_buffer;
}
extern "C" void set_placeholder_value(int kernel_order, int offset, int value) {
    meta_buffers[kernel_order][offset] = value;
}

#ifndef INCLUDE_EIGEN
#define INCLUDE_EIGEN
#include <Eigen/Dense>
#endif

void sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(const int * meta_buffer)
{
    float *A = (static_buffer + meta_buffer[0]);
    float *B = (static_buffer + meta_buffer[1]);
    float *C = (static_buffer + meta_buffer[2]);

    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > a_mat(A, meta_buffer[3], meta_buffer[5]);
    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > b_mat(B, meta_buffer[5], meta_buffer[4]);
    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > c_mat(C, meta_buffer[3], meta_buffer[4]);

    c_mat.noalias() = a_mat * b_mat;
}


void fusedelementwise_f58106401a09ef1f1bb1ab126217f37add519a38ed66b58562cf18f4(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2624 shape=(16384,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x1309f2550>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2830 shape=(1, 16384), order=[N, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a599198>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2831 shape=(1, 16384), order=[N, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a599198>}
    float * v3 = (static_buffer + meta_buffer[2]);
    //load: 16384}
    const int D0 = meta_buffer[3];
    int d0;
    for (d0 = 0; d0 < D0; d0 += 1) {
        //<Transpose inputs={'x0': <Variable Variable2830 shape=(1, 16384), order=[N, C]>}, outputs={'y': <Variable Variable2407 shape=(1, 16384), order=[N, C]>}>}
        const float v4 = v2[d0];
        float v5;
        {
            v5 = v4;
        }
        //<ElementwiseAdd inputs={'x0': <Variable Variable2407 shape=(1, 16384), order=[N, C]>, 'x1': <ConstantVariable ConstantVariable2624 shape=(16384,), order=[C]>}, outputs={'y': <Variable Variable13 shape=(1, 16384), order=[N, C]>}>}
        const float v6 = v1[d0];
        float v7;
        {
            v7 = v5 + v6;
        }
        //<Relu inputs={'x0': <Variable Variable13 shape=(1, 16384), order=[N, C]>}, outputs={'y': <Variable Variable2831 shape=(1, 16384), order=[N, C]>}>}
        float v8;
        {
            v8 = v7 > 0 ? v7 : 0;
        }
        v3[d0] = v8;
    }
}


void reshape_f6c88dc1fd9479f62d789912530e6a5c7c51c73de368540e8b8e1ceb(const int * meta_buffer )
{
    const float *x = (static_buffer + meta_buffer[0]);
    float *y = (static_buffer + meta_buffer[1]);

    const int N = meta_buffer[2];

    for (int gid = 0; gid < N; gid += 1) {
        y[gid] = x[gid];
    }
}


void transpose_b7fd92b9b4c26ab13df7e90700e52641c53c7094a74cf9be8eaa009f(const int * meta_buffer)
{
    //<Variable Variable15 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d45f8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2537 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d4588>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable15 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2537 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(const int * meta_buffer)
{
    const float *im = (static_buffer + meta_buffer[0]);
    float *col = (static_buffer + meta_buffer[1]);

    const int N = meta_buffer[2];
    const int C1 = meta_buffer[3];
    const int H1 = meta_buffer[4];
    const int W1 = meta_buffer[5];
    const int H2 = meta_buffer[6];
    const int W2 = meta_buffer[7];
    const int KH = meta_buffer[8];
    const int KW = meta_buffer[9];
    const int DH = meta_buffer[10];
    const int DW = meta_buffer[11];
    const int SH = meta_buffer[12];
    const int SW = meta_buffer[13];
    const int PH = meta_buffer[14];
    const int PW = meta_buffer[15];

    for (int gid = 0; gid < N*H2*W2*KH*KW*C1; gid += 1) {
        const int c1 = gid % C1;
        const int kw = gid / C1 % KW;
        const int kh = gid / C1 / KW % KH;
        const int w2 = gid / C1 / KW / KH % W2;
        const int h2 = gid / C1 / KW / KH / W2 % H2;
        const int  n = gid / C1 / KW / KH / W2 / H2;
        
        const int h1 = h2 * SH - PH + kh * DH;
        const int w1 = w2 * SW - PW + kw * DW;

        col[gid] = (h1 < 0 || h1 >= H1 || w1 < 0 || w1 >= W1) ? 0 : im[((n*H1+h1)*W1+w1)*C1+c1];
    }
}


void fusedelementwise_9d37714cb5da35257207e81f23ceee818952af9a1fc3b4aebced1451(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2622 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130905518>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2623 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130905470>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2828 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d4390>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2829 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d4048>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2828 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable16 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable16 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2622 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2404 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2404 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2623 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable24 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable24 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable25 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable25 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2829 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_2e0ce6a3072184a0f4774826e8ec90261c193bb4970aa9192070fec0(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2620 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130905908>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2621 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130905da0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2825 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c91d0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2826 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d45f8>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2827 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9be0>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 256}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2825 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable26 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v3[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable26 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2621 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2401 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2401 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2826 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2486 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v4[d0*v7 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2486 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2620 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2827 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v9;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_4b5e16381d3855b9c2eaf0755d8ca7557690b04b5ab5dc488bdb0049(const int * meta_buffer)
{
    //<Variable Variable35 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9be0>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2543 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9e48>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable35 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2543 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_e0e788854bd579f85116dca8e520ef7a5876db2ae33503b566bb5f9b(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2618 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a649908>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2619 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x130628358>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2823 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d44a8>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2824 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d44a8>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2823 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable36 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable36 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2619 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2398 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v8;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2398 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2618 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable44 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v7;
            }
            //<Relu inputs={'x0': <Variable Variable44 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable45 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable45 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2824 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_f6ea8310e0d517988df45add40295a58d753ce4ad6544c842942e841(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2616 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a649b00>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2617 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a649b38>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2820 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9048>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2821 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9be0>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2822 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9cf8>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 256}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2820 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable46 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v3[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable46 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2617 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2395 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2395 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2821 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2488 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v4[d0*v7 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2488 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2616 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2822 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v9;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_760203947e741c85ec0516f0f1fd3f0658bafb611658f9bf891d2511(const int * meta_buffer)
{
    //<Variable Variable55 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9cf8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2549 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9d68>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable55 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2549 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_9409f5c2d62fc75dbe4f877027e582c64e862678c491db6fae294b24(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2614 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a649e48>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2615 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6496a0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2818 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c96d8>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2819 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c92e8>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2818 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable56 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable56 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2615 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2392 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v8;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2392 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2614 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable64 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v7;
            }
            //<Relu inputs={'x0': <Variable Variable64 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable65 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable65 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2819 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_d6e6f25812d6f6c1eb1990b36b58f55fbe3affac4ee50530defca799(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2612 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a649d68>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2613 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x13061e9e8>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2815 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9cf8>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2816 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9b70>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2817 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9cf8>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 256}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2816 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable66 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v4[d0 + d1*v7];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable66 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2612 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2389 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2389 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2815 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2490 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v3[d0*v6 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2490 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2613 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2817 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v10;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_1f8680c169f361d10d3224f8d20dcd44a1f401bcedc9601ca7e470ef(const int * meta_buffer)
{
    //<Variable Variable75 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9cf8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2555 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9eb8>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable75 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2555 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_08cddee2b046bf1a29902fa68fb9137d471bc53d4ed312ad27bd08ca(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2610 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x13061e400>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2611 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x13061e780>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2813 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c90b8>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2814 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c90b8>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2813 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable76 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable76 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2610 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2386 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2386 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2611 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable84 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable84 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable85 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable85 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2814 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_fc81bc871275c0fe28283d2dbb9946ac30a9e50efaacac02c4d93632(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2608 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fecbb00>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2609 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fecbbe0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2810 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c99b0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2811 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9cf8>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2812 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9b38>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 256}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2810 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable86 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v3[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable86 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2608 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2383 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2383 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2811 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2492 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v4[d0*v7 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2492 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2609 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2812 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v10;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_6f4f35a4f991ae83680f0e280c95ed71e70ae766d7e074684610f934(const int * meta_buffer)
{
    //<Variable Variable95 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9b38>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2561 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9898>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable95 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2561 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_e37c637296815835b819ab85085a35a897b9608e7afaaf952f086c4e(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2606 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fecbb70>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2607 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x12fecb668>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2808 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c92b0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2809 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9240>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2808 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable96 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable96 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2606 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2380 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2380 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2607 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable104 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable104 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable105 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable105 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2809 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_5a6128be7ddfc0f93c615d5d471f453af0c3d2c4f652951a70f5acea(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2604 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63d668>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2605 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63d8d0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2805 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9b38>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2806 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c94e0>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2807 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9b38>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 256}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2806 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable106 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v4[d0 + d1*v7];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable106 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2604 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2377 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2377 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2805 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2494 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v3[d0*v6 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2494 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2605 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2807 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v10;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_4a703ed8257dcb8e6d5552606d97d8fcf882628dfbe93f9653524f56(const int * meta_buffer)
{
    //<Variable Variable115 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9b38>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2567 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9400>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable115 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2567 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_282c87f1fae9c852632c8afcf8a46fa9f49d4ba1840ac83f688ebdf1(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2602 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63ddd8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2603 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63d898>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2803 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9588>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2804 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9588>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2803 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable116 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable116 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2602 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2374 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2374 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2603 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable124 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable124 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable125 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable125 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2804 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_f90baa03f69d888ffa6aac902cf0d0d38a73e310bf7239de4f26d688(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2600 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63deb8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2601 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63dcc0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2800 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5c9b38>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2801 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc400>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2802 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bcb00>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 256}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2801 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable126 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v4[d0 + d1*v7];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable126 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2600 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2371 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2371 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2800 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2496 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v3[d0*v6 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2496 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2601 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2802 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v10;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_8ef52db057a0cd7ddaa7c0edb7bb1e1a780b87788933c34e97041ae3(const int * meta_buffer)
{
    //<Variable Variable135 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bcb00>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2573 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bcdd8>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable135 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2573 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_3eafdfdd48742b09698dde234e3d5caaed62adb2cde72f6fb1846ebd(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2598 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63dc18>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2599 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63d160>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2798 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc908>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2799 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bca20>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2798 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable136 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable136 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2598 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2368 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2368 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2599 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable144 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable144 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable145 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable145 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2799 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_3537fb340f1cc16cc8fdd65a06480be11b18c44f5cc8d4faf752ab0b(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2596 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63d048>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2597 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63dac8>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2795 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bcb00>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2796 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bcb38>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2797 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bcb00>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 256}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2796 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable146 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v4[d0 + d1*v7];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable146 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2597 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2365 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2365 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2795 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2498 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v3[d0*v6 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2498 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2596 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2797 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v9;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_bbe7574e6a0ba840fdcc3e73565e6a0fc115a1ba7d1ea51cfae2b878(const int * meta_buffer)
{
    //<Variable Variable155 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bcb00>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2579 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc630>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable155 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2579 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_1e79bceeb893c7b725021d9e648b69c744273db819294c01f5d754ce(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2594 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63da58>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2595 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63dfd0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2793 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc2b0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2794 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc240>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2793 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable156 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable156 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2594 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2362 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2362 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2595 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable164 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable164 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable165 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable165 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2794 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_c5e3bf93b5af87f834418bfd096d1ed1a29ea73266121fea80e39b4a(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2592 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63de10>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2593 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a63def0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2790 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bcb00>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2791 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc048>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2792 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc128>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 256}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2791 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable166 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v4[d0 + d1*v7];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable166 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2593 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2359 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2359 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2790 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2500 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v3[d0*v6 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2500 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2592 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2792 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v9;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_a404e37cca3ada664e666cc83d2e17f7b272a9657a7fd95baeb0427a(const int * meta_buffer)
{
    //<Variable Variable175 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc128>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2585 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0e80>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable175 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2585 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_3529d6be2d93e13f540c519cf6fac6d2b538867d1a18faa07856ec21(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2590 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632be0>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2591 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6328d0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2788 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc550>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2789 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc550>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2788 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable176 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable176 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2590 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2356 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2356 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2591 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable184 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable184 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable185 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable185 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2789 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_738aa4797215bd5badcbffc58de637d987aa47aa37212ae3902c8f41(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2588 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6322e8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2589 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6320f0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2785 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0748>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2786 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5bc128>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2787 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b05c0>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 256}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2785 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable186 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v3[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable186 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2588 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2353 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2353 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2786 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2502 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v4[d0*v7 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2502 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2589 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2787 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v10;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_65a1c9e1dad1af46ba823c90861bb970fce4c800358028a00ac74c5a(const int * meta_buffer)
{
    //<Variable Variable195 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b05c0>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2591 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0518>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable195 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2591 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_266386fad03a85e2b60195cb35f65fec377add3762a1f34bc7bdd2ac(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2586 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632240>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2587 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632ef0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2783 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b06a0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2784 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b00f0>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2783 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable196 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable196 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2586 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2350 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2350 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2587 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable204 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable204 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable205 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable205 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2784 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_95ef45b843b64d0d9911cd52fec191aa9841a87441e83b5073605799(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2584 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632438>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2585 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632780>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2780 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b05c0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2781 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0c88>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2782 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0b38>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 256}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2781 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable206 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v4[d0 + d1*v7];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable206 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2584 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2347 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2347 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2780 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2504 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v3[d0*v6 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2504 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2585 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2782 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v10;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_8968aa9bf83d4c7e26716ce230eece3d23fecfd57063efe82986202c(const int * meta_buffer)
{
    //<Variable Variable215 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0b38>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2597 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0fd0>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable215 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2597 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_f56e2cc23d3b3e885fda45321e8796cef1eedc8e9eac2bc98358422b(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2582 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632c50>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2583 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632d30>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2778 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0278>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2779 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0278>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2778 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable216 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable216 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2583 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2344 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v8;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2344 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2582 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable224 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v7;
            }
            //<Relu inputs={'x0': <Variable Variable224 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable225 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable225 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2779 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_8404953d845efedcb97b09fcda133e16d942eb1e073338adef3bb547(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2580 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632b70>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2581 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632a58>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2775 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0b38>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2776 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0b00>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2777 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b07f0>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 256}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2776 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable226 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v4[d0 + d1*v7];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable226 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2580 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2341 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2341 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2775 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2506 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v3[d0*v6 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2506 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2581 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2777 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v10;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_08329fc095284da7f902b2b68e577d39530c4929527cf66538797202(const int * meta_buffer)
{
    //<Variable Variable235 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b07f0>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2603 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0898>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable235 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2603 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_290b18d19cdf2846e2189c485a4d13032282c8bb92430feb1d3c9d19(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2578 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632748>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2579 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632898>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2773 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0cf8>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2774 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0cf8>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2773 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable236 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable236 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2578 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2338 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2338 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2579 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable244 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable244 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable245 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable245 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2774 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_e81270d7a0f77c30fdd225f41c82482a4c5f600080df12ef26b50f49(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2576 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632518>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2577 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6325c0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2770 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b07f0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2771 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b04e0>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2772 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b07f0>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 256}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2771 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable246 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v4[d0 + d1*v7];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable246 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2577 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2335 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2335 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2770 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2508 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v3[d0*v6 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2508 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2576 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2772 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v9;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_e24c8bf00c4f3490c90e5058d91ae03dd40e078676481f660fa3a033(const int * meta_buffer)
{
    //<Variable Variable255 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b07f0>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2609 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0438>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable255 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2609 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_986ab8f8ba8ec3a6781a3dfa03c54822f3b93fb10a59fa1b27de7b48(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2574 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a632128>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2575 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6322b0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2768 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7be0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2769 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7c50>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2768 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable256 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable256 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2575 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2332 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v8;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2332 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2574 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable264 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v7;
            }
            //<Relu inputs={'x0': <Variable Variable264 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable265 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable265 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2769 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_2a07f0aa3151abe127188b844999774200c3ddc6d9f14608127a6b58(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2572 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6286d8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2573 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628748>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2765 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7e48>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2766 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b07f0>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2767 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7668>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 256}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2765 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable266 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v3[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable266 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2572 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2329 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2329 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2766 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2510 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v4[d0*v7 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2510 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2573 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2767 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v10;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_1460b743c71eaedc105c9e27782fb1917e3efcffcbe070ccc45dc66d(const int * meta_buffer)
{
    //<Variable Variable275 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7668>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2615 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7160>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable275 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2615 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_8b6140bafa04b31207312a05165042bd12ec81937cffb1118f3490c7(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2570 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628048>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2571 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6285f8>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2763 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7d30>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2764 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a73c8>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2763 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable276 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable276 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2571 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2326 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v8;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2326 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2570 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable284 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v7;
            }
            //<Relu inputs={'x0': <Variable Variable284 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable285 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable285 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2764 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_30d98157a86d72413b7a6aa7c6076bbeaaeb68a0fa4b32f8ccd9a884(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2568 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6283c8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2569 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628cc0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2760 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7400>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2761 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7668>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2762 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7da0>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 256}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2760 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable286 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v3[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable286 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2569 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2323 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2323 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2761 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2512 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v4[d0*v7 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2512 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2568 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2762 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v9;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_af33e7f973463c3307557968e4d61bc0a734e6103f6604674d412d0d(const int * meta_buffer)
{
    //<Variable Variable295 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7da0>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2621 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7b38>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable295 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2621 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_b6fefa6a6e5a2687b22035b0a09f2f303006590c6525d4694a85f3cd(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2566 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628da0>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2567 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628128>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2758 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0a90>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2759 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0a90>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2758 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable296 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable296 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2567 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2320 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v8;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2320 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2566 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable304 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v7;
            }
            //<Relu inputs={'x0': <Variable Variable304 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable305 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable305 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2759 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_91c60515a2157d8e8129d90670647abc0325b9a21f672788627d8d70(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2564 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628c18>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2565 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628b00>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2755 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7da0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2756 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7f28>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2757 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7da0>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 256}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int v7 = meta_buffer[6];
    //load: 256}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2756 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable306 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v4[d0 + d1*v7];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable306 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2564 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2317 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v9;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2317 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2755 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2514 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v3[d0*v6 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2514 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2565 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2757 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v10;
            }
            v5[d0*v8 + d1] = v16;
        }
    }
}


void transpose_6c8a9d1608d92da43ee2f2054257db77fc099b4c7fc0526654c5b375(const int * meta_buffer)
{
    //<Variable Variable315 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7da0>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2627 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7e10>}
    float * v2 = (static_buffer + meta_buffer[1]);
    //load: 256}
    const int v3 = meta_buffer[2];
    //load: 64}
    const int v4 = meta_buffer[3];
    //load: 64}
    const int D0 = meta_buffer[4];
    //load: 256}
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable315 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2627 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void fusedelementwise_13ebc87498a94f8424ca37c5d6abc339864294c44f36571349d29098(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2562 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628f60>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2563 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628dd8>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2753 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a599400>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2754 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5995f8>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2753 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable316 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable316 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2563 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2314 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v8;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2314 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2562 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable324 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v7;
            }
            //<Relu inputs={'x0': <Variable Variable324 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable325 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable325 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2754 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_db94100b63009d3e44d68a6c4292a1ed04d726151d3ad28fef816bdb(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2560 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628908>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2561 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628fd0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2750 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a599470>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2751 shape=(1, 64, 16, 16), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7da0>}
    const float * v4 = (static_buffer + meta_buffer[3]);
    //}
    //<Variable Variable2752 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a599908>}
    float * v5 = (static_buffer + meta_buffer[4]);
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 256}
    const int v7 = meta_buffer[6];
    //load: 64}
    const int v8 = meta_buffer[7];
    //load: 64}
    const int D0 = meta_buffer[8];
    //load: 256}
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2750 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable326 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v11 = v3[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable326 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2561 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2311 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 * v10;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2311 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <Variable Variable2751 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2516 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v14 = v4[d0*v7 + d1];
            float v15;
            {
                v15 = v13 + v14;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2516 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2560 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable335 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v16;
            {
                v16 = v15 + v9;
            }
            //<Transpose inputs={'x0': <Variable Variable335 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2752 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v17;
            {
                v17 = v16;
            }
            v5[d0 + d1*v8] = v17;
        }
    }
}


void fusedelementwise_b8ea63c6c8478615104fd3dee8612bd94359a2bf061cb7245b6dea8a(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2558 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628940>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2559 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a6289e8>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2748 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7470>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2749 shape=(1, 16, 16, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7470>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 256}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2748 shape=(1, 16, 16, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable336 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable336 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2559 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2308 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v8;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2308 shape=(1, 64, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2558 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable344 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v7;
            }
            //<Relu inputs={'x0': <Variable Variable344 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable345 shape=(1, 64, 16, 16), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable345 shape=(1, 64, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2749 shape=(1, 16, 16, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_95373c3f24c677b3d0c93c7c0b09b6c7dea821159579035fe706387b(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2557 shape=(256,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d49b0>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2746 shape=(1, 16, 16, 256), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7908>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2747 shape=(1, 16, 16, 256), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7908>}
    float * v3 = (static_buffer + meta_buffer[2]);
    //load: 256}
    const int v4 = meta_buffer[3];
    //load: 256}
    const int v5 = meta_buffer[4];
    //load: 256}
    const int D0 = meta_buffer[5];
    //load: 256}
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2746 shape=(1, 16, 16, 256), order=[N, H, W, C]>}, outputs={'y': <Variable Variable346 shape=(1, 256, 16, 16), order=[N, C, H, W]>}>}
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable346 shape=(1, 256, 16, 16), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2557 shape=(256,), order=[C]>}, outputs={'y': <Variable Variable347 shape=(1, 256, 16, 16), order=[N, C, H, W]>}>}
            float v9;
            {
                v9 = v8 + v6;
            }
            //<Transpose inputs={'x0': <Variable Variable347 shape=(1, 256, 16, 16), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2747 shape=(1, 16, 16, 256), order=[N, H, W, C]>}>}
            float v10;
            {
                v10 = v9;
            }
            v3[d0 + d1*v5] = v10;
        }
    }
}


void depth2space_fb4d08ab9e4cdbc9170db5af72396a76eb9781af5c65d1dd49b86fdd(const int * meta_buffer)
{
    const float *x = (static_buffer + meta_buffer[0]);
    float *y = (static_buffer + meta_buffer[1]);
    const int r = meta_buffer[2];

    const int N = meta_buffer[3];
    const int C1 = meta_buffer[4];
    const int C2 = meta_buffer[5];
    const int H1 = meta_buffer[6];
    const int H2 = meta_buffer[7];
    const int W1 = meta_buffer[8];
    const int W2 = meta_buffer[9];

    for (int gid = 0; gid < N*H2*W2*C2; gid += 1) {
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


void fusedelementwise_2bb9ce1b353b7b4c0164a42db40811653c7ef5d5e3f296272cb3527f(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2555 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d4208>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2556 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a628a58>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2744 shape=(1, 32, 32, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7cc0>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2745 shape=(1, 32, 32, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5a7cc0>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 1024}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2744 shape=(1, 32, 32, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable348 shape=(1, 64, 32, 32), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable348 shape=(1, 64, 32, 32), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2555 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2305 shape=(1, 64, 32, 32), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2305 shape=(1, 64, 32, 32), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2556 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable355 shape=(1, 64, 32, 32), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable355 shape=(1, 64, 32, 32), order=[N, C, H, W]>}, outputs={'y': <Variable Variable356 shape=(1, 64, 32, 32), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable356 shape=(1, 64, 32, 32), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2745 shape=(1, 32, 32, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_52c30fbdb7fa2c4972a97e36697f7bf8485ba8334f101581c564d566(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2554 shape=(256,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d4128>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2742 shape=(1, 32, 32, 256), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0710>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2743 shape=(1, 32, 32, 256), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0710>}
    float * v3 = (static_buffer + meta_buffer[2]);
    //load: 256}
    const int v4 = meta_buffer[3];
    //load: 256}
    const int v5 = meta_buffer[4];
    //load: 256}
    const int D0 = meta_buffer[5];
    //load: 1024}
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2742 shape=(1, 32, 32, 256), order=[N, H, W, C]>}, outputs={'y': <Variable Variable357 shape=(1, 256, 32, 32), order=[N, C, H, W]>}>}
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable357 shape=(1, 256, 32, 32), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2554 shape=(256,), order=[C]>}, outputs={'y': <Variable Variable358 shape=(1, 256, 32, 32), order=[N, C, H, W]>}>}
            float v9;
            {
                v9 = v8 + v6;
            }
            //<Transpose inputs={'x0': <Variable Variable358 shape=(1, 256, 32, 32), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2743 shape=(1, 32, 32, 256), order=[N, H, W, C]>}>}
            float v10;
            {
                v10 = v9;
            }
            v3[d0 + d1*v5] = v10;
        }
    }
}


void fusedelementwise_c95229d232a4030bb1d1871c63e2a75083d8765a4d87ec6364ca43cd(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2552 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d46d8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2553 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d40f0>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2740 shape=(1, 64, 64, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0208>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2741 shape=(1, 64, 64, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5b0208>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 4096}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2740 shape=(1, 64, 64, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable359 shape=(1, 64, 64, 64), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable359 shape=(1, 64, 64, 64), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2552 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2302 shape=(1, 64, 64, 64), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2302 shape=(1, 64, 64, 64), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2553 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable366 shape=(1, 64, 64, 64), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable366 shape=(1, 64, 64, 64), order=[N, C, H, W]>}, outputs={'y': <Variable Variable367 shape=(1, 64, 64, 64), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable367 shape=(1, 64, 64, 64), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2741 shape=(1, 64, 64, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_f350f7326a3486c4ec7d27a1ff47128b344d436387703253d443bf00(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2551 shape=(256,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d4b70>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2738 shape=(1, 64, 64, 256), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a599748>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2739 shape=(1, 64, 64, 256), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5990f0>}
    float * v3 = (static_buffer + meta_buffer[2]);
    //load: 256}
    const int v4 = meta_buffer[3];
    //load: 256}
    const int v5 = meta_buffer[4];
    //load: 256}
    const int D0 = meta_buffer[5];
    //load: 4096}
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2738 shape=(1, 64, 64, 256), order=[N, H, W, C]>}, outputs={'y': <Variable Variable368 shape=(1, 256, 64, 64), order=[N, C, H, W]>}>}
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable368 shape=(1, 256, 64, 64), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2551 shape=(256,), order=[C]>}, outputs={'y': <Variable Variable369 shape=(1, 256, 64, 64), order=[N, C, H, W]>}>}
            float v9;
            {
                v9 = v8 + v6;
            }
            //<Transpose inputs={'x0': <Variable Variable369 shape=(1, 256, 64, 64), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2739 shape=(1, 64, 64, 256), order=[N, H, W, C]>}>}
            float v10;
            {
                v10 = v9;
            }
            v3[d0 + d1*v5] = v10;
        }
    }
}


void fusedelementwise_73ae9dc6e89c264cb3a9e2e0169756234e73dd755aed5dabdc8bf5cd(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2549 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d49e8>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<ConstantVariable ConstantVariable2550 shape=(64,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d4e48>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2736 shape=(1, 128, 128, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a599550>}
    const float * v3 = (static_buffer + meta_buffer[2]);
    //}
    //<Variable Variable2737 shape=(1, 128, 128, 64), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5994e0>}
    float * v4 = (static_buffer + meta_buffer[3]);
    //load: 64}
    const int v5 = meta_buffer[4];
    //load: 64}
    const int v6 = meta_buffer[5];
    //load: 64}
    const int D0 = meta_buffer[6];
    //load: 16384}
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2736 shape=(1, 128, 128, 64), order=[N, H, W, C]>}, outputs={'y': <Variable Variable370 shape=(1, 64, 128, 128), order=[N, C, H, W]>}>}
            const float v9 = v3[d0 + d1*v5];
            float v10;
            {
                v10 = v9;
            }
            //<ElementwiseMul inputs={'x0': <Variable Variable370 shape=(1, 64, 128, 128), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2549 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable2299 shape=(1, 64, 128, 128), order=[N, C, H, W]>}>}
            float v11;
            {
                v11 = v10 * v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable2299 shape=(1, 64, 128, 128), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2550 shape=(64,), order=[C]>}, outputs={'y': <Variable Variable377 shape=(1, 64, 128, 128), order=[N, C, H, W]>}>}
            float v12;
            {
                v12 = v11 + v8;
            }
            //<Relu inputs={'x0': <Variable Variable377 shape=(1, 64, 128, 128), order=[N, C, H, W]>}, outputs={'y': <Variable Variable378 shape=(1, 64, 128, 128), order=[N, C, H, W]>}>}
            float v13;
            {
                v13 = v12 > 0 ? v12 : 0;
            }
            //<Transpose inputs={'x0': <Variable Variable378 shape=(1, 64, 128, 128), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2737 shape=(1, 128, 128, 64), order=[N, H, W, C]>}>}
            float v14;
            {
                v14 = v13;
            }
            v4[d0 + d1*v6] = v14;
        }
    }
}


void fusedelementwise_3efa18fc173586fd639e5aa6537cfce86d2d5ec645d2c05bf6392518(const int * meta_buffer)
{
    //<ConstantVariable ConstantVariable2548 shape=(3,), order=[C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d4a58>}
    const float * v1 = (static_buffer + meta_buffer[0]);
    //}
    //<Variable Variable2734 shape=(1, 128, 128, 3), order=[N, H, W, C]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5990b8>}
    const float * v2 = (static_buffer + meta_buffer[1]);
    //}
    //<Variable Variable2735 shape=(1, 3, 128, 128), order=[N, C, H, W]>}
    //load: <webdnn.backend.code_generator.allocator.Allocation object at 0x11a5d4860>}
    float * v3 = (static_buffer + meta_buffer[2]);
    //load: 3}
    const int v4 = meta_buffer[3];
    //load: 16384}
    const int v5 = meta_buffer[4];
    //load: 3}
    const int D0 = meta_buffer[5];
    //load: 16384}
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            //<Transpose inputs={'x0': <Variable Variable2734 shape=(1, 128, 128, 3), order=[N, H, W, C]>}, outputs={'y': <Variable Variable379 shape=(1, 3, 128, 128), order=[N, C, H, W]>}>}
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7;
            }
            //<ElementwiseAdd inputs={'x0': <Variable Variable379 shape=(1, 3, 128, 128), order=[N, C, H, W]>, 'x1': <ConstantVariable ConstantVariable2548 shape=(3,), order=[C]>}, outputs={'y': <Variable Variable380 shape=(1, 3, 128, 128), order=[N, C, H, W]>}>}
            float v9;
            {
                v9 = v8 + v6;
            }
            //<Tanh inputs={'x0': <Variable Variable380 shape=(1, 3, 128, 128), order=[N, C, H, W]>}, outputs={'y': <Variable Variable2735 shape=(1, 3, 128, 128), order=[N, C, H, W]>}>}
            float v10;
            {
                v10 = tanh(v9);
            }
            v3[d0*v5 + d1] = v10;
        }
    }
}

extern "C" void run() {
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_0);
fusedelementwise_f58106401a09ef1f1bb1ab126217f37add519a38ed66b58562cf18f4(meta_buf_1);
reshape_f6c88dc1fd9479f62d789912530e6a5c7c51c73de368540e8b8e1ceb(meta_buf_2);
transpose_b7fd92b9b4c26ab13df7e90700e52641c53c7094a74cf9be8eaa009f(meta_buf_3);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_4);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_5);
fusedelementwise_9d37714cb5da35257207e81f23ceee818952af9a1fc3b4aebced1451(meta_buf_6);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_7);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_8);
fusedelementwise_2e0ce6a3072184a0f4774826e8ec90261c193bb4970aa9192070fec0(meta_buf_9);
transpose_4b5e16381d3855b9c2eaf0755d8ca7557690b04b5ab5dc488bdb0049(meta_buf_10);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_11);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_12);
fusedelementwise_e0e788854bd579f85116dca8e520ef7a5876db2ae33503b566bb5f9b(meta_buf_13);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_14);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_15);
fusedelementwise_f6ea8310e0d517988df45add40295a58d753ce4ad6544c842942e841(meta_buf_16);
transpose_760203947e741c85ec0516f0f1fd3f0658bafb611658f9bf891d2511(meta_buf_17);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_18);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_19);
fusedelementwise_9409f5c2d62fc75dbe4f877027e582c64e862678c491db6fae294b24(meta_buf_20);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_21);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_22);
fusedelementwise_d6e6f25812d6f6c1eb1990b36b58f55fbe3affac4ee50530defca799(meta_buf_23);
transpose_1f8680c169f361d10d3224f8d20dcd44a1f401bcedc9601ca7e470ef(meta_buf_24);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_25);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_26);
fusedelementwise_08cddee2b046bf1a29902fa68fb9137d471bc53d4ed312ad27bd08ca(meta_buf_27);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_28);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_29);
fusedelementwise_fc81bc871275c0fe28283d2dbb9946ac30a9e50efaacac02c4d93632(meta_buf_30);
transpose_6f4f35a4f991ae83680f0e280c95ed71e70ae766d7e074684610f934(meta_buf_31);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_32);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_33);
fusedelementwise_e37c637296815835b819ab85085a35a897b9608e7afaaf952f086c4e(meta_buf_34);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_35);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_36);
fusedelementwise_5a6128be7ddfc0f93c615d5d471f453af0c3d2c4f652951a70f5acea(meta_buf_37);
transpose_4a703ed8257dcb8e6d5552606d97d8fcf882628dfbe93f9653524f56(meta_buf_38);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_39);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_40);
fusedelementwise_282c87f1fae9c852632c8afcf8a46fa9f49d4ba1840ac83f688ebdf1(meta_buf_41);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_42);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_43);
fusedelementwise_f90baa03f69d888ffa6aac902cf0d0d38a73e310bf7239de4f26d688(meta_buf_44);
transpose_8ef52db057a0cd7ddaa7c0edb7bb1e1a780b87788933c34e97041ae3(meta_buf_45);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_46);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_47);
fusedelementwise_3eafdfdd48742b09698dde234e3d5caaed62adb2cde72f6fb1846ebd(meta_buf_48);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_49);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_50);
fusedelementwise_3537fb340f1cc16cc8fdd65a06480be11b18c44f5cc8d4faf752ab0b(meta_buf_51);
transpose_bbe7574e6a0ba840fdcc3e73565e6a0fc115a1ba7d1ea51cfae2b878(meta_buf_52);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_53);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_54);
fusedelementwise_1e79bceeb893c7b725021d9e648b69c744273db819294c01f5d754ce(meta_buf_55);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_56);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_57);
fusedelementwise_c5e3bf93b5af87f834418bfd096d1ed1a29ea73266121fea80e39b4a(meta_buf_58);
transpose_a404e37cca3ada664e666cc83d2e17f7b272a9657a7fd95baeb0427a(meta_buf_59);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_60);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_61);
fusedelementwise_3529d6be2d93e13f540c519cf6fac6d2b538867d1a18faa07856ec21(meta_buf_62);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_63);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_64);
fusedelementwise_738aa4797215bd5badcbffc58de637d987aa47aa37212ae3902c8f41(meta_buf_65);
transpose_65a1c9e1dad1af46ba823c90861bb970fce4c800358028a00ac74c5a(meta_buf_66);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_67);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_68);
fusedelementwise_266386fad03a85e2b60195cb35f65fec377add3762a1f34bc7bdd2ac(meta_buf_69);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_70);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_71);
fusedelementwise_95ef45b843b64d0d9911cd52fec191aa9841a87441e83b5073605799(meta_buf_72);
transpose_8968aa9bf83d4c7e26716ce230eece3d23fecfd57063efe82986202c(meta_buf_73);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_74);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_75);
fusedelementwise_f56e2cc23d3b3e885fda45321e8796cef1eedc8e9eac2bc98358422b(meta_buf_76);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_77);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_78);
fusedelementwise_8404953d845efedcb97b09fcda133e16d942eb1e073338adef3bb547(meta_buf_79);
transpose_08329fc095284da7f902b2b68e577d39530c4929527cf66538797202(meta_buf_80);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_81);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_82);
fusedelementwise_290b18d19cdf2846e2189c485a4d13032282c8bb92430feb1d3c9d19(meta_buf_83);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_84);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_85);
fusedelementwise_e81270d7a0f77c30fdd225f41c82482a4c5f600080df12ef26b50f49(meta_buf_86);
transpose_e24c8bf00c4f3490c90e5058d91ae03dd40e078676481f660fa3a033(meta_buf_87);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_88);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_89);
fusedelementwise_986ab8f8ba8ec3a6781a3dfa03c54822f3b93fb10a59fa1b27de7b48(meta_buf_90);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_91);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_92);
fusedelementwise_2a07f0aa3151abe127188b844999774200c3ddc6d9f14608127a6b58(meta_buf_93);
transpose_1460b743c71eaedc105c9e27782fb1917e3efcffcbe070ccc45dc66d(meta_buf_94);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_95);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_96);
fusedelementwise_8b6140bafa04b31207312a05165042bd12ec81937cffb1118f3490c7(meta_buf_97);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_98);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_99);
fusedelementwise_30d98157a86d72413b7a6aa7c6076bbeaaeb68a0fa4b32f8ccd9a884(meta_buf_100);
transpose_af33e7f973463c3307557968e4d61bc0a734e6103f6604674d412d0d(meta_buf_101);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_102);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_103);
fusedelementwise_b6fefa6a6e5a2687b22035b0a09f2f303006590c6525d4694a85f3cd(meta_buf_104);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_105);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_106);
fusedelementwise_91c60515a2157d8e8129d90670647abc0325b9a21f672788627d8d70(meta_buf_107);
transpose_6c8a9d1608d92da43ee2f2054257db77fc099b4c7fc0526654c5b375(meta_buf_108);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_109);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_110);
fusedelementwise_13ebc87498a94f8424ca37c5d6abc339864294c44f36571349d29098(meta_buf_111);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_112);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_113);
fusedelementwise_db94100b63009d3e44d68a6c4292a1ed04d726151d3ad28fef816bdb(meta_buf_114);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_115);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_116);
fusedelementwise_b8ea63c6c8478615104fd3dee8612bd94359a2bf061cb7245b6dea8a(meta_buf_117);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_118);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_119);
fusedelementwise_95373c3f24c677b3d0c93c7c0b09b6c7dea821159579035fe706387b(meta_buf_120);
depth2space_fb4d08ab9e4cdbc9170db5af72396a76eb9781af5c65d1dd49b86fdd(meta_buf_121);
fusedelementwise_2bb9ce1b353b7b4c0164a42db40811653c7ef5d5e3f296272cb3527f(meta_buf_122);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_123);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_124);
fusedelementwise_52c30fbdb7fa2c4972a97e36697f7bf8485ba8334f101581c564d566(meta_buf_125);
depth2space_fb4d08ab9e4cdbc9170db5af72396a76eb9781af5c65d1dd49b86fdd(meta_buf_126);
fusedelementwise_c95229d232a4030bb1d1871c63e2a75083d8765a4d87ec6364ca43cd(meta_buf_127);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_128);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_129);
fusedelementwise_f350f7326a3486c4ec7d27a1ff47128b344d436387703253d443bf00(meta_buf_130);
depth2space_fb4d08ab9e4cdbc9170db5af72396a76eb9781af5c65d1dd49b86fdd(meta_buf_131);
fusedelementwise_73ae9dc6e89c264cb3a9e2e0169756234e73dd755aed5dabdc8bf5cd(meta_buf_132);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_133);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_134);
fusedelementwise_3efa18fc173586fd639e5aa6537cfce86d2d5ec645d2c05bf6392518(meta_buf_135);

}

