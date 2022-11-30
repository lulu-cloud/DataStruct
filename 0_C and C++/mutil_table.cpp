#include<iostream>

using namespace std;


//链表的结构体
typedef struct Node
{
    int num;
    Node *next;
}Node;




int main()
{
    // int i=0;
    // for( ;i<50;i++){
    //     //执行循环体的内容

    //     cout<<"i:"<<i<<endl;
    // }

    // cout<<"i="<<i<<endl;

    // int num=-2;


        // if(num>0){
        //     //
        //     cout<<"大于0";
        // }


        // if(num<=-1){
        //     cout<<"小于等于-1";
        // }

        // if(num<=-2){
        //     cout<<"小于等于-2";
        // }





    // {
    //     int i=0;
    //     i++;
    //     cout<<"i="<<i<<endl;
    // }


    

    
    //  (x0,y0)


    //函数也要先声明后使用
    int f(int x);


    //逻辑运算符号返回的是true或者false



    // for(  1、初始化语句，只执行一次;2、 判定条件，结果为true，进入循环，否则跳出循环  ; 3、执行循环体后的语句){
            //循环体
    // }


    //（判定条件，结果为true，进入循环，否则跳出循环）
    int i=0;
    while(i<100){
        //循环体
        



        i++;
    }
    cout<<i<<endl;
// for(;;){

// }
// while(  ){

// }
    for(int i=0 ; ; ){

    }
    // 链表、二叉树
    // while(f(i)==y){

    // }


    //遍历(0,0) -> (99,99)
    //定义两个变量i,j
    // int j=0 ;
    int cnt=0;
    int cnt_0=0;
    for(int i=0;   i<100;    i++){
        for(int j=0;  j<100;  j++){
           if(f(i)==j){
              cout<<i<<" "<<j<<endl;
           }
           cnt+=1;
        }
        cnt_0+=1;
    }
    cout<<cnt_0<<endl;

    cout<<cnt<<endl;
    
    // 循环代码
    for(int i=1;i<=9;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<"*"<<i<<"="<<i*j<<"\t";
        }
        cout<<endl;
    }

    // cout<<"i="<<i<<endl;
    return 0;

}

//数组、指针、引用、结构体
//函数


int f(int x){
    int y=2*x+1;
    return y;
}