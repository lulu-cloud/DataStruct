#include<iostream>
#include <windows.h>
using namespace std;


typedef char ElemType;
//定义栈结构
#define maxsize 100

typedef struct SqStack{
    ElemType *base;
    int top;
}SqStack;



//初始化栈
bool InitStack(SqStack &stack){
    stack.base=new ElemType[maxsize];
    if(stack.base==nullptr){
        return false;
    }
    stack.top=-1;
    return true;
}

// {
//     int a[]={1,2,3,4};
//     a[0];
//     a[3];
//     int *p=new int[120];
//     p[0]
//     p[10]
// }

//入栈
bool push(SqStack &stack,ElemType data){
    //存储空间还有
    if(stack.top<maxsize){
        stack.top++;
        stack.base[stack.top]=data;
        return true;
    }
    return false;
}

//出栈
ElemType pop(SqStack &stack){
    if(stack.top>-1){
        ElemType data=stack.base[stack.top];
        stack.top--;
        return data;
    }
    return (ElemType)-1;
}

//查看栈顶元素
ElemType peek(SqStack stack){
    if(stack.top>-1){
        return stack.base[stack.top];
    }
    return (ElemType)-1;
}

//判定栈是否为空
bool isEmpty(SqStack stack){
    if(stack.top==-1){
        return true;
    }
    return false;
}

void display(SqStack stack){
    cout<<"当前栈顶指针top="<<stack.top<<" 栈顶元素为:"<<peek(stack)<<endl;
    for(int i=stack.top;i>-1;i--){
        cout<<stack.base[i]<<endl;
    }
    cout<<endl;
}

// int main()
// {
//     SqStack stack;
//     InitStack(stack);
//     push(stack,2);
//     push(stack,1);
//     display(stack);
//     int data=pop(stack);
//     cout<<data<<endl;
//     push(stack,5);
//     push(stack,3);
//     display(stack);
//     data=pop(stack);
//     cout<<data<<endl;
//     display(stack);
// }