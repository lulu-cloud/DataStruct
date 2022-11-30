#include<iostream>
#include <windows.h>
using namespace std;
//O(n^2)

void fun1(int n){
    int sum=0;
    //      (n+n-1+n-2+...+1)
    //      (1+n)*n/2
    //      O(n^2)
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum++;
        }
    }
    return ;
}

//O(sqrt(n))
void fun2(int n){
    int i=0,s=0;
    while(s<n){
        i++;
        s+=i;
    }
    return;
}

//  ???
void fun3(int n){
    int i=1;
    int s=0;
    while(s<n){
        i*=2;
        s+=i;
    }
    return ;
}


/**
 * @discription
 * 1、设m次结束
 * 2、列出大致方程
 *      2*2*...*2=n
 *      2^m=n
 * 3、写出m=f(n)的表达式
 *      m=log(n)
 * 
 * 4、取最大因子作为结果
 *      O(log(n))
 * 
 */

void display(int *p,int length){
    for(int i=0;i<length;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}

//new 关键字
int main()
{
    int size=5;
    int *p=new int[size];

    //赋值
    for(int i=0;i<size;i++){
        p[i]=i;
    }

    display(p,size);

    delete p;

    display(p,size);
    // cout<<sizeof(p)/sizeof(int)<<endl;
    int a[5]={1,2,3,4,5};
    display(a,5);

}