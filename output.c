
//------------- IRBase Translate -------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function & Class Declare
struct Test;

long rand();
void Test__Test(long This);
void Test__printme(long This);
long str_le(long str1, long str2);
long str_eql(long str1, long str2);
long substring(long str, long l, long r);
long ord(long pos, long str);
long parseInt(long x);
long strlength(long idx);
long size(long x);
long toMoStr(char *str);
long str_add(long a, long b);
long getInt();
void print(long null);
void println(long null);
void __lib_printInt(long null);
long __lib_malloc(long null);
long toString(long null);
int main();
long getString();
void __lib_printlnInt(long null);

//Grobal Variable
long reed_;
long n_;

//Inside Function
long str_le(long str1, long str2){
    if(strcmp((char*)str1, (char*)str2) < 0){
        return 1;
    }
    return 0;
}
long str_eql(long str1, long str2){
    int l1 = (int) strlength(str1);
    int l2 = (int) strlength(str2);
    if(l1 != l2) return 0;

    for(int i = 0; i < l1; i ++){
        if(((char*)str1)[i] != ((char*)str2)[i]){
            return 0;
        }
    }
    return 1;
}
long substring(long str, long l, long r){
    int ns = r - l + 1;
    unsigned char *ret = (unsigned char*)malloc(ns + sizeof(int) + 1);
    *((int*)ret) = ns;
    ret += sizeof(int);
    int idx = 0;
    for(int i = l; i <= r; i ++){
        ((char*)ret)[idx++] = ((char*)str)[i];
    }
    ((char*)ret)[idx] = '\0';
    return (long)ret;
}
long ord(long str, long pos){
    char* ret = (char*)str + pos;
    return (long)*ret;
}
long parseInt(long x){
    int s = (int) strlength(x);
    char* ret = (char*)x;
    int res = 0;
    for(int i = 0; i < s; i ++){
        if(ret[i]>='0' && ret[i] <= '9'){
            res = res * 10 + ret[i] - '0';
        }else{
            break;
        }
    };
    return res;
}
long strlength(long idx){
    int res = *((int *)(idx - sizeof(int)));
    return (long)res;
}
long getInt(){
    int tmp = 0;
    scanf("%d", &tmp);
    return (long)tmp;
}
long getString(){
    int size = 0;
    unsigned char* tmp = (unsigned char*)malloc(2000 + sizeof(int));
    unsigned char* bak = tmp;
    tmp += sizeof(int);
    scanf("%s", tmp);
    size = strlen((char*)tmp);
    *((int*) bak) = size;
    return (long)(bak + sizeof(int));
}
long size(long x){
    long s = *((long*)(x - sizeof(long)));
    return s;
}
long toMoStr(char *str) {
    int len = strlen(str);
    unsigned char* ret = (unsigned char *) malloc(len + sizeof(int) + 1);

    *((int *)ret) = len;
    ret += sizeof(int);

    strcpy((char *)ret, str);
    return (long)ret;
}
long str_add(long a, long b) {
    int l1 = *((int *)(a - sizeof(int)));
    int l2 = *((int *)(b - sizeof(int)));

    int l = l1 + l2;

    unsigned char* ret = (unsigned char*) malloc(l + sizeof(int) + 1);
    *((int *)ret) = l;
    ret += sizeof(int);


    for (int i =0; i < l1; i++)
        ((char*)ret)[i] = ((char *)a)[i];

    for (int i = 0; i < l2; i++)
        ((char*)ret)[i+l1] = ((char *)b)[i];

    ((char*)ret)[l] = 0;

    return (long)ret;
}
void __lib_printlnInt(long x) {
    printf("%ld\n", x);
}

void __lib_printInt(long x) {
    printf("%ld", x);
}

long __lib_malloc(long x) {
    return (long) malloc(x);
}

void println(long x) {
    puts((char *)x);
}void print(long x){
    printf("%s", (char*)x);
}
long toString(long x) {
    unsigned char *ret = (unsigned char*)malloc(12 + sizeof(int));
    ret += sizeof(int);
    unsigned char *p = ret;

    if (x < 0) {
        *p++ = '-';
        x = -x;
    }

    if (x == 0)
        *p++ = '0';

    unsigned char *begin = p;
    while (x) {
        int next = x / 10;
        *p++ = '0' + x - next * 10;
        x = next;
    }
    *p = 0;
    *(((int *)ret) - 1) = p - ret;

    p--;
    while (begin <= p) {
        char t = *begin;
        *begin = *p;
        *p = t;
        begin++;
        p--;
    }

    return (long)ret;
}

//Class Body
struct Test{
long array_;
};
long rand(){
//Define Local Variable
long const_0_;
//Function Body
reed_ = (((reed_) + ((reed_) << (5))) + (1727317));
if((((reed_) % (1772371)) < (1000))) goto AsmLabel0; else goto AsmLabel2;;
AsmLabel0:;
reed_ = (((reed_) ^ ((reed_) + (818277))) | ((reed_) - (18217)));
AsmLabel2:;
const_0_ = ((1) << (30));
return ((reed_) & ~((const_0_) >> (2)));
}
void Test__Test(long This){
//Define Local Variable
long This_1_ = This;
long __tmp0_2_;
long __tmp2_3_;
long __tmp1_4_;
long i_5_;
long j_6_;
long __tmp4_7_;
long __tmp3_8_;
long s_9_;
long __tmp5_10_;
long sum_11_;
long __tmp6_12_;
long __tmp7_13_;
//Function Body
__tmp1_4_ = (n_);
__tmp0_2_ = __lib_malloc((((__tmp1_4_) * (8)) + (8)));
*((long*)(__tmp0_2_)) = (__tmp1_4_);
__tmp0_2_ = ((__tmp0_2_) + (8));
*((long*)((This_1_) + (0))) = (__tmp0_2_);
i_5_ = (0);
AsmLabel7:;
if(((i_5_) < (n_))) goto AsmLabel8; else goto AsmLabel10;;
AsmLabel8:;
sum_11_ = (0);
__tmp4_7_ = ((((i_5_) + ((i_5_) * (i_5_))) + (3)) | (13));
__tmp3_8_ = __lib_malloc((((__tmp4_7_) * (8)) + (8)));
*((long*)(__tmp3_8_)) = (__tmp4_7_);
__tmp3_8_ = ((__tmp3_8_) + (8));
*((long*)((*(long *)((This_1_) + (0))) + ((j_6_) * (8)))) = (__tmp3_8_);
s_9_ = (0);
j_6_ = (0);
AsmLabel14:;
if(((j_6_) < ((((i_5_) + ((i_5_) * (i_5_))) + (2)) | (13)))) goto AsmLabel15; else goto AsmLabel17;;
AsmLabel15:;
__tmp6_12_ = rand();
__tmp7_13_ = toString((__tmp6_12_));
*((long*)((*(long *)((*(long *)((This_1_) + (0))) + ((i_5_) * (8)))) + ((j_6_) * (8)))) = (__tmp7_13_);
AsmLabel16:;
j_6_ = ((j_6_) + (1));
goto AsmLabel14;
AsmLabel17:;
AsmLabel9:;
i_5_ = ((i_5_) + (1));
goto AsmLabel7;
AsmLabel10:;
}
void Test__printme(long This){
//Define Local Variable
long This_14_ = This;
long i_15_;
long j_16_;
long k_17_;
long r_18_;
long __tmp10_19_;
long __tmp11_20_;
long __tmp14_21_;
long __tmp15_22_;
long __tmp12_23_;
long __tmp13_24_;
long l_25_;
long __tmp8_26_;
long __tmp9_27_;
long t_28_;
long __tmp16_29_;
long __tmp17_30_;
//Function Body
i_15_ = (0);
AsmLabel18:;
if(((i_15_) < (n_))) goto AsmLabel19; else goto AsmLabel21;;
AsmLabel19:;
j_16_ = (0);
AsmLabel22:;
if((((j_16_) - ((i_15_) * (i_15_))) < ((i_15_) + (3)))) goto AsmLabel23; else goto AsmLabel25;;
AsmLabel23:;
println((*(long *)((*(long *)((*(long *)((This_14_) + (0))) + ((i_15_) * (8)))) + ((j_16_) * (8)))));
;
__tmp8_26_ = parseInt((*(long *)((*(long *)((*(long *)((This_14_) + (0))) + ((i_15_) * (8)))) + ((j_16_) * (8)))));
__tmp9_27_ = toString((__tmp8_26_));
println(str_add((toMoStr("toInt: ")), (__tmp9_27_)));
;
__tmp10_19_ = strlength((*(long *)((*(long *)((*(long *)((This_14_) + (0))) + ((i_15_) * (8)))) + ((j_16_) * (8)))));
__tmp11_20_ = rand();
l_25_ = ((__tmp11_20_) % (__tmp10_19_));
__tmp12_23_ = strlength((*(long *)((*(long *)((*(long *)((This_14_) + (0))) + ((i_15_) * (8)))) + ((j_16_) * (8)))));
__tmp13_24_ = rand();
r_18_ = ((__tmp13_24_) % (__tmp12_23_));
if(((l_25_) > (r_18_))) goto AsmLabel26; else goto AsmLabel28;;
AsmLabel26:;
t_28_ = (l_25_);
l_25_ = (r_18_);
r_18_ = (t_28_);
AsmLabel28:;
__tmp14_21_ = substring((*(long *)((*(long *)((*(long *)((This_14_) + (0))) + ((i_15_) * (8)))) + ((j_16_) * (8)))), (l_25_), (r_18_));
println(str_add((toMoStr("substr: ")), (__tmp14_21_)));
;
k_17_ = (0);
AsmLabel30:;
__tmp15_22_ = strlength((*(long *)((*(long *)((*(long *)((This_14_) + (0))) + ((i_15_) * (8)))) + ((j_16_) * (8)))));
if((((k_17_) + (1)) < ((__tmp15_22_) + (1)))) goto AsmLabel31; else goto AsmLabel33;;
AsmLabel31:;
__tmp16_29_ = ord((*(long *)((*(long *)((*(long *)((This_14_) + (0))) + ((i_15_) * (8)))) + ((j_16_) * (8)))), (k_17_));
__tmp17_30_ = toString((__tmp16_29_));
print(str_add((__tmp17_30_), (toMoStr(" "))));
;
AsmLabel32:;
k_17_ = ((k_17_) + (2));
goto AsmLabel30;
AsmLabel33:;
println((toMoStr("")));
;
AsmLabel24:;
j_16_ = ((j_16_) + (1));
goto AsmLabel22;
AsmLabel25:;
AsmLabel20:;
i_15_ = ((i_15_) + (1));
goto AsmLabel18;
AsmLabel21:;
}
int main(){
//Grobal Variable Initialize
reed_ = (12883127);
//Define Local Variable
long a_31_;
long __tmp21_32_;
long __tmp22_33_;
long __tmp20_34_;
long __tmp23_35_;
long __tmp24_36_;
long __tmp18_37_;
long __tmp19_38_;
long a_39_;
long a_40_;
long a_41_;
long a_42_;
//Function Body
__tmp18_37_ = getInt();
n_ = (__tmp18_37_);
println((toMoStr("BY Kipsora")));
;
__tmp19_38_ = __lib_malloc((8));
Test__Test((__tmp19_38_));
;
a_31_ = (__tmp19_38_);
Test__printme((a_31_));
;
__tmp21_32_ = (3);
__tmp20_34_ = __lib_malloc((((__tmp21_32_) * (8)) + (8)));
*((long*)(__tmp20_34_)) = (__tmp21_32_);
__tmp20_34_ = ((__tmp20_34_) + (8));
__tmp22_33_ = (0);
goto AsmLabel34;
AsmLabel35:;
__tmp23_35_ = (3);
*((long*)((__tmp20_34_) + ((__tmp22_33_) * (8)))) = __lib_malloc((((__tmp23_35_) * (8)) + (8)));
*((long*)(*(long *)((__tmp20_34_) + ((__tmp22_33_) * (8))))) = (__tmp23_35_);
*((long*)((__tmp20_34_) + ((__tmp22_33_) * (8)))) = ((*(long *)((__tmp20_34_) + ((__tmp22_33_) * (8)))) + (8));
__tmp22_33_ = ((__tmp22_33_) + (1));
AsmLabel34:;
if(((__tmp22_33_) < (__tmp21_32_))) goto AsmLabel35; else goto AsmLabel36;;
AsmLabel36:;
*((long*)((a_31_) + (0))) = (__tmp20_34_);
if((1)) goto AsmLabel40; else goto AsmLabel41;;
AsmLabel40:;
goto AsmLabel42;
AsmLabel41:;
AsmLabel42:;
AsmLabel43:;
if((1)) goto AsmLabel44; else goto AsmLabel46;;
AsmLabel44:;
AsmLabel45:;
goto AsmLabel43;
AsmLabel46:;
AsmLabel47:;
if((1)) goto AsmLabel48; else goto AsmLabel49;;
AsmLabel48:;
goto AsmLabel47;
AsmLabel49:;
}

//------------- IRBase Traverse End -------------

