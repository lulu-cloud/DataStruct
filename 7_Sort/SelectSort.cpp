#include<iostream>
#include <windows.h>
#include<stack>
#include<queue>
using namespace std;

void SimpleSelectSort(int data[],int len){
    for(int i=0;i<len-1;i++){
        int min=i;
        for(int j=i;j<len;j++){
            if(data[min]>data[j]){
                min=j;
            }
        }
        if(min!=i){
            int temp=data[min];
            data[min]=data[i];
            data[i]=temp;
        }
    }
}


//大顶堆
//data[low:high]
void Shift(int data[],int low,int high){
    int i=low;
    int j=2*low;
    int temp=data[i];
    while(j<=high){
        if(j<high&&data[j]<data[j+1]){
            //右孩子小，指向右孩子
            j++;
        }
        if(temp<data[j]){
            data[i]=data[j];
            i=j;
            j=2*j;
        }
        else{
            break;
        }
    }
    data[i]=temp;
}

void HeapSort(int data[],int len){
    //建立堆
    //如果数组长度为0或者1，不需要排序    
    
    if(len==0||len==1){
        return ;
    }

    //建立堆
    for(int i=len/2;i>=1;i--){
        Shift(data,i,len);
    }

    for(int i=len;i>=2;i--){
        //堆顶与最后元素交换，
        int temp=data[1];
        data[1]=data[i];
        data[i]=temp;
        Shift(data,1,i-1);
    }
}

int main()
{
    int data[]={-1,1,6,3,8,0,2,5,4,7,9,-9,1,72,45};
    // sort(data);
    HeapSort(data,sizeof(data)/sizeof(int)-1);
    for(int i=0;i<sizeof(data)/sizeof(int);i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}