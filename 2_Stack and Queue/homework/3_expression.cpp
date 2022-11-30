#include <iostream>
#include <string>
#include "D:\VSCODE\2_Stack and Queue\Stack.cpp"
 
using namespace std;
/**
 * @brief 
 * 
 * 
 * 中缀求值
 算法思想
 *定义两个栈：

 *数据栈：s1，用以存储数字；

 *运算符栈：s2，用以存储运算符；

 *将字符元素一个个扫描，遇到操作数则进栈s1，

 *遇到运算符型，需要判断：
 *s2栈顶元素运算符优先级是否比当前运算符大或等于：
    1. 成立：
        1.1 那么s2栈顶运算符出栈：假设出栈是运算符a，那么此时从s1中出栈两个数字b、c参与运算，把运算结果进栈s1；
        1.2 循环1.1操作，直到栈顶元素不满足条件
        1.3 当前运算符入栈
    2. 不成立：当前运算符入栈

  *遇到(直接进s1，
  *遇到)则就要把这一对括号之间运算符都一个个拿出来运算,与1.1处理过程一致
  * 
  */
bool equal(char ch,char top){
   if((ch=='*'||ch=='/')&&(top=='+'||top=='-'||top=='(')){
      return true;
   }
   else{
      return false;
   }
}


//返回num1 op num2
//   num1='9'  num2='8'  op='-'
// int 返回1
int opreator(char num1,char num2,char op){
   return -1;
}

int expression_mid(string s){
   SqStack s1;
   SqStack s2;
   //s1为数字栈，s2为符号栈
   // int ch3=(ch-'0')+(ch2-'0');
   InitStack(s1);
   InitStack(s2);
   for(int i=0;i<s.length();i++){
      char ch=s[i];
      if(ch>='0'&&ch<='9'){
         //操作数的情况，进栈s1
         push(s1,ch);
      }
      else{
         //操作符的情况
         if(isEmpty(s2)){
            //s2为空，不需要比较优先级
            push(s2,ch);
         }
         else{
            //比较优先级
            char top=peek(s2);
            if(ch=='('){
               //左括号
               push(s2,ch)
            }
            //第一种，当前ch优先级大于栈顶运算符的优先级
            if((ch=='*'||ch=='/')&&(top=='+'||top=='-'||top=='(')){
               push(s2,ch);
            }
            else{
               
               while(!equal(ch,top)){
                  char op=pop(s2);
                  char num1=pop(s1);
                  char num2=pop(s1);
                  int ans=opreator(num1,num2,op);
                  push(s1,char(ans+'0'));
                  top=peek(s2);
               }
            }
         }
      }
   }

   
}

int main()
{
   expression_mid(" ");
   return 0;
}

 /**
  * @brief 
  * 
  * 后缀表达式求值
  * 算法思想
  * 设置一个栈，开始时，栈为空，然后从左到右扫描后缀表达式，若遇操作数，则进栈；

  * 若遇运算符，则从栈中退出两个元素，先退出的放到运算符的右边，后退出的 放到运算符左边，运算后的结果再进栈，直到后缀表达式扫描完毕。
  * 
  */

 int expression_last(string s){
    return 0;
 }
