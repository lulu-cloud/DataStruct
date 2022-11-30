#include <stack>
#include <iostream>
#include <string>
#include "D:\VSCODE\2_Stack and Queue\Stack.cpp"

using namespace std;

    /**
     * ()、{}、[]
     * (){}[]、[({})]
     * 思路：用栈来解决
     * 1、遇见左字符，将左字符入栈
     * 2、遇见右字符
     *      2.1、如果栈为空，说明括号无效，返回false
     *      2.2、如果栈不为空，将栈顶字符出栈，与右字符值匹配
     * 3、判断左右字符是否匹配
     *      3.1、如果左右字符不匹配，说明括号无效
     *      3.2、如果左右字符匹配，继续扫描下一个字符
     * 4、当所有字符扫描完毕之后
     *      4.1、栈为空，说明括号有效
     *      4.2、栈不为空，说明括号无效
     */

bool isValid(char s[],int length) {
    /**
     * @brief 请在此处写入你的代码
     * 
     */
    //声明一个栈并且初始化它
    // stack<int>ans;
    // ans.size
    SqStack stack;
    InitStack(stack);
    for(int i=0;i<length;i++){
        //循环代码，遍历字符(1)
        char ch=s[i];
        if(ch=='('||ch=='{'||ch=='['){
            //左字符的情况(2)
            push(stack,ch);
        }
        else{
            //右字符的情况(2)
            if(isEmpty(stack)){
                //2.1栈为空的情况
                return false;
            }
            else{//(3)
                //2.2栈不空，栈顶字符出栈，
                char data=pop(stack);
                //3 抛出来的data一定都是左字符
                if(ch=='}'&&data=='{'){
                    //匹配情况一
                    continue;
                }
                if(ch==')'&&data=='('){
                    //匹配情况二
                    continue;
                }
                if(ch==']'&&data=='['){
                    //匹配情况三
                    continue;
                }
                else{
                    //3.1匹配无效
                    return false;
                }                                
            }
        }
    }
    //end for
    // "(()"
    //4、栈为空的时候，才是匹配成功
    if(isEmpty(stack)){
        return true;
    }
    return false;
}


void display(char s[],int length){
    if(isValid(s,length)){
        for(int i=0;i<length;i++){
            cout<<s[i]<<" ";
        }
        cout<<"\t匹配！"<<endl;
    }
    else{
        cout<<"\t不匹配!"<<endl;
    }
}

int main()
{
    char s[]={'(',')','{','}','[',']'};
    string s1="(){}[]";
    string s2="((){}){}[]";
    string s3="((){}){}]]";
    string s4="]";
    string s5="{";
    // const char *ch1=s1.data();
    // const char *ch2=s2.data();
    // const char *ch3=s3.data();
    // const char *ch4=s4.data();
    // const char *ch5=s5.data();
    // display(ch1,sizeof(ch1)/sizeof(char));    
    // display(ch2,sizeof(ch2)/sizeof(char));
    // display(ch3,sizeof(ch3)/sizeof(char));
    // display(ch4,sizeof(ch4)/sizeof(char));
    // display(ch5,sizeof(ch5)/sizeof(char));       
    display(s,6);     
    // display(s2);
    // display(s3);
    // display(s4);
    // display(s5);
}