#include<iostream>
#include <windows.h>
using namespace std;

//定义顺序表结构
#define maxsize 100

typedef struct SqList{
    int *elem;
    int length;
}SqList;


// void fun(int i){

// }




//初始化顺序表
bool InitList(SqList &L){
    //开100间房

    L.elem=new int[maxsize];
    //申请内存失败，返回false
    if(L.elem==nullptr){
        return false;
    }
    //申请成功，计时器置为0，表明顺序表当前长度为0
    L.length=0;
    return true;
}

//插入
bool InsertList(SqList &L,int i,int data){
    //插入索引非法
    if(i<0||i>L.length){
        return false;
    }

    //当前顺序表已满，拒绝插入
    if(L.length==maxsize){
        return false;
    }

    //开始搬运，从后往前搬运
    for(int j=L.length;j>=i;j--){
        L.elem[j]=L.elem[j-1];
    }
    //腾出的位置放入插入的值
    L.elem[i]=data;
    //多了一个元素
    L.length++;
    return true;
}

bool DeleteList(SqList &L,int i){
    //删除的位置是否合理
    if(i<0||i>L.length){
        return false;
    }
    //进行搬运，覆盖删除位置的值
    for(int j=i;j<L.length;j++){
        L.elem[j]=L.elem[j+1];
    }
    //顺序表长度-1
    L.length--;
    return true;
}

//查找
int SearchElem(SqList L,int data){
    //
    for(int i=0;i<L.length;i++){
        if(L.elem[i]==data){
            return i;
        }
    }
    //返回下标-1，表示不存在
    return -1;
}

//取第i个值
bool GetElem(SqList L,int i,int &data){
    //下标是否非法
    if(i<0||i>=L.length){
        return false;
    }
    //合法，直接取值
    data=L.elem[i];
    return true;
}

void SetElem(SqList &L,int data[],int length){
    L.length=length;
    for(int i=0;i<length;i++){
        L.elem[i]=data[i];
    }
    return;
}

//打印当前顺序表的值
void display(SqList L){
    for(int i=0;i<L.length;i++){
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}

// int main()
// {
//     // int i;
//     SqList L;
//     InitList(L);
//     InsertList(L,0,1);
//     InsertList(L,1,2);
//     InsertList(L,2,3);
//     display(L);
//     InsertList(L,0,0);
//     display(L);
//     DeleteList(L,0);
//     display(L);
//     DeleteList(L,1);
//     display(L);
// }

