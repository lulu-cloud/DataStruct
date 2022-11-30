#include<iostream>
#include <windows.h>
using namespace std;

/**
 * @brief 
 * 
 * 
 * 数组
 * 
 * 
 */


//int double char float


//结构体
//里面可以包含结构体指针



typedef struct Student
{
    int id;
    string name;
    Student* next;
}Student;



//函数
//函数头 函数体

//返回类型 函数名(形参列表){
//  函数体
// return 语句;
//}

// for(int i=0;;){
//
// }


int back(int n){
    cout<<"back 函数"<<endl;
    return n+1;
}

void swap(int *a,int *b){
    // cout<<&a<<endl;
    // cout<<&b<<endl;
    int temp=*a;
    *a=*b;
    *b=temp;
    int n=2;

    cout<<back(n)<<endl;

    cout<<"n="<<n<<endl;
    return ;

}

//引用 &
void swap_1(int &a,int &b){
    cout<<"内部a，b地址"<<endl;
    cout<<&a<<endl;
    cout<<&b<<endl;
    int temp=a;
    a=b;
    b=temp;
    return ;
}

//指针
int main()
{

    int a[4]={1,2,3,4};
    
    int *b;
    b=new int[11];

    // b[0];
    // b[3];



    // int a[]={1,2,3,4};
    // for(int i=0;i<4;i++){
    //     cout<<a[i]<<endl;
    // }


    // //二维数组
    // int a[2][4]={{1,2,3,4},
    //              {1,2,3,4}};

    // int a[][][]={{{},},}


    // Student zhang_san={1,"zhangsan"}; 
    // // Student zhang_san_1={"one","zhangsan"}; 
    
    // cout<<zhang_san.id<<endl;
    // cout<<zhang_san.name<<endl;

    // zhang_san.id=2;
    // zhang_san.name="lisi";
    // cout<<zhang_san.id<<endl;


    // int     a=9;
    // int*    p=  & a;  //p是指针, & 取地址符号
    
    // int*  p = nullptr; //声明+初始化
    // p = &a;   //赋值


    // p=&a;
    // *p != &a
    // cout<<*p<<endl; //*p代表取当前p地址的变量,此时*p=a
    // cout<<p<<endl;  //输出p，就是p的内容，a的地址
    // cout<<&p<<endl; 
    // cout<<* &p<<endl;
    // cout<<** &p<<endl;

    int a=9;
    int b=-8;

    //f(x,y)
    cout<<"初始a，b地址"<<endl;
    cout<<&a<<endl;
    cout<<&b<<endl;
    // swap(&a,&b); 
    // swap_1(a,b);  
    cout<<"外部a，b"<<endl; 
    cout<<a<<endl;
    cout<<b<<endl;

    // int* a=&b;
    // double b=3.2;
    // cout<<*a<<endl;
    // p=&b;
    // cout<<*p;

    return 0;
}