
#include<iostream>
#include <windows.h>
using namespace std;


void fun(int* &a){
    a=new int;
    *a=3;
    cout<<"内部a:"<<a<<endl;
    cout<<*a<<endl;
    return;
}

int main()
{
    int* a=NULL;
    cout<<"外部a（未执行函数之前）:"<<a<<endl;
    fun(a);
    cout<<"外部a（执行函数之后）:"<<a<<endl;
    cout<<*a<<endl;
}