#include<iostream>
#include <windows.h>
using namespace std;


typedef struct BSTNode
{
    int data;      //结点域
    BSTNode* left;     //左指针
    BSTNode* right;    //右指针
    /* data */
}BSTNode;


BSTNode* search(BSTNode* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    //去左子树找
    else if(root->data>key){
        return search(root->left,key);
    }
    //去右子树找
    else{
        return search(root->right,key);
    }
}

void insert(BSTNode* &root,int key){
    if(root==NULL){
        root=new BSTNode;
        root->data=key;
        root->left=root->right=NULL;
    }
    //去左子树插入
    else if(root->data>key){
        insert(root->left,key);
    }
    //去右子树找
    else{
        insert(root->right,key);
    }
}

void createBST(BSTNode* &root,int data[],int n){
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
}

void display(BSTNode* root){
    if(root==NULL){
        return;
    }
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int main()
{
    //排序树、查找树
    int data[]={40,24,12,37,55};
    BSTNode* root=NULL;
    createBST(root,data,5);
    display(root);
    cout<<endl;
    insert(root,54);
    display(root);
    cout<<endl;
}   
