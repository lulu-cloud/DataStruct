#include<iostream>
#include <windows.h>
using namespace std;

void C(){
    cout<<"这是 C 函数"<<endl;
}

void B(){
    cout<<"这是 B 函数"<<endl;
    C();
    cout<<"这是 B 函数返回"<<endl;
}


void A(){
    cout<<"这是 A 函数"<<endl;
    B();
    cout<<"这是 A 函数返回"<<endl;
}

void R(int n){
    //套娃出口 临界状态，就是出口
    if(n==0)    {
        cout<<"差不多得了"<<endl;
        return ;
    }
    cout<<"这是第"<<n<<"层的 R 函数"<<endl;
    //调用自己 套娃 
    //走到出口，每次状态都不一样
    R(n-1);
    cout<<"这是第"<<n<<"层的 R 函数返回"<<endl;
    return;
}

void display(int a[],int i,int length){
    //i表示状态
    if(i==length){
        return;
    }
    
    display(a,i+1,length);
    cout<<a[i]<<" ";
}

int main()
{
    cout<<"主程序"<<endl;
    // A();
    // R(4);


    int a[]={1,2,3,4,5};
    // for(int i=0;i<5;i++){
    //     cout<<a[i]<<" ";
    // }
    display(a,0,5);
    return 0;
}