#include<iostream>
#include<queue>
#include<stack>
#include <windows.h>
using namespace std;

typedef char ElemType;

typedef struct TreeNode
{
    ElemType data;      //结点域
    TreeNode* left;     //左指针
    TreeNode* right;    //右指针
    /* data */
}TreeNode;






//先序
void preOrderTraverse(TreeNode* root){
    //空结点直接返回

    if(root==nullptr){
        return ;
    }

    //访问根节点
    cout<<root->data<<" ";


    //先序遍历左子树
    preOrderTraverse(root->left);

    //然后,先序遍历右子树
    preOrderTraverse(root->right);
    
    
    // return;
}


//中序
void inOrderTraverse(TreeNode* root){
    //空结点直接返回
    if(root==nullptr){
        return ;
    }
    
    //中序遍历左子树
    inOrderTraverse(root->left);

    //访问根节点
    cout<<root->data<<" ";
    
    //然后,中序遍历右子树
    inOrderTraverse(root->right);


    // return;
}

//后序
void postOrderTraverse(TreeNode* root){
    //空结点直接返回
    if(root==nullptr){
        return ;
    }
    //后序遍历左子树
    postOrderTraverse(root->left);
    //然后,后序遍历右子树
    postOrderTraverse(root->right);


    //访问根节点
    cout<<root->data<<" ";


    // return;
}

//层序
void layerOrderTraverse(TreeNode* root){
    if(root==nullptr){
        return ;
    }
    queue<TreeNode*>q;
    //根节点入队
    q.push(root);
    // q..size
    //队列不空，进行循环
    while(!q.empty()){
        TreeNode* node=q.front();
        
        //出队并且访问
        cout<<node->data<<" ";
        q.pop();
        //左右子树若是存在，左右子树入队
        if(node->left!=nullptr){
            q.push(node->left);
        }
        if(node->right!=nullptr){
            q.push(node->right);
        }
    }
    cout<<endl;
}


//非递归前序
void preOrderTraverse1(TreeNode* root){
    TreeNode* p=root;
    stack<TreeNode*>s;
    while(!s.empty()||p!=NULL){
        if(p!=NULL){
            //当前结点不是空节点，优先访问
            cout<<p->data<<" ";
            //当前节点入栈
            s.push(p);
            //一直往左走
            p=p->left;
        }
        else{
            //p==null
            //栈顶元素出栈，也就是左子树上的结点
            TreeNode* top=s.top();
            s.pop();
            //转向右子树
            p=top->right;
        }
    }
}

//非递归中序
void inOrderTraverse1(TreeNode* root){
    TreeNode* p=root;
    stack<TreeNode*>s;
    while(!s.empty()||p!=NULL){
        if(p!=NULL){
            //当前节点入栈
            s.push(p);
            //一直往左走
            p=p->left;
        }
        else{
            //p==null
            //栈顶元素出栈，也就是左子树上的结点
            TreeNode* top=s.top();
            s.pop();
            //当前结点不是空节点，优先访问
            cout<<top->data<<" ";
            //转向右子树
            p=top->right;
        }
    }
}

//非递归后序
void postOrderTraverse1(TreeNode* root){
    TreeNode* p=root;
    TreeNode* pre=NULL;
    stack<TreeNode*>s;
    while(!s.empty()||p!=NULL){
        if(p!=NULL){
            //当前节点入栈
            s.push(p);
            //一直往左走
            p=p->left;
        }
        else{
            //分两种情况了
            TreeNode* top=s.top();

            //栈顶元素存在右孩子，并且右孩子没有访问过
            if(top->right!=NULL&&top->right!=pre){
                //转向右孩子
                p=top->right;
            }
            //右孩子为空，或者右孩子以及访问,说明当前节点下，左右子树皆被访问，此时访问当前节点即可,并处理好p=null，pre=当前节点
            else{
                cout<<top->data<<" ";
                s.pop();
                pre=top;
            }
        }//end else
    }//end while
}


//创建树
TreeNode* createTree(TreeNode* root){
    char ch;
    cin>>ch;
    if(ch!='#'){
        root=new TreeNode;
        root->data=ch;
        root->left=nullptr;
        root->right=nullptr;
        root->left=createTree(root->left);
        root->right=createTree(root->right);
    } 
    return root;
}

//方法一
void getNum(TreeNode* root,int &num){
    if(root==NULL){
        return ;
    }

    num++;
    getNum(root->left,num);
    getNum(root->right,num);
}

//方法二
int getNum2(TreeNode* root){
    //空就是0个节点
    if(root==NULL){
        return 0;
    }
    int left=getNum2(root->left);
    int right=getNum2(root->right);
    return left+right+1;
}

int max(int a,int b){
    return a>b?a:b;
}

int getDeep(TreeNode* root){
    if(root==NULL){
        return 0;
    }

    int left=getDeep(root->left);
    int right=getDeep(root->right);
    return max(left,right)+1;
    //     1 ? 2 : 3 
    // return getDeep(root->left)>getDeep(root->right)? getDeep(root->left)+1 : getDeep(root->right)+1;
}

//翻转二叉树
//形参

// int fun(int a){
//     a++;
// }

void fanzhuan(TreeNode* root){
    if(root==NULL){
        return;
    }

    TreeNode* a=NULL;
    a=root->left;
    root->left=root->right;
    root->right= a;
    //前序遍历
    fanzhuan(root->left);
    fanzhuan(root->right);

    // return 1;
}

bool is_GoodTree(TreeNode* root){
    //判定是否为完全二叉树
    
    //定义队列q，层序遍历的思想
    queue<TreeNode*>q;
        if(root==nullptr){
        return true;
    }
    q.push(root);
    while(!q.empty()){
        //看看队首结点
        TreeNode*top=q.front();
        q.pop();
        if(top==NULL){
            //把队列元素统统弹出，看看是否有非空结点
            while(!q.empty()){
                TreeNode*top1=q.front();
                if(top1!=NULL){
                    return false;
                }
            }
            return true;
        }
        q.push(top->left);
        q.push(top->right);
    }
    return true;    
}


int main()
{
    TreeNode* a=new TreeNode;
    TreeNode* b=new TreeNode;
    TreeNode* c=new TreeNode;
    TreeNode* d=new TreeNode;
    TreeNode* e=new TreeNode;
    TreeNode* f=new TreeNode;
    TreeNode* g=new TreeNode;
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=nullptr;
    c->right=nullptr;
    d->left=nullptr;
    d->right=nullptr; 
    e->left=f;
    e->right=g;
    f->left=nullptr;
    f->right=nullptr;
    g->left=nullptr;
    g->right=nullptr;

    a->data='a';
    b->data='b';
    c->data='c';
    d->data='d';
    e->data='e';
    f->data='f';
    g->data='g';

    cout<<is_GoodTree(a);

    // TreeNode* root=createTree(root);



    // preOrderTraverse(root);


    //前序
    cout<<"前序遍历："<<endl;    
    preOrderTraverse(a);
    cout<<endl;
    //非递归前序
    cout<<"非递归前序遍历："<<endl;    
    preOrderTraverse1(a);
    cout<<endl;
    cout<<"反转后"<<endl;
    fanzhuan(a);
    preOrderTraverse1(a);
    cout<<endl;

    //中序
    cout<<"中序遍历："<<endl;    
    inOrderTraverse(a);
    cout<<endl;
    //非中归前序
    cout<<"非递归中序遍历："<<endl;    
    inOrderTraverse1(a);
    cout<<endl;
    //后序
    cout<<"后序遍历："<<endl;    
    postOrderTraverse(a);
    cout<<endl;
    //非递归后序
    cout<<"非递归后序遍历："<<endl;    
    postOrderTraverse1(a);
    cout<<endl;
    //层序
    cout<<"层序遍历："<<endl;    
    layerOrderTraverse(a);
    cout<<endl;
    int num=0;
    getNum(a,num);
    cout<<num<<endl;
    int num2=0;
    num2=getNum2(a);
    cout<<num2<<endl;
    int deep=getDeep(a);
    cout<<deep<<endl;
}