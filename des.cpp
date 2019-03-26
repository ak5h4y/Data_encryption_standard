#include<iostream>
#include<string>
#include<vector>
using namespace std;
int pc1[56]={57,   49,    41,   33,    25,    17,    9,
               1,   58,    50,   42,    34,    26,   18,
              10,    2,    59,   51,    43,    35,   27,
              19,   11,     3,   60,    52,    44,   36,
              63,   55,    47,   39,    31,    23,   15,
               7,   62,    54,   46,    38,    30,   22,
              14,   6,    61,   53,    45,    37,   29,
              21,   13,     5,   28,    20,    12,    4};
int pc2[48]={14 ,   17,   11,    24,     1,    5,
              3,    28,   15,     6,    21,   10,
             23,    19,   12,     4,    26,    8,
             16,     7,   27,    20,    13,    2,
             41,    52,   31,    37,    47,   55,
             30,    40,   51,    45,    33,   48,
             44,    49,   39,    56,    34,  53,
             46,    42,   50,    36,    29,   32,};
      //initial permutation of message
int ip[64]={58,    50,   42,    34,    26,   18,    10,    2,
            60,    52,   44,    36,    28,   20,    12,    4,
            62,    54,   46,    38,    30,   22,    14,    6,
            64,    56,   48,    40,    32,   24,    16,    8,
            57,    49,   41,    33,    25,   17,     9,    1,
            59,    51,   43,    35,    27,   19,    11,    3,
            61,    53,   45,    37,    29,   21,    13,    5,
            63,    55,   47,    39,    31,   23,    15,    7};
int E[48]={32,     1,    2,     3,     4,    5,
            4,     5,    6,     7,     8,    9,
            8,     9,   10,    11,    12,   13,
           12,    13,   14,    15,    16,   17,
           16,    17,   18,    19,    20,  21,
           20,    21,   22,    23,    24,   25,
           24,    25,   26,    27,    28,  29,
           28,    29,   30,    31,    32,   1};
           //S-blocks for converting 6 bits to 4 bits
int  s1[4][16]={{14,  4,  13,  1,   2, 15,  11,  8 ,  3, 10,   6, 12,   5,  9,   0,  7},
      {0, 15,   7,  4,  14,  2,  13,  1,  10,  6,  12, 11,   9 , 5 ,  3,  8},
      {4,  1,  14,  8 , 13 , 6 ,  2 ,11,  15, 12,   9,  7 ,  3, 10 ,  5 , 0},
     {15, 12,   8,  2 ,  4,  9,   1,  7,   5, 11 ,  3, 14,  10,  0,   6, 13}};
int  s2[4][16]={{15,  1,   8, 14 ,  6, 11,   3,  4,   9,  7,   2, 13,  12,  0 ,  5 ,10},
        {3, 13,   4,  7,  15,  2,   8, 14,  12,  0,   1, 10,   6,  9,  11,  5},
      {0, 14,   7, 11,  10,  4,  13,  1,   5,  8,  12,  6,   9,  3,   2, 15},
     {13,  8,  10,  1,   3, 15,   4,  2,  11,  6,   7, 12,   0,  5,  14,  9}};
int  s3[4][16]={{10,  0,   9, 14,   6,  3,  15,  5,   1, 13,  12,  7,  11,  4,   2,  8},
     {13,  7,   0,  9,   3,  4,   6, 10,   2,  8,   5, 14,  12, 11,  15,  1},
     {13,  6,   4,  9,   8, 15 ,  3 , 0,  11,  1,   2, 12,   5, 10 , 14,  7},
      {1, 10,  13,  0,   6,  9,   8,  7,   4, 15,  14,  3,  11,  5,   2, 12}};
int s4[4][16]={{7, 13,  14,  3,   0,  6,   9, 10,   1,  2,   8,  5,  11, 12,   4, 15},
     {13,  8,  11,  5,   6, 15,   0,  3,   4,  7,   2, 12,   1, 10,  14,  9},
     {10,  6,   9,  0,  12, 11 ,  7, 13,  15,  1,   3, 14,   5,  2,   8,  4},
      {3 ,15,   0,  6,  10,  1,  13,  8,   9,  4,   5, 11,  12,  7 ,  2, 14}};
int s5[4][16]={{2, 12,   4,  1,   7, 10,  11,  6 ,  8,  5,   3, 15,  13,  0,  14,  9},
     {14, 11,   2, 12,   4,  7,  13,  1,   5,  0,  15, 10,   3,  9,   8,  6},
      {4,  2,   1, 11,  10, 13,   7,  8,  15,  9,  12,  5,   6,  3 ,  0, 14},
     {11,  8,  12,  7,   1, 14,   2, 13,   6, 15,   0,  9,  10,  4,   5,  3}};
int s6[4][16]={{12,  1,  10, 15,   9,  2,   6,  8,   0, 13,   3,  4,  14,  7,   5, 11},
     {10, 15,   4,  2,   7, 12,   9,  5,   6,  1,  13, 14,   0, 11,   3,  8},
      {9, 14,  15,  5,   2,  8,  12,  3,   7,  0,   4, 10,   1, 13,  11,  6},
      {4,  3,   2, 12,   9,  5,  15, 10,  11, 14,   1,  7,   6,  0,   8, 13}};
int s7[4][16]={{4, 11 ,  2, 14,  15,  0,   8 ,13,   3, 12 ,  9,  7 ,  5 ,10 ,  6,  1},
     {13,  0,  11,  7,   4,  9,   1, 10,  14,  3,   5, 12,   2, 15,   8,  6},
      {1,  4,  11, 13,  12,  3,   7, 14,  10, 15,   6,  8,   0,  5 ,  9,  2},
      {6, 11,  13,  8,   1,  4,  10,  7,   9,  5,   0, 15,  14,  2,   3, 12}};
int s8[4][16]={{13,  2,   8,  4,   6, 15,  11,  1,  10,  9,   3, 14,   5,  0,  12,  7},
      {1, 15,  13,  8,  10,  3,   7,  4,  12,  5,   6, 11,   0, 14 ,  9,  2},
      {7, 11,   4,  1,   9, 12,  14,  2,   0,  6,  10, 13,  15,  3,   5,  8},
      {2,  1,  14,  7,   4, 10,   8, 13,  15, 12,   9,  0,   3,  5,   6, 11}};
        //final permutation to get fun_final
int P[32]={16,   7,  20,  21,
          29,  12,  28,  17,
          1,  15,  23,  26,
          5,  18,  31,  10,
          2,   8,  24,  14,
         32,  27,   3,   9,
         19,  13,  30,   6,
         22,  11,   4,  25};
         //final permutation
int IPinverse[64]={40,     8,   48,    16,    56,   24,    64,   32,
            39,     7,   47,    15,    55,   23,    63,   31,
            38,     6,   46,    14,    54,   22,    62,   30,
            37,     5,   45,    13,    53,   21,    61,   29,
            36 ,    4,   44,    12,    52,   20,    60,   28,
            35 ,    3,   43,    11,    51,   19,    59,   27,
            34,     2,   42,   10,    50,   18,    58,   26,
            33,     1,   41,     9,    49,   17,    57,   25};
int shift[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
void shift_fun(int *arr,int size,int sh){
  for(int i=0;i<sh;i++){
    int x=arr[0],j;
    for(j=0;j<size-1;j++){
      arr[j]=arr[j+1];
    }
    arr[j]=x;
  }return;
}
void key_gen(int* cd,int* cdin,int* kout,int it){
  for(int i=0;i<56;i++){
    cd[i]=cdin[i];
  }
  shift_fun(cd,28,shift[it]);
  int *r=&cd[28];
  shift_fun(r,28,shift[it]);
  for(int i=0;i<48;i++){
    kout[i]=cd[pc2[i]-1];
  }
}
int xor_op(int a,int b){
  if(a==b){return 0;}
  return 1;
}
void mess_gen(int* min,int* mout,int* k){
  int lin[32],rin[32],i,j;
  for(i=0;i<32;i++){
    lin[i]=min[i];rin[i]=min[i+32];
  }
  for(i=0;i<32;i++){
    mout[i]=rin[i];
  }

//conversion of rin from 32 bits to 48 bits
  int erin[48];
  for(i=0;i<48;i++){
    erin[i]=rin[E[i]-1];
  }

//taking xor_op operaton between key and erin
  int pre_fun[48];
  for(i=0;i<48;i++){
    pre_fun[i]=xor_op(k[i],erin[i]);
  }

//designing f using blocks named S-blocks
  int f[32];
  for(i=0;i<8;i++){
      int x=pre_fun[i*6],y=pre_fun[i*6+5],z;  //here z decides row for correspoding S-block
      if(x==0){
        if(y==0){z=0;}
        else{z=1;}
      }
      else{
        if(y==0){z=2;}
        else{z=3;}
      }
      int l=pre_fun[i*6+1],m=pre_fun[i*6+2],n=pre_fun[i*6+3],o=pre_fun[i*6+4],p;         //here p decides column for correspoding S-block
      if(l==0){
        if(m==0){
          if(n==0){
            if(o==0){p=0;}
            else{p=1;}
          }
          else{
            if(o==0){p=2;}
            else{p=3;}
          }
        }
        else{
          if(n==0){
            if(o==0){p=4;}
            else{p=5;}
          }
          else{
            if(o==0){p=6;}
            else{p=7;}
          }
        }
      }
      else{
        if(m==0){
          if(n==0){
            if(o==0){p=8;}
            else{p=9;}
          }
          else{
            if(o==0){p=10;}
            else{p=11;}
          }
        }
        else{
          if(n==0){
            if(o==0){p=12;}
            else{p=13;}
          }
          else{
            if(o==0){p=14;}
            else{p=15;}
          }
        }
      }
      int q;
      switch(i){
        case 0: q=s1[z][p];break;
        case 1: q=s2[z][p];break;
        case 2: q=s3[z][p];break;
        case 3: q=s4[z][p];break;
        case 4: q=s5[z][p];break;
        case 5: q=s6[z][p];break;
        case 6: q=s7[z][p];break;
        case 7: q=s8[z][p];break;
      }//q is an exact element(4 bits) to be replaced in place of 6 bits
      int w[4];
      for(j=0;j<4;j++){
        w[j]=q%2;
        q/=2;
      }int v=0;
      for(j=3;j>=0;j--){
        f[i*4+v]=w[j];v++;
      }
  }
  int fun_final[32];
  for(i=0;i<32;i++){
    fun_final[i]=f[P[i]-1];
  }
  for(i=0;i<32;i++){
    mout[i+32]=xor_op(fun_final[i],lin[i]);
  }
}
int main(){
  int i,j; //counters
//plaintext input
  string plain_text;cout<<"plain text:->";
  cin>>plain_text;

  //binary conversion of plain_text
  vector <int> M;int x;
  for(j=0;j<plain_text.size();j++){
    x=plain_text[j];
    int w[8];
    for(i=0;i<8;i++){
      w[i]=x%2;
      x/=2;
    }
    for(i=7;i>=0;i--){
      M.push_back(w[i]);
    }
  }

  //adding character "<" which specifies end of plain text
  x=60;
  int w[8];
  for(i=0;i<8;i++){
    w[i]=x%2;
    x/=2;
  }
  for(i=7;i>=0;i--){
    M.push_back(w[i]);
  }
  //managing plaintext size in multiple of 64 bits
  if(M.size()%64!=0){
    int x2=M.size()%64;x2=64-x2;
    for(i=0;i<x2;i++){
      M.push_back(0);
    }
  }
  //key input
  cout<<"write a key which should be of size 8 bit in decimal\n";cout<<"key:->";
  string key;
  cin>>key;
  //key binary conversion
  vector <int> K;int x1;
  for(j=0;j<key.size();j++){
    x1=key[j];
    int w[8];
    for(i=0;i<8;i++){
      w[i]=x1%2;
      x1/=2;
    }
    for(i=7;i>=0;i--){
      K.push_back(w[i]);
    }
  }
//Step 1: Create 16 subkeys, each of which is 48-bits long

  int  k0[56];
  for(i=0;i<56;i++){
    k0[i]=K[pc1[i]-1];
  }
  int c1d1[56],c2d2[56],c3d3[56],c4d4[56],c5d5[56],c6d6[56],c7d7[56],c8d8[56],c9d9[56],c10d10[56],c11d11[56],c12d12[56],c13d13[56],c14d14[56],c15d15[56],c16d16[56];
  int  k1[48],k2[48],k3[48],k4[48],k5[48],k6[48],k7[48],k8[48],k9[48],k10[48],k11[48],k12[48],k13[48],k14[48],k15[48],k16[48];


  key_gen(c1d1,k0,k1,0); //for k1
  key_gen(c2d2,c1d1,k2,1); //for k2
  key_gen(c3d3,c2d2,k3,2); //for k3
  key_gen(c4d4,c3d3,k4,3); //for k4
  key_gen(c5d5,c4d4,k5,4); //for k5
  key_gen(c6d6,c5d5,k6,5); //for k6
  key_gen(c7d7,c6d6,k7,6); //for k7
  key_gen(c8d8,c7d7,k8,7); //for k8
  key_gen(c9d9,c8d8,k9,8); //for k9
  key_gen(c10d10,c9d9,k10,9); //for k10
  key_gen(c11d11,c10d10,k11,10); //for k11
  key_gen(c12d12,c11d11,k12,11); //for k12
  key_gen(c13d13,c12d12,k13,12); //for k13
  key_gen(c14d14,c13d13,k14,13);  //for k14
  key_gen(c15d15,c14d14,k15,14); //for k15
  key_gen(c16d16,c15d15,k16,15); //for k16
//we have 16 keys from k1 to k16

//  Step 2: Encode each 64-bit block of data
  int plength=M.size()/64;
  int IP[M.size()];
  for(i=0;i<plength;i++){
    for(j=0;j<64;j++){
      IP[i*64+j]=M[i*64+(ip[j]-1)];
    }
  }int M_final[M.size()];
for(i=0;i<plength;i++){
  int *qq=&IP[i*64];
  int m1[64],m2[64],m3[64],m4[64],m5[64],m6[64],m7[64],m8[64],m9[64],m10[64],m11[64],m12[64],m13[64],m14[64],m15[64],m16[64];
  mess_gen(qq,m1,k1);
  mess_gen(m1,m2,k2);
  mess_gen(m2,m3,k3);
  mess_gen(m3,m4,k4);
  mess_gen(m4,m5,k5);
  mess_gen(m5,m6,k6);
  mess_gen(m6,m7,k7);
  mess_gen(m7,m8,k8);
  mess_gen(m8,m9,k9);
  mess_gen(m9,m10,k10);
  mess_gen(m10,m11,k11);
  mess_gen(m11,m12,k12);
  mess_gen(m12,m13,k13);
  mess_gen(m13,m14,k14);
  mess_gen(m14,m15,k15);
  mess_gen(m15,m16,k16);

  //reversing left and right part of m16
  int t;
  for(j=0;j<32;j++){
    t=m16[j];m16[j]=m16[j+32];m16[j+32]=t;
  }
  //finallization of encryption
  for(j=0;j<64;j++){
    M_final[i*64+j]=m16[IPinverse[j]-1];
  }
}
cout<<"encrypted message in binary:";
  for(i=0;i<M.size();i++){
    cout<<M_final[i];
  }
}
