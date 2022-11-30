#include<iostream>
#include <windows.h>
using namespace std;

#define maxsize 100

// typedef struct Trimat{
//     int val;
//     int i;
//     int j;
// }Trimat;

// int a[][3]={
//     {1,2,3},
//     {4,5,6}
// };

// int b[]={1,2,3,4};

void transpose(int A[][3],int B[][3]){
    //三元组的转置
    int p,q,row;
    //B是转换后的新矩阵
    // row
    // col
    B[0][0]=A[0][0];
    B[0][1]=A[0][2];
    B[0][2]=A[0][1];
    if(B[0][0]>0){
        //存在值,q是B的索引
        q=1;
        for(row=0;row<B[0][2];row++){
            //按行转置
            for(p=1;p<=B[0][0];p++){
                if(A[p][1]==row){
                    B[q][0]=A[p][0];
                    B[q][1]=A[p][2];
                    B[q][2]=A[p][1];
                    q++;
                }
            }
        }
    }

}

//建立,nums是稀疏矩阵，A是建立好的三元组
void translate(int nums[][maxsize],int m,int n,int A[][3]){
    int cnt=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(nums[i][j]!=0){
                A[cnt][0]=nums[i][j];
                A[cnt][1]=i;
                A[cnt][2]=j;
                cnt++;
            }
        }
    }
    A[0][0]=cnt-1;
    A[0][1]=m;
    A[0][2]=n;
    return ;
}

void display(int A[][3],int length){
    cout<<"Trimat"<<endl;
    for(int i=0;i<length+1;i++){
        for(int j=0;j<3;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    int nums[][100]={
        {15,0,0,22,0,-15},
        {0,11,3,0,0,0},
        {0,0,0,-6,0,0},
        {0,0,0,0,0,0},
        {91,0,0,0,0,0},
        {0,0,28,0,0,0}
    };
    int A[maxsize][3];
    translate(nums,6,6,A);
    display(A,A[0][0]);
    int B[maxsize][3];
    transpose(A,B);
    display(B,B[0][0]);

}
