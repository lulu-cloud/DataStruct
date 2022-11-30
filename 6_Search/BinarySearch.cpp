#include<iostream>
#include <windows.h>
#include<stack>
#include<queue>
using namespace std;


/**
 * @brief 
 * 二分查找，左闭右开的策略
 * 
 */

int BinarySearch1(int data[],int target,int len){
    int left=0;
    int right=len;
    while(left<right){
        int mid=left+(right-left)/2;
        //找到了
        if(data[mid]==target){
            return mid;
        }
        //查找的值在左边,区间右端缩减  
        else if(data[mid]>target){  
            right=mid;              //左闭右开，right取中mid，mid已经查找过
        }
        //查找的值在右边，区间左端缩减
        else {
            left=mid+1;         //左闭右开，left取中mid+1，mid已经查找过
        }
    }
    //查找失败。返回下标-1
    return -1;
}

/**双边闭区间*/
int BinarySearch2(int data[],int target,int len){
    int left=0;
    int right=len-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        //找到了
        if(data[mid]==target){
            return mid;
        }
        //查找的值在左边,区间右端缩减  
        else if(data[mid]>target){  
            right=mid-1;              //right取中mid-1，mid已经查找过
        }
        //查找的值在右边，区间左端缩减
        else {
            left=mid+1;         //left取中mid+1，mid已经查找过
        }
    }
    //查找失败。返回下标-1
    return -1;
}


//二分查找的递归写法，左闭右开区间
int Search_R(int data[],int target,int left,int right){
    if(right<=left){
        return -1;
    }
    int mid=left+(right-left)/2;
    if(data[mid]==target){
        return mid;
    }
    //在右边
    else if(data[mid]<target){
        return Search_R(data,target,mid+1,right);
    }
    else{
        return Search_R(data,target,left,mid);
    }
}

int main()
{
    int data[]={5,13,19,21,37,56,64,75,80,88,92};
    int target_1=5;
    int target_2=11;
    //左闭右开区间策略
    cout<<target_1<<"的下标为"<<BinarySearch1(data,target_1,sizeof(data)/sizeof(int))<<endl;
    cout<<target_2<<"的下标为"<<BinarySearch1(data,target_2,sizeof(data)/sizeof(int))<<endl;
    //左右闭区间策略
    cout<<target_1<<"的下标为"<<BinarySearch2(data,target_1,sizeof(data)/sizeof(int))<<endl;
    cout<<target_2<<"的下标为"<<BinarySearch2(data,target_2,sizeof(data)/sizeof(int))<<endl;
    //递归查找
    cout<<target_1<<"的下标为"<<Search_R(data,target_1,0,sizeof(data)/sizeof(int))<<endl;
    cout<<target_2<<"的下标为"<<Search_R(data,target_2,0,sizeof(data)/sizeof(int))<<endl;
}