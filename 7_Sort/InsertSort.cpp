#include<iostream>
#include <windows.h>
#include<stack>
#include<queue>
using namespace std;

//直接插入排序
void InsertSort(int data[],int len){
    //如果数组长度为0或者1，不需要排序    
    if(len==0||len==1){
        return ;
    }
    for(int i=1;i<len;i++){
        for(int j=0;j<i;j++){
            if(data[i]<data[j]){
                //找到一个可以插入的位置
                int temp=data[i];
                int k=i;
                //开始移动
                while(k>j){
                    data[k]=data[k-1];
                    k--;
                }
                data[j]=temp;
            }
        }
    }
}

int main()
{
    int data[]={1,6,3,8,0,2,5,4,7,9,-9,1,72,45};
    // sort(data);
    InsertSort(data,sizeof(data)/sizeof(int));
    for(int i=0;i<sizeof(data)/sizeof(int);i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}