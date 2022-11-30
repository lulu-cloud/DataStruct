#include "D:\VSCODE\1_LinearList\SquentialList\squence_learn.cpp"




//原地翻转顺序表L
//双"指针"法
void reverse(SqList &L){
    int i=0,j=L.length-1;
    while(i<j){
        int temp=L.elem[i];
        L.elem[i]=L.elem[j];
        L.elem[j]=temp;
        //不要忘记，会死循环
        i++;
        j--;
    }
    return ;
}



//归并两个有序顺序表
/**如
 * L1={1,3,4,7,9}
 * L2={2,3,5,6,12}
 * 返回新的顺序表L3
 * L3={1,2,3,3,4,5,6,7,9,12}
*/
SqList mergeSqList(SqList L1,SqList L2){
    SqList L3;
    InitList(L3);
    L3.length=L1.length+L2.length;
    int i=0,j=0;
    int k=0;
    while(i<L1.length&&j<L2.length){
        if(L1.elem[i]<L2.elem[j]){
            L3.elem[k]=L1.elem[i];
            i++;k++;
        }
        else{
            L3.elem[k]=L2.elem[j];
            j++;k++;
        }
    }
    while(i<L1.length){
        L3.elem[k]=L1.elem[i];
        i++;k++;
    }
    while(j<L2.length){
        L3.elem[k]=L2.elem[j];
        j++;k++;
    }
    return L3;
}


int main()
{
    SqList L1;
    SqList L2;
    InitList(L1);
    InitList(L2);
    int L1_data[]={1,3,4,7,9};
    int L2_data[]={2,3,5,6,12};
    // sort()
    SetElem(L1,L1_data,sizeof(L1_data)/sizeof(int));
    SetElem(L2,L2_data,sizeof(L2_data)/sizeof(int));
    SqList L3=mergeSqList(L1,L2);
    display(L3);
    reverse(L3);
    display(L3);
}
