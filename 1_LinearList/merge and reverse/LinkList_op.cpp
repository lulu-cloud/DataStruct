#include "D:\VSCODE\1_LinearList\LinkedList\LinkedList.cpp"


ListNode *merge(ListNode *&L1,ListNode *&L2){
    ListNode *p=L1->next;
    ListNode *q=L2->next;
    ListNode *now=L1;
    while(p!=nullptr&&q!=nullptr){
        if(p->data<q->data){
            now->next=p;
            p=p->next;
        }
        else{
            now->next=q;
            q=q->next;
        }
        now=now->next;
    }
    if(p!=nullptr){
        q=p;
    }
    now->next=q;
    return L1;
}

 //头插法思想进行翻转
void reverse(ListNode *&L){
    ListNode *p=L->next;
    //使得最终的表尾为空
    L->next=nullptr;
    while(p!=nullptr){
        //存一下后继结点
        ListNode *q=p->next; 
        //头插
        p->next=L->next;
        L->next=p;
        p=q; 
    }
    return;
}


int main()
{
    int L1_data[]={1,3,4,7,9};
    int L2_data[]={2,3,5,6,12};
    ListNode *L1;
    ListNode *L2;
    InitList(L1);
    InitList(L2);
    GetValue_tail(L1,L1_data,sizeof(L1_data)/sizeof(int));
    GetValue_tail(L2,L2_data,sizeof(L2_data)/sizeof(int));
    ListNode* L3=merge(L1,L2);
    display(L3);
    
    reverse(L3);
    display(L3);

}