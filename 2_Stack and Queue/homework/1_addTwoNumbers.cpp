// #include <stack>
#include<iostream>

#include "D:\VSCODE\1_LinearList\LinkedList\LinkedList.cpp"
 
using namespace std;

/**
 * @brief 
 * 
 * @param l1 
 * @param l2 
 * @return ListNode* 
 * 
 * 1、设置进位标志carry，申请一个新的头结点，作为新链表的头
 * 2、双指针遍历两个链表，如果两个链表都没有遍历到末尾
 *     
 *      2.1、两个结点值相加再加上carry得num
 *      2.2、如果num>=10
 *              carry设置为1
 *              num-=10
 *      2.3、否则
 *              carry设置为0
 *      2.4、申请一个结点，将num的值赋值给该结点，尾插法延长新链表
 *      2.5、双指针往后移动一次
 * 3、其中一个链表遍历完毕，继续遍历另一个链表
 *      3.1、结点值相加再加上carry得num
 *      3.2、如果num>=10
 *              carry设置为1
 *              num-=10
 *      3.3、否则
 *              carry设置为0
 *      3.4、申请一个结点，将num的值赋值给该结点，尾插法延长新链表
 * 4、若最后的carry>0
 *      4.1、再次申请一个新节点，将carry放入新的结点，尾插法分延长新链表
 * 5、返回头结点的下一个结点
 */

ListNode* addTwoNumbers(ListNode *l1,ListNode *l2){
    /**
     * @brief 请在此处写入你的代码
     * 
     */
    
}

int main()
{
    /*测试样例代码，勿动！*/
    ListNode* l1;
    ListNode* l2;
    InitList(l1);
    InitList(l2);
    int data1[]={9,7,8,9};
    int data2[]={1,1,5,8,9};
    GetValue_tail(l1,data1,sizeof(data1)/sizeof(int));
    GetValue_tail(l2,data2,sizeof(data2)/sizeof(int));
    display(l1);
    display(l2);
    l1=l1->next;
    l2=l2->next;
    ListNode* ans=addTwoNumbers(l1,l2);
    //应该输出0 9 3 8 0 1
    display(ans);

    // int *p1=new int[10];
    // int *p2=(int*)malloc(sizeof(int)*10);

}