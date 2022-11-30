#include<iostream>
#include <windows.h>
#include<stack>
#include<queue>
using namespace std;

//左右闭区间
void merge(int data[],int low,int mid,int high){
    int len=high-low+1;
    int* ans=new int[len];
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=high){
        if(data[i]<data[j]){
            ans[k]=data[i];
            k++;i++;
        }
        else{
            ans[k]=data[j];
            k++;j++;
        }
    }
    while(i<=mid){
        ans[k]=data[i];
        k++;i++;
    }
    while(j<=high){
        ans[k]=data[j];
        k++;j++;
    }

    for(int i=0;i<len;i++){
        data[low+i]=ans[i];
    }
}

void MergeSort(int data[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        MergeSort(data,low,mid);
        MergeSort(data,mid+1,high);
        merge(data,low,mid,high);
    }
}

int main()
{
    int data[]={1,6,3,8,0,2,5,4,7,9};
    MergeSort(data,0,sizeof(data)/sizeof(int)-1);
    for(int i=0;i<sizeof(data)/sizeof(int);i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}