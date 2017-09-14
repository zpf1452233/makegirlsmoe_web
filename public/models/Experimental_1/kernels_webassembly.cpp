
#include <stdlib.h>
#include <math.h>

float static_buffer[90452905];
float* dynamic_buffer = nullptr;

int meta_buf_0[] = {90452739,0,8827651,1,16384,166};
int meta_buf_1[] = {2752512,2719744,2768896,2736128,8827651,8794883,16384};
int meta_buf_2[] = {8794883,8762115,16384};
int meta_buf_3[] = {8762115,8827651,256,64,64,256};
int meta_buf_4[] = {8827651,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_5[] = {8467203,2785280,8778499,256,64,576};
int meta_buf_6[] = {2822208,2822272,2822144,2822336,8778499,8811267,64,64,64,256};
int meta_buf_7[] = {8811267,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_8[] = {8467203,2822400,8680195,256,64,576};
int meta_buf_9[] = {2859264,2859328,2859456,2859392,8762115,8680195,8696579,256,64,256,64,256};
int meta_buf_10[] = {8696579,8680195,256,64,64,256};
int meta_buf_11[] = {8680195,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_12[] = {8467203,2859520,8778499,256,64,576};
int meta_buf_13[] = {2896448,2896384,2896576,2896512,8778499,8860419,64,64,64,256};
int meta_buf_14[] = {8860419,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_15[] = {8467203,2896640,8876803,256,64,576};
int meta_buf_16[] = {2933632,2933568,2933504,2933696,8876803,8696579,8811267,64,256,256,64,256};
int meta_buf_17[] = {8811267,8778499,256,64,64,256};
int meta_buf_18[] = {8778499,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_19[] = {8467203,2933760,8712963,256,64,576};
int meta_buf_20[] = {2970752,2970816,2970624,2970688,8712963,8778499,64,64,64,256};
int meta_buf_21[] = {8778499,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_22[] = {8467203,2970880,8778499,256,64,576};
int meta_buf_23[] = {3007808,3007936,3007744,3007872,8778499,8811267,8827651,64,256,256,64,256};
int meta_buf_24[] = {8827651,8778499,256,64,64,256};
int meta_buf_25[] = {8778499,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_26[] = {8467203,3008000,8729347,256,64,576};
int meta_buf_27[] = {3044864,3044992,3044928,3045056,8729347,8712963,64,64,64,256};
int meta_buf_28[] = {8712963,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_29[] = {8467203,3045120,8876803,256,64,576};
int meta_buf_30[] = {3082176,3081984,3082048,3082112,8876803,8827651,8729347,64,256,256,64,256};
int meta_buf_31[] = {8729347,8778499,256,64,64,256};
int meta_buf_32[] = {8778499,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_33[] = {8467203,3082240,8745731,256,64,576};
int meta_buf_34[] = {3119168,3119296,3119104,3119232,8745731,8712963,64,64,64,256};
int meta_buf_35[] = {8712963,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_36[] = {8467203,3119360,8696579,256,64,576};
int meta_buf_37[] = {3156416,3156352,3156224,3156288,8729347,8696579,8778499,256,64,256,64,256};
int meta_buf_38[] = {8778499,8794883,256,64,64,256};
int meta_buf_39[] = {8794883,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_40[] = {8467203,3156480,8680195,256,64,576};
int meta_buf_41[] = {3193408,3193472,3193536,3193344,8680195,8696579,64,64,64,256};
int meta_buf_42[] = {8696579,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_43[] = {8467203,3193600,8729347,256,64,576};
int meta_buf_44[] = {3230528,3230656,3230592,3230464,8778499,8729347,8794883,256,64,256,64,256};
int meta_buf_45[] = {8794883,8827651,256,64,64,256};
int meta_buf_46[] = {8827651,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_47[] = {8467203,3230720,8860419,256,64,576};
int meta_buf_48[] = {3267648,3267776,3267584,3267712,8860419,8876803,64,64,64,256};
int meta_buf_49[] = {8876803,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_50[] = {8467203,3267840,8778499,256,64,576};
int meta_buf_51[] = {3304704,3304768,3304832,3304896,8778499,8794883,8811267,64,256,256,64,256};
int meta_buf_52[] = {8811267,8909571,256,64,64,256};
int meta_buf_53[] = {8909571,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_54[] = {8467203,3304960,8893187,256,64,576};
int meta_buf_55[] = {3341824,3341952,3341888,3342016,8893187,8909571,64,64,64,256};
int meta_buf_56[] = {8909571,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_57[] = {8467203,3342080,8893187,256,64,576};
int meta_buf_58[] = {3379136,3378944,3379008,3379072,8893187,8811267,8925955,64,256,256,64,256};
int meta_buf_59[] = {8925955,8893187,256,64,64,256};
int meta_buf_60[] = {8893187,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_61[] = {8467203,3379200,8893187,256,64,576};
int meta_buf_62[] = {3416192,3416064,3416256,3416128,8893187,8876803,64,64,64,256};
int meta_buf_63[] = {8876803,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_64[] = {8467203,3416320,8909571,256,64,576};
int meta_buf_65[] = {3453184,3453248,3453376,3453312,8909571,8925955,8893187,64,256,256,64,256};
int meta_buf_66[] = {8893187,8909571,256,64,64,256};
int meta_buf_67[] = {8909571,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_68[] = {8467203,3453440,8909571,256,64,576};
int meta_buf_69[] = {3490496,3490304,3490368,3490432,8909571,8925955,64,64,64,256};
int meta_buf_70[] = {8925955,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_71[] = {8467203,3490560,8876803,256,64,576};
int meta_buf_72[] = {3527424,3527552,3527616,3527488,8893187,8876803,8909571,256,64,256,64,256};
int meta_buf_73[] = {8909571,8893187,256,64,64,256};
int meta_buf_74[] = {8893187,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_75[] = {8467203,3527680,8893187,256,64,576};
int meta_buf_76[] = {3564608,3564736,3564544,3564672,8893187,8876803,64,64,64,256};
int meta_buf_77[] = {8876803,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_78[] = {8467203,3564800,8794883,256,64,576};
int meta_buf_79[] = {3601664,3601728,3601792,3601856,8909571,8794883,8680195,256,64,256,64,256};
int meta_buf_80[] = {8680195,8696579,256,64,64,256};
int meta_buf_81[] = {8696579,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_82[] = {8467203,3601920,8778499,256,64,576};
int meta_buf_83[] = {3638784,3638848,3638912,3638976,8778499,8745731,64,64,64,256};
int meta_buf_84[] = {8745731,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_85[] = {8467203,3639040,8729347,256,64,576};
int meta_buf_86[] = {3676032,3675904,3675968,3676096,8729347,8680195,8712963,64,256,256,64,256};
int meta_buf_87[] = {8712963,8778499,256,64,64,256};
int meta_buf_88[] = {8778499,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_89[] = {8467203,3676160,8696579,256,64,576};
int meta_buf_90[] = {3713216,3713152,3713024,3713088,8696579,8811267,64,64,64,256};
int meta_buf_91[] = {8811267,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_92[] = {8467203,3713280,8876803,256,64,576};
int meta_buf_93[] = {3750272,3750336,3750208,3750144,8712963,8876803,8860419,256,64,256,64,256};
int meta_buf_94[] = {8860419,8876803,256,64,64,256};
int meta_buf_95[] = {8876803,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_96[] = {8467203,3750400,8844035,256,64,576};
int meta_buf_97[] = {3787264,3787456,3787328,3787392,8844035,8827651,64,64,64,256};
int meta_buf_98[] = {8827651,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_99[] = {8467203,3787520,8876803,256,64,576};
int meta_buf_100[] = {3824576,3824448,3824512,3824384,8876803,8860419,8844035,64,256,256,64,256};
int meta_buf_101[] = {8844035,8811267,256,64,64,256};
int meta_buf_102[] = {8811267,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_103[] = {8467203,3824640,8778499,256,64,576};
int meta_buf_104[] = {3861568,3861504,3861632,3861696,8778499,8712963,64,64,64,256};
int meta_buf_105[] = {8712963,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_106[] = {8467203,3861760,8696579,256,64,576};
int meta_buf_107[] = {3898752,3898816,3898688,3898624,8844035,8696579,8712963,256,64,256,64,256};
int meta_buf_108[] = {8712963,8729347,256,64,64,256};
int meta_buf_109[] = {8729347,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_110[] = {8467203,3898880,8778499,256,64,576};
int meta_buf_111[] = {3935872,3935936,3935808,3935744,8778499,8876803,64,64,64,256};
int meta_buf_112[] = {8876803,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_113[] = {8467203,3936000,8729347,256,64,576};
int meta_buf_114[] = {3972864,3973056,3972928,3972992,8712963,8729347,8778499,256,64,64,64,256};
int meta_buf_115[] = {8778499,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_116[] = {8467203,3973120,8794883,256,64,576};
int meta_buf_117[] = {4010048,4009984,4010112,4010176,8762115,8794883,8827651,256,64,64,64,256};
int meta_buf_118[] = {8827651,8467203,1,64,16,16,16,16,3,3,1,1,1,1,1,1};
int meta_buf_119[] = {8467203,4010240,8614659,256,256,576};
int meta_buf_120[] = {4157696,8614659,8680195,256,256,256,256};
int meta_buf_121[] = {8680195,8467203,2,1,256,64,16,32,16,32};
int meta_buf_122[] = {4158080,4157952,4158016,8467203,8614659,64,64,64,1024};
int meta_buf_123[] = {8614659,7877379,1,64,32,32,32,32,3,3,1,1,1,1,1,1};
int meta_buf_124[] = {7877379,4158144,8467203,1024,256,576};
int meta_buf_125[] = {4305600,8467203,8139523,256,256,256,1024};
int meta_buf_126[] = {8139523,7877379,2,1,256,64,32,64,32,64};
int meta_buf_127[] = {4305920,4305984,4305856,7877379,8467203,64,64,64,4096};
int meta_buf_128[] = {8467203,4469507,1,64,64,64,64,64,3,3,1,1,1,1,1,1};
int meta_buf_129[] = {4469507,4306048,6828803,4096,256,576};
int meta_buf_130[] = {4453504,6828803,7877379,256,256,256,4096};
int meta_buf_131[] = {7877379,6828803,2,1,256,64,64,128,64,128};
int meta_buf_132[] = {4453760,4453888,4453824,6828803,89404163,64,64,64,16384};
int meta_buf_133[] = {89404163,4469507,1,64,128,128,128,128,9,9,1,1,1,1,4,4};
int meta_buf_134[] = {4469507,4453952,89404163,16384,3,5184};
int meta_buf_135[] = {4469504,89404163,8680195,3,16384,3,16384};
int* meta_buffers[] = {meta_buf_0,meta_buf_1,meta_buf_2,meta_buf_3,meta_buf_4,meta_buf_5,meta_buf_6,meta_buf_7,meta_buf_8,meta_buf_9,meta_buf_10,meta_buf_11,meta_buf_12,meta_buf_13,meta_buf_14,meta_buf_15,meta_buf_16,meta_buf_17,meta_buf_18,meta_buf_19,meta_buf_20,meta_buf_21,meta_buf_22,meta_buf_23,meta_buf_24,meta_buf_25,meta_buf_26,meta_buf_27,meta_buf_28,meta_buf_29,meta_buf_30,meta_buf_31,meta_buf_32,meta_buf_33,meta_buf_34,meta_buf_35,meta_buf_36,meta_buf_37,meta_buf_38,meta_buf_39,meta_buf_40,meta_buf_41,meta_buf_42,meta_buf_43,meta_buf_44,meta_buf_45,meta_buf_46,meta_buf_47,meta_buf_48,meta_buf_49,meta_buf_50,meta_buf_51,meta_buf_52,meta_buf_53,meta_buf_54,meta_buf_55,meta_buf_56,meta_buf_57,meta_buf_58,meta_buf_59,meta_buf_60,meta_buf_61,meta_buf_62,meta_buf_63,meta_buf_64,meta_buf_65,meta_buf_66,meta_buf_67,meta_buf_68,meta_buf_69,meta_buf_70,meta_buf_71,meta_buf_72,meta_buf_73,meta_buf_74,meta_buf_75,meta_buf_76,meta_buf_77,meta_buf_78,meta_buf_79,meta_buf_80,meta_buf_81,meta_buf_82,meta_buf_83,meta_buf_84,meta_buf_85,meta_buf_86,meta_buf_87,meta_buf_88,meta_buf_89,meta_buf_90,meta_buf_91,meta_buf_92,meta_buf_93,meta_buf_94,meta_buf_95,meta_buf_96,meta_buf_97,meta_buf_98,meta_buf_99,meta_buf_100,meta_buf_101,meta_buf_102,meta_buf_103,meta_buf_104,meta_buf_105,meta_buf_106,meta_buf_107,meta_buf_108,meta_buf_109,meta_buf_110,meta_buf_111,meta_buf_112,meta_buf_113,meta_buf_114,meta_buf_115,meta_buf_116,meta_buf_117,meta_buf_118,meta_buf_119,meta_buf_120,meta_buf_121,meta_buf_122,meta_buf_123,meta_buf_124,meta_buf_125,meta_buf_126,meta_buf_127,meta_buf_128,meta_buf_129,meta_buf_130,meta_buf_131,meta_buf_132,meta_buf_133,meta_buf_134,meta_buf_135};

extern "C" void init() {
    //static_buffer = (float*)malloc(90452905 * sizeof(float));
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


void fusedelementwise_395848b8c7809be7e3578166af73679d2f49823cb66b3a4040726585(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int D0 = meta_buffer[6];
    int d0;
    for (d0 = 0; d0 < D0; d0 += 1) {
        const float v7 = v4[d0];
        const float v8 = v5[d0];
        float v9;
        {
            v9 = v8 * v7;
        }
        const float v10 = v1[d0];
        float v11;
        {
            v11 = v9 + v10;
        }
        const float v12 = v2[d0];
        float v13;
        {
            v13 = v11 + v12;
        }
        const float v14 = v3[d0];
        float v15;
        {
            v15 = v13 + v14;
        }
        float v16;
        {
            v16 = v15 > 0 ? v15 : 0;
        }
        v6[d0] = v16;
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


void transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    float * v2 = (static_buffer + meta_buffer[1]);
    const int v3 = meta_buffer[2];
    const int v4 = meta_buffer[3];
    const int D0 = meta_buffer[4];
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
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


void fusedelementwise_6177a2463a4717c9b9c902c46ae0c40c12dfc52be3d528b85d4e43af(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v10;
            }
            float v16;
            {
                v16 = v15 + v12;
            }
            float v17;
            {
                v17 = v16 + v9;
            }
            float v18;
            {
                v18 = v17 + v11;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_6a02c6cb2915d14666fd2c0a83876b9a9d5dec92d627af871231a70c(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v6[d0 + d1*v9];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v14;
            }
            float v18;
            {
                v18 = v17 + v13;
            }
            float v19;
            {
                v19 = v18 + v12;
            }
            float v20;
            {
                v20 = v19 + v11;
            }
            const float v21 = v5[d0*v8 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_9cbbc9bd350bd5bd8b9be82d74d28bba5584b94328ef070ea7917976(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v12;
            }
            float v16;
            {
                v16 = v15 + v11;
            }
            float v17;
            {
                v17 = v16 + v9;
            }
            float v18;
            {
                v18 = v17 + v10;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_02cde58bf601bbf164d56cbd01d26cc5db9539d6e24d2301261c3d87(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v5[d0 + d1*v8];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v11;
            }
            float v18;
            {
                v18 = v17 + v14;
            }
            float v19;
            {
                v19 = v18 + v12;
            }
            float v20;
            {
                v20 = v19 + v13;
            }
            const float v21 = v6[d0*v9 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_b216cfdd8f66257de25a69ce636ff50affc18eda2100c9aa0c911c38(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v9;
            }
            float v16;
            {
                v16 = v15 + v10;
            }
            float v17;
            {
                v17 = v16 + v12;
            }
            float v18;
            {
                v18 = v17 + v11;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_f21a927c18fa0bd89f485cdb75e3e5d62259363e06cd6c2e5feab764(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v5[d0 + d1*v8];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v14;
            }
            float v18;
            {
                v18 = v17 + v12;
            }
            float v19;
            {
                v19 = v18 + v11;
            }
            float v20;
            {
                v20 = v19 + v13;
            }
            const float v21 = v6[d0*v9 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_142103ceb134072dd41da9531ca331dac9098467b514144f72265aaa(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v11;
            }
            float v16;
            {
                v16 = v15 + v10;
            }
            float v17;
            {
                v17 = v16 + v9;
            }
            float v18;
            {
                v18 = v17 + v12;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_82ca90363a6b1fb0c2c1daec56eb03bb83ad942fadd23af68dc41316(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v5[d0 + d1*v8];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v13;
            }
            float v18;
            {
                v18 = v17 + v14;
            }
            float v19;
            {
                v19 = v18 + v12;
            }
            float v20;
            {
                v20 = v19 + v11;
            }
            const float v21 = v6[d0*v9 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_765756e61a6f81057738fa6aca11dca493316631eadd838da12d736f(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v9;
            }
            float v16;
            {
                v16 = v15 + v12;
            }
            float v17;
            {
                v17 = v16 + v11;
            }
            float v18;
            {
                v18 = v17 + v10;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_916418b94669e1cda727ef3accd1542ee730c69f2b7967c6ccf1b96e(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v6[d0 + d1*v9];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v14;
            }
            float v18;
            {
                v18 = v17 + v12;
            }
            float v19;
            {
                v19 = v18 + v13;
            }
            float v20;
            {
                v20 = v19 + v11;
            }
            const float v21 = v5[d0*v8 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_051e60f843bbbfede689ec262b3075fdca1607476979093ac1f8ec46(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v10;
            }
            float v16;
            {
                v16 = v15 + v11;
            }
            float v17;
            {
                v17 = v16 + v9;
            }
            float v18;
            {
                v18 = v17 + v12;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_23ecf6179b2005391e54caaa6e802df3399562bbdd182d1e22eb1583(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v6[d0 + d1*v9];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v11;
            }
            float v18;
            {
                v18 = v17 + v13;
            }
            float v19;
            {
                v19 = v18 + v14;
            }
            float v20;
            {
                v20 = v19 + v12;
            }
            const float v21 = v5[d0*v8 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_70a746fee3d0d73d4b0eccc748014573c18bad68075fd370f864c8a9(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v5[d0 + d1*v8];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v13;
            }
            float v18;
            {
                v18 = v17 + v14;
            }
            float v19;
            {
                v19 = v18 + v11;
            }
            float v20;
            {
                v20 = v19 + v12;
            }
            const float v21 = v6[d0*v9 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_fcee812311ba892fab97c60d0c20489771644f55bfaa168270a14a97(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v10;
            }
            float v16;
            {
                v16 = v15 + v12;
            }
            float v17;
            {
                v17 = v16 + v11;
            }
            float v18;
            {
                v18 = v17 + v9;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_91dfe919a8b8a10c9bc04c09f258304484ed83456698fb66fcec38e9(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v5[d0 + d1*v8];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v14;
            }
            float v18;
            {
                v18 = v17 + v11;
            }
            float v19;
            {
                v19 = v18 + v13;
            }
            float v20;
            {
                v20 = v19 + v12;
            }
            const float v21 = v6[d0*v9 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_b90722e6f9a174043c9a682567419aa9edf3b7e4eb50e4f1f7b2548d(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v9;
            }
            float v16;
            {
                v16 = v15 + v11;
            }
            float v17;
            {
                v17 = v16 + v12;
            }
            float v18;
            {
                v18 = v17 + v10;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_53f719882625f6da5abccb888ae770c20dd9b12dbe2aa62629d7db01(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v5[d0 + d1*v8];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v14;
            }
            float v18;
            {
                v18 = v17 + v13;
            }
            float v19;
            {
                v19 = v18 + v12;
            }
            float v20;
            {
                v20 = v19 + v11;
            }
            const float v21 = v6[d0*v9 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_7d4846b45e57eb6ba36862ea8b58cbba75121c50a717eff2e5bd08c6(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v11;
            }
            float v16;
            {
                v16 = v15 + v12;
            }
            float v17;
            {
                v17 = v16 + v10;
            }
            float v18;
            {
                v18 = v17 + v9;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_f777b2795fe2cbcc309329e63b9a7c5d9b911edc7f746fb8e953a1bc(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v6[d0 + d1*v9];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v14;
            }
            float v18;
            {
                v18 = v17 + v12;
            }
            float v19;
            {
                v19 = v18 + v11;
            }
            float v20;
            {
                v20 = v19 + v13;
            }
            const float v21 = v5[d0*v8 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_01212f4b7d769506340dd0332ddfd8ae63af19f2a51b01440982c153(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v12;
            }
            float v16;
            {
                v16 = v15 + v10;
            }
            float v17;
            {
                v17 = v16 + v9;
            }
            float v18;
            {
                v18 = v17 + v11;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_d3e0cca46f9dcc0f8dfb6ed8a65b504cc355ba4c55b1b9e2c2e62099(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v6[d0 + d1*v9];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v13;
            }
            float v18;
            {
                v18 = v17 + v14;
            }
            float v19;
            {
                v19 = v18 + v12;
            }
            float v20;
            {
                v20 = v19 + v11;
            }
            const float v21 = v5[d0*v8 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_4cbf199db6854e5783c726627ca3a9be5aaf16f8a9b4a390043d91c1(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v5[d0 + d1*v8];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v13;
            }
            float v18;
            {
                v18 = v17 + v11;
            }
            float v19;
            {
                v19 = v18 + v12;
            }
            float v20;
            {
                v20 = v19 + v14;
            }
            const float v21 = v6[d0*v9 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_620abb110fbed8d734dd98de2c2183c3094b1024e7f17a3b32cb053e(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v12;
            }
            float v16;
            {
                v16 = v15 + v10;
            }
            float v17;
            {
                v17 = v16 + v11;
            }
            float v18;
            {
                v18 = v17 + v9;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_086d9c236da1c61e45def0f65ce96f8f4fdbb5e4bc6ab7339b2a7109(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v6[d0 + d1*v9];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v11;
            }
            float v18;
            {
                v18 = v17 + v12;
            }
            float v19;
            {
                v19 = v18 + v13;
            }
            float v20;
            {
                v20 = v19 + v14;
            }
            const float v21 = v5[d0*v8 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            v7[d0*v10 + d1] = v22;
        }
    }
}


void fusedelementwise_1a6c448fe359db17e3b64a3ef36325fcf7902ef13a6e0dff7bee1c1e(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v11;
            }
            float v16;
            {
                v16 = v15 + v12;
            }
            float v17;
            {
                v17 = v16 + v9;
            }
            float v18;
            {
                v18 = v17 + v10;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_4e692a8d4784563340efe41df60bd3df722e5bd7303e416f6e22b4e2(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    float * v6 = (static_buffer + meta_buffer[5]);
    const int v7 = meta_buffer[6];
    const int v8 = meta_buffer[7];
    const int D0 = meta_buffer[8];
    const int D1 = meta_buffer[9];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v9 = v1[d0];
        const float v10 = v2[d0];
        const float v11 = v3[d0];
        const float v12 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v13 = v5[d0 + d1*v7];
            float v14;
            {
                v14 = v13;
            }
            float v15;
            {
                v15 = v14 * v9;
            }
            float v16;
            {
                v16 = v15 + v10;
            }
            float v17;
            {
                v17 = v16 + v11;
            }
            float v18;
            {
                v18 = v17 + v12;
            }
            float v19;
            {
                v19 = v18 > 0 ? v18 : 0;
            }
            float v20;
            {
                v20 = v19;
            }
            v6[d0 + d1*v8] = v20;
        }
    }
}


void fusedelementwise_091201d734a62479030e84fb7a73ba3b592880267c0a5e4fc214cb55(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v6[d0 + d1*v9];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v14;
            }
            float v18;
            {
                v18 = v17 + v12;
            }
            float v19;
            {
                v19 = v18 + v13;
            }
            float v20;
            {
                v20 = v19 + v11;
            }
            const float v21 = v5[d0*v8 + d1];
            float v22;
            {
                v22 = v20 + v21;
            }
            float v23;
            {
                v23 = v22;
            }
            v7[d0 + d1*v10] = v23;
        }
    }
}


void fusedelementwise_80e11104e1572cabb9aa36d6584b4843cdeb1b70467a7c2ca7b68786(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    const float * v5 = (static_buffer + meta_buffer[4]);
    const float * v6 = (static_buffer + meta_buffer[5]);
    float * v7 = (static_buffer + meta_buffer[6]);
    const int v8 = meta_buffer[7];
    const int v9 = meta_buffer[8];
    const int v10 = meta_buffer[9];
    const int D0 = meta_buffer[10];
    const int D1 = meta_buffer[11];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v11 = v1[d0];
        const float v12 = v2[d0];
        const float v13 = v3[d0];
        const float v14 = v4[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v15 = v6[d0 + d1*v9];
            float v16;
            {
                v16 = v15;
            }
            float v17;
            {
                v17 = v16 * v13;
            }
            float v18;
            {
                v18 = v17 + v14;
            }
            float v19;
            {
                v19 = v18 + v11;
            }
            float v20;
            {
                v20 = v19 + v12;
            }
            float v21;
            {
                v21 = v20 > 0 ? v20 : 0;
            }
            const float v22 = v5[d0*v8 + d1];
            float v23;
            {
                v23 = v21 + v22;
            }
            float v24;
            {
                v24 = v23;
            }
            v7[d0 + d1*v10] = v24;
        }
    }
}


void fusedelementwise_24b8a34bb72e8c951eb84d658a3def8f92d5d5626d9be984a0a08bdf(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7;
            }
            float v9;
            {
                v9 = v8 + v6;
            }
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


void fusedelementwise_873f0b1c451d62128c2bbe1dea7b7fa1ed781f244c05a2ac4a75dad0(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    float * v5 = (static_buffer + meta_buffer[4]);
    const int v6 = meta_buffer[5];
    const int v7 = meta_buffer[6];
    const int D0 = meta_buffer[7];
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v8 = v1[d0];
        const float v9 = v2[d0];
        const float v10 = v3[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v11 = v4[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            float v13;
            {
                v13 = v12 * v8;
            }
            float v14;
            {
                v14 = v13 + v10;
            }
            float v15;
            {
                v15 = v14 + v9;
            }
            float v16;
            {
                v16 = v15 > 0 ? v15 : 0;
            }
            float v17;
            {
                v17 = v16;
            }
            v5[d0 + d1*v7] = v17;
        }
    }
}


void fusedelementwise_1c8ec28459c1ac28890f13ccccca41d512b5d28f186a465b7861120e(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    float * v5 = (static_buffer + meta_buffer[4]);
    const int v6 = meta_buffer[5];
    const int v7 = meta_buffer[6];
    const int D0 = meta_buffer[7];
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v8 = v1[d0];
        const float v9 = v2[d0];
        const float v10 = v3[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v11 = v4[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            float v13;
            {
                v13 = v12 * v9;
            }
            float v14;
            {
                v14 = v13 + v8;
            }
            float v15;
            {
                v15 = v14 + v10;
            }
            float v16;
            {
                v16 = v15 > 0 ? v15 : 0;
            }
            float v17;
            {
                v17 = v16;
            }
            v5[d0 + d1*v7] = v17;
        }
    }
}


void fusedelementwise_4f2aa29948489d2c01c418a72a15484fc3d68a9e8af1f8a3504b4e31(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    const float * v4 = (static_buffer + meta_buffer[3]);
    float * v5 = (static_buffer + meta_buffer[4]);
    const int v6 = meta_buffer[5];
    const int v7 = meta_buffer[6];
    const int D0 = meta_buffer[7];
    const int D1 = meta_buffer[8];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v8 = v1[d0];
        const float v9 = v2[d0];
        const float v10 = v3[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v11 = v4[d0 + d1*v6];
            float v12;
            {
                v12 = v11;
            }
            float v13;
            {
                v13 = v12 * v9;
            }
            float v14;
            {
                v14 = v13 + v10;
            }
            float v15;
            {
                v15 = v14 + v8;
            }
            float v16;
            {
                v16 = v15 > 0 ? v15 : 0;
            }
            float v17;
            {
                v17 = v16;
            }
            v5[d0 + d1*v7] = v17;
        }
    }
}


void fusedelementwise_cea8f9810bcf9588942a7d0f6e1c023ad31dc8f4cfbb942fb0fa751a(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7;
            }
            float v9;
            {
                v9 = v8 + v6;
            }
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
fusedelementwise_395848b8c7809be7e3578166af73679d2f49823cb66b3a4040726585(meta_buf_1);
reshape_f6c88dc1fd9479f62d789912530e6a5c7c51c73de368540e8b8e1ceb(meta_buf_2);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_3);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_4);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_5);
fusedelementwise_6177a2463a4717c9b9c902c46ae0c40c12dfc52be3d528b85d4e43af(meta_buf_6);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_7);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_8);
fusedelementwise_6a02c6cb2915d14666fd2c0a83876b9a9d5dec92d627af871231a70c(meta_buf_9);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_10);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_11);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_12);
fusedelementwise_9cbbc9bd350bd5bd8b9be82d74d28bba5584b94328ef070ea7917976(meta_buf_13);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_14);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_15);
fusedelementwise_02cde58bf601bbf164d56cbd01d26cc5db9539d6e24d2301261c3d87(meta_buf_16);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_17);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_18);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_19);
fusedelementwise_b216cfdd8f66257de25a69ce636ff50affc18eda2100c9aa0c911c38(meta_buf_20);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_21);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_22);
fusedelementwise_f21a927c18fa0bd89f485cdb75e3e5d62259363e06cd6c2e5feab764(meta_buf_23);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_24);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_25);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_26);
fusedelementwise_142103ceb134072dd41da9531ca331dac9098467b514144f72265aaa(meta_buf_27);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_28);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_29);
fusedelementwise_82ca90363a6b1fb0c2c1daec56eb03bb83ad942fadd23af68dc41316(meta_buf_30);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_31);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_32);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_33);
fusedelementwise_765756e61a6f81057738fa6aca11dca493316631eadd838da12d736f(meta_buf_34);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_35);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_36);
fusedelementwise_916418b94669e1cda727ef3accd1542ee730c69f2b7967c6ccf1b96e(meta_buf_37);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_38);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_39);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_40);
fusedelementwise_051e60f843bbbfede689ec262b3075fdca1607476979093ac1f8ec46(meta_buf_41);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_42);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_43);
fusedelementwise_23ecf6179b2005391e54caaa6e802df3399562bbdd182d1e22eb1583(meta_buf_44);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_45);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_46);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_47);
fusedelementwise_765756e61a6f81057738fa6aca11dca493316631eadd838da12d736f(meta_buf_48);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_49);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_50);
fusedelementwise_70a746fee3d0d73d4b0eccc748014573c18bad68075fd370f864c8a9(meta_buf_51);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_52);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_53);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_54);
fusedelementwise_fcee812311ba892fab97c60d0c20489771644f55bfaa168270a14a97(meta_buf_55);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_56);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_57);
fusedelementwise_91dfe919a8b8a10c9bc04c09f258304484ed83456698fb66fcec38e9(meta_buf_58);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_59);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_60);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_61);
fusedelementwise_b90722e6f9a174043c9a682567419aa9edf3b7e4eb50e4f1f7b2548d(meta_buf_62);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_63);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_64);
fusedelementwise_53f719882625f6da5abccb888ae770c20dd9b12dbe2aa62629d7db01(meta_buf_65);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_66);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_67);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_68);
fusedelementwise_7d4846b45e57eb6ba36862ea8b58cbba75121c50a717eff2e5bd08c6(meta_buf_69);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_70);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_71);
fusedelementwise_f777b2795fe2cbcc309329e63b9a7c5d9b911edc7f746fb8e953a1bc(meta_buf_72);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_73);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_74);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_75);
fusedelementwise_01212f4b7d769506340dd0332ddfd8ae63af19f2a51b01440982c153(meta_buf_76);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_77);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_78);
fusedelementwise_d3e0cca46f9dcc0f8dfb6ed8a65b504cc355ba4c55b1b9e2c2e62099(meta_buf_79);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_80);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_81);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_82);
fusedelementwise_051e60f843bbbfede689ec262b3075fdca1607476979093ac1f8ec46(meta_buf_83);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_84);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_85);
fusedelementwise_4cbf199db6854e5783c726627ca3a9be5aaf16f8a9b4a390043d91c1(meta_buf_86);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_87);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_88);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_89);
fusedelementwise_620abb110fbed8d734dd98de2c2183c3094b1024e7f17a3b32cb053e(meta_buf_90);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_91);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_92);
fusedelementwise_086d9c236da1c61e45def0f65ce96f8f4fdbb5e4bc6ab7339b2a7109(meta_buf_93);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_94);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_95);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_96);
fusedelementwise_620abb110fbed8d734dd98de2c2183c3094b1024e7f17a3b32cb053e(meta_buf_97);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_98);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_99);
fusedelementwise_4cbf199db6854e5783c726627ca3a9be5aaf16f8a9b4a390043d91c1(meta_buf_100);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_101);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_102);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_103);
fusedelementwise_1a6c448fe359db17e3b64a3ef36325fcf7902ef13a6e0dff7bee1c1e(meta_buf_104);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_105);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_106);
fusedelementwise_086d9c236da1c61e45def0f65ce96f8f4fdbb5e4bc6ab7339b2a7109(meta_buf_107);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_108);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_109);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_110);
fusedelementwise_4e692a8d4784563340efe41df60bd3df722e5bd7303e416f6e22b4e2(meta_buf_111);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_112);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_113);
fusedelementwise_091201d734a62479030e84fb7a73ba3b592880267c0a5e4fc214cb55(meta_buf_114);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_115);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_116);
fusedelementwise_80e11104e1572cabb9aa36d6584b4843cdeb1b70467a7c2ca7b68786(meta_buf_117);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_118);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_119);
fusedelementwise_24b8a34bb72e8c951eb84d658a3def8f92d5d5626d9be984a0a08bdf(meta_buf_120);
depth2space_fb4d08ab9e4cdbc9170db5af72396a76eb9781af5c65d1dd49b86fdd(meta_buf_121);
fusedelementwise_873f0b1c451d62128c2bbe1dea7b7fa1ed781f244c05a2ac4a75dad0(meta_buf_122);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_123);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_124);
fusedelementwise_24b8a34bb72e8c951eb84d658a3def8f92d5d5626d9be984a0a08bdf(meta_buf_125);
depth2space_fb4d08ab9e4cdbc9170db5af72396a76eb9781af5c65d1dd49b86fdd(meta_buf_126);
fusedelementwise_1c8ec28459c1ac28890f13ccccca41d512b5d28f186a465b7861120e(meta_buf_127);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_128);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_129);
fusedelementwise_24b8a34bb72e8c951eb84d658a3def8f92d5d5626d9be984a0a08bdf(meta_buf_130);
depth2space_fb4d08ab9e4cdbc9170db5af72396a76eb9781af5c65d1dd49b86fdd(meta_buf_131);
fusedelementwise_4f2aa29948489d2c01c418a72a15484fc3d68a9e8af1f8a3504b4e31(meta_buf_132);
im2col_1dc147a294d043a7b2199b007777978656dfb88774a7a9bb20a1039c(meta_buf_133);
sgemm_49ee440e78a4467f5e364896610c9bdbdd5dbf08d70b98a210d579d8(meta_buf_134);
fusedelementwise_cea8f9810bcf9588942a7d0f6e1c023ad31dc8f4cfbb942fb0fa751a(meta_buf_135);

}

