#include<iostream>
#include <windows.h>
using namespace std;


typedef int ElemType;

typedef struct TreeNode
{
    ElemType data;      //结点域
    TreeNode* left;     //左指针
    TreeNode* right;    //右指针
    /* data */
}TreeNode;





//定义队列结构
#define maxsize 10

typedef struct SqQueue{
    ElemType *base;
    int front;//队首
    int rear;//队尾
}SqQueue;

void InitQueue(SqQueue &queue){
    queue.base=new ElemType[maxsize];
    queue.front=queue.rear=0;
}

//判空
bool isEmpty(SqQueue queue){
    if(queue.front==queue.rear){
        return true;
    }
    return false;
}

//入队
bool EnQueue(SqQueue &queue,ElemType data){
    if((queue.rear+1)%maxsize==queue.front){
        return false;
    }
    queue.rear=(queue.rear+1)%maxsize;
    queue.base[queue.rear]=data;
    cout<<data<<"入队"<<endl;
    return true;
}

// char ch='h';
// (int)ch

//出队
ElemType DeQueue(SqQueue &queue){

    if(queue.front==queue.rear){
        return (ElemType)-1;
    }
    ElemType data=queue.base[(queue.front+1)%maxsize];
    cout<<data<<"出队"<<endl;
    queue.front=(queue.front+1)%maxsize;
    return data;
}

//取队首元素
ElemType getTop(SqQueue queue){
    if(queue.front==queue.rear){
        return (ElemType)-1;
    }
    return queue.base[(queue.front+1)%maxsize];
}

//获取队列长度
int getLength(SqQueue queue){
    return (queue.rear-queue.front+maxsize)%maxsize;
}

void display(SqQueue queue){
    cout<<"队首下标:"<<queue.front<<" 队尾下标:"<<queue.rear<<endl;
    int length=getLength(queue);
    cout<<"队列长度为:"<<length<<endl;
    if(length==maxsize-1){
        cout<<"队列已满"<<endl;
    }
    cout<<"元素下标\t"<<"元素值"<<endl;
    int index=queue.front+1;
    int cnt=0;
    int size=getLength(queue);
    while(cnt<size){
        cout<<index%maxsize<<"\t\t"<<queue.base[index%maxsize]<<endl;
        index++;
        cnt++;
    }
    cout<<endl;
}


// int main()
// {
//     SqQueue queue;
//     InitQueue(queue);
//     EnQueue(queue,2);
//     EnQueue(queue,4);
//     EnQueue(queue,5);
//     display(queue);
//     EnQueue(queue,6);
//     DeQueue(queue);
//     DeQueue(queue);
//     display(queue);    
//     EnQueue(queue,9);
//     display(queue);  
//     EnQueue(queue,8);
//     EnQueue(queue,5);  
//     display(queue);
    
//     }




