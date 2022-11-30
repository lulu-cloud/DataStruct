#include<iostream>
#include <windows.h>
#include<stack>
#include<queue>
using namespace std;

void BubbleSort(int data[],int len){
    //如果数组长度为0或者1，不需要排序    
    if(len==0||len==1){
        return ;
    }
    bool flag=true;
    for(int i=0;i<len-1&&flag;i++){  
        flag=false;
        for(int j=i+1;j<len;j++){
            if(data[j]<data[i]){
                int temp=data[i];
                data[i]=data[j];
                data[j]=temp;
                flag=true;
            }
        }
    }
}

void QuickSort(int data[],int low,int high){
    if(low<high){
        int l=low,r=high;
        int temp=data[l];
        while(l<r){
            while(l<r&&data[r]>=temp) {r--;}
            if(l<r){
                data[l]=data[r];
                l++;
            }
            while(l<r&&data[l]<=temp) {l++;}
            if(l<r){
                data[r]=data[l];
                r--;
            }
        }
        data[l]=temp;
        QuickSort(data,low,l-1);
        QuickSort(data,l+1,high);
    }
}


int main()
{
    int data[]={1,6,3,8,0,2,5,4,7,9};
    BubbleSort(data,sizeof(data)/sizeof(int));
    for(int i=0;i<sizeof(data)/sizeof(int);i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;

    int data1[]={1,6,3,8,0,2,5,4,7,9};
    QuickSort(data1,0,sizeof(data1)/sizeof(int)-1);
    for(int i=0;i<sizeof(data1)/sizeof(int);i++){
        cout<<data1[i]<<" ";
    }
    cout<<endl;
}