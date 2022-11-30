#include<iostream>
#include <windows.h>
using namespace std;

typedef struct ListNode
{
    int data;
    ListNode* next;
}ListNode;


//初始化一个带头节点的链表
bool InitList(ListNode *&L){
    
    
    L=new ListNode;
    // L=(ListNode*)malloc(sizeof(ListNode)*1);

    // double num=2.2;
    // int a=(int)num;
    // //a=2;

    //有指针出现，暂时不知道指向的时候，要设置为null
    L->next=nullptr;
    return true;
}

//销毁
bool DestroyList(ListNode *&L){
    ListNode *p=L;
    //连带着头结点一起销毁
    while(L!=nullptr){
        p=L;
        L=L->next;
        delete p;  
    }
    return true;
}

//清空
bool ClearList(ListNode *&L){
    ListNode *p=L->next;
    while(p!=nullptr){
        ListNode *q=p->next;
        delete p;
        p=q;
    }
    //最后的处理！
    L->next=nullptr;
    return true;
}

//求链表长度
int GetListLength(ListNode *L){
    int cnt=0;
    ListNode *p=L;
    if(L->next==nullptr){
        return 0;
    }
    while(p!=nullptr){
        p=p->next;
        cnt++;
    }
    return cnt-1;
}

//判空
bool isEmpty(ListNode *L){
    if(L->next==nullptr){
        return true;
    }
    return false;
}

//取值
bool GetElem(ListNode *L,int i,int &data){
    //取第i个元素的值，若能取，赋值给data，返回true;否则返回false
    ListNode *p=L->next;
    int cnt=0;
    //遍历，看看能否找到第i个值
    while(p!=nullptr && cnt<i){
        p=p->next;
        cnt++;
    }
    //当前链表没走完(i比链表长小)
    if(p!=nullptr&&cnt==i){
        data=p->data;
        return true;
    }
    return false;
}


//查找1:返回地址
ListNode* SearchElem1(ListNode* L,int data){
    //寻找链表L是否存在data数据
    ListNode *p=L->next;
    while(p!=nullptr){
        if(p->data==data){
            //找到，返回当前结点地址，就是p(p是指针)
            return p;
        }
        //不要忘记这个操作，不然会死循环
        p=p->next;
    }
    //没找到
    return NULL;
}

//查找2:返回下标
int SearchElem2(ListNode* L,int data){
    //寻找链表L是否存在data数据
    int cnt=0;
    ListNode *p=L->next;
    while(p!=nullptr){
        if(p->data==data){
            //找到，返回当前结点地址，就是p(p是指针)
            return cnt;
        }
        //不要忘记这个操作，不然会死循环
        p=p->next;
        cnt++;
    }
    //没找到
    return -1;
}


// void fun(int a,int b){
//     a=1;
//     b=1;
// }


//插入1，在第i个位置之前插入data
bool insertListNode1(ListNode* &L,int i,int data){
    /**
     * 1、找到第i-1个位置(pre)
     * 2、生成一个新节点(s)，将data作为结点数据(s->data=data)
     * 3、新节点的指针指向第i个结点(s.next=pre.next)
     * 4、第i-1个节点的指针指向新节点(pre->next=s)
     * 
     */
    ListNode *pre=L;
    int cnt=i-1;
    while(pre!=nullptr&&cnt>0){
        pre=pre->next;
        cnt--;
    }
    if(pre!=nullptr){
        //找到pre
        ListNode *s=new ListNode;
        s->data=data;
        s->next=pre->next;
        pre->next=s;
        return true;
    }
    else{
        return false;
    }
}

//插入2，在target之前插入data
bool insertListNode2(ListNode* &L,int target,int data){
    /**双指针法
     * (*)1、找到target的结点p以及它的前驱结点pre
     *    2、生成一个新节点(s)，将data作为结点数据(s->data=data)
     *    3、新节点的指针指向target结点(s.next=pre.next)(pre.next=target,此时等效)
     *    4、第i-1个节点的指针指向新节点(pre->next=s)
     * 
     */
    ListNode *pre=L;
    ListNode *p=L->next;
    while(p!=nullptr){
        if(p->data==target){
            //找到当前target结点，break
            break;
        }
        pre=p;
        p=p->next;
    }
    if(p==nullptr){
        return false;
    }
    else{
        ListNode *s=new ListNode;
        s->data=data;
        //不能调换
        s->next=pre->next;
        pre->next=s;
        return true;
    }
}


//删除1
bool deleteListNode1(ListNode *&L,int index){
    //删除index值的结点
    int cnt=index-1;
    ListNode *pre=L;
    while(pre!=nullptr&&cnt>0){
        pre=pre->next;
    }
    if(pre==nullptr){
        return false;
    }
    else{
        pre->next=pre->next->next;
        delete pre->next;
        return true;
    }
}

//删除2
bool deleteListNode2(ListNode*&L,int target){
    //删除target值的结点
    //双指针法
    ListNode *p=L->next;
    ListNode *pre=L;
    while(p!=nullptr){
        if(p->data==target){
            break;
        }
        pre=p;
        p=p->next;
    }
    if(p==nullptr){
        return false;
    }
    else{
        //218删除
        pre->next=p->next;
        delete p;
        return true;
    }
}


//尾插法
void GetValue_tail(ListNode *&L,int datas[],int length){
    //L是头指针
    ListNode* tail=L;
    for(int i=0;i<length;i++){
        ListNode* p=new ListNode;
        p->data=datas[i];
        //防止野指针
        p->next=nullptr;
        //尾插
        tail->next=p;
        tail=p;
    }
}

//头插法
void GetValue_head(ListNode *&L,int datas[],int length){
    //L是头指针
    for(int i=0;i<length;i++){
        ListNode* p=new ListNode;
        p->data=datas[i];
        //头插
        p->next=L->next;
        L->next=p;
    }
}



void display(ListNode *L){
    ListNode*p=L;
    cout<<"节点地址\t"<<"节点data\t"<<"节点next"<<endl;
    while(p!=nullptr){
        cout<<p<<"\t"<<p->data<<"\t"<<p->next<<endl;
        p=p->next;
    }
    //测试表长
    int length=GetListLength(L);
    cout<<"当前链表长度为:"<<length<<endl;
    cout<<endl;
}




int main()
{
    int datas[]={2,1,6,7,9,8,5,3,4};
    ListNode* L=nullptr;


    //初始化
    InitList(L);

    
    GetValue_head(L,datas,sizeof(datas)/sizeof(int));
    // GetValue_tail(L,datas,sizeof(datas)/sizeof(int));
    display(L);
    cout<<endl;



    /**---查找测试1----*/
    int data0=9;
    ListNode *data_address=SearchElem1(L,data0);
    cout<<data0<<"的地址为:"<<data_address<<endl;
    cout<<endl;   


    /**---查找测试2----*/
    int data1=9;
    int data_index=SearchElem2(L,data1);
    cout<<data1<<"在链表中位置为:"<<data_index<<endl;
    cout<<endl;  


    /**取值测试*/
    int get_data=-1;
    int i=2;
    if(GetElem(L,i,get_data)){
        cout<<"第"<<i<<"个元素为"<<get_data<<endl;
    }
    else{
        cout<<"第i个值不存在,取值失败"<<endl;
    }
    cout<<endl;

    /**插入测试1*/
    // int insert_data1=-1;
    // int insert_index=4;
    // insertListNode1(L,insert_index,insert_data1);
    // display(L);

    /**插入测试2*/
    int insert_data2=-2;
    int insert_target=4;
    insertListNode2(L,insert_target,insert_data2);
    display(L);

    /**删除测试1*/
    // int insert_data2=-2;
    // int delete_index=1;
    // deleteListNode2(L,delete_index);
    // display(L);

    /**删除测试2*/
    // int insert_data2=-2;
    int delete_target=7;
    deleteListNode2(L,delete_target);
    display(L);
    

    //清空链表
    ClearList(L);
    if(isEmpty(L)){
        cout<<"链表为空！"<<endl;
    }
    else{
        cout<<"链表不为空！"<<endl;
    }
    cout<<endl;    


    //销毁链表
    DestroyList(L);
    cout<<endl;
}



/**
 * 任务
 * 
 * 重写insertListNode函数1
 * 使之成为插入在第i个位置
 * 
 *  
 * 
 * 
 * 
 */