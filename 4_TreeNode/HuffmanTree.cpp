#include<iostream>
#include <windows.h>
using namespace std;

typedef  struct HuffmanTree{
    int weight;
    int parent,lch,rch;
}HuffmanTree;


typedef  char* HuffmanCode;

void Select(HuffmanTree* HT,int index,int &s1,int &s2){
    //设最小值
    int min=0;
    int min_w=INT32_MAX;
    for(int i=1;i<=index;i++){
        int par=HT[i].parent;
        int w=HT[i].weight;
        if(HT[i].parent==0&&HT[i].weight<min_w){
            min_w=HT[i].weight;
            min=i;
        }
    }
    s1=min;
    int secondary=0;
    int secondary_w=INT32_MAX;
    for(int i=1;i<=index;i++){
        if(HT[i].parent==0&&HT[i].weight<secondary_w&&i!=s1){
            secondary_w=HT[i].weight;
            secondary=i;
        }
    }
    s2=secondary;
    return ;
}

//创建哈夫曼树****
void CreatHuffmanTree(HuffmanTree* &HT,int weigth[],int n){
    //n为根节点个数
    if(n<=1){
        return ;
    }

    int m=2*n-1;
    //0号不用
    HT=new HuffmanTree[m+1];
    // int weight[]={70,50,20,40};
    //初始化
    for(int i=1;i<=n;i++){
        HT[i].weight=weigth[i-1];
    }
    for(int i=1;i<=m;i++){
        HT[i].lch=0;
        HT[i].rch=0;
        HT[i].parent=0;
    }

    //开始构造
    for(int i=n+1;i<=m;i++){
        //在HT[k](1≤k≤i-1)中选择两个其双亲域为0,
        //且权值最小的结点,
        //并返回它们在HT中的序号s1和s2
        int s1,s2;
        Select(HT,i-1,s1,s2);
        //设置父节点
        HT[s1].parent=i;
        HT[s2].parent=i;
        //设置当前的左右孩子结点
        HT[i].lch=s1;
        HT[i].rch=s2;
        //设置权重
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
}


//构造哈夫曼编码
void CreatHuffmanCode(HuffmanTree *HT, HuffmanCode* &HC, int n){
    //从叶子到根逆向求每个字符的赫夫曼编码，存储在编码表HC中
    
    //分配n个字符编码的头指针矢量
    HC=new char* [n+1];
    //分配临时存放编码的动态数组空间
    char *cd=new char [n];			
    //编码结束符
    cd[n-1]='\0'; 	                                
    for(int i=1; i<=n; ++i){	                
        int start=n-1; int c=i; int f=HT[i].parent;                 			
        //从叶子结点开始向上回溯，直到根结点
        while(f!=0){	                                                 
            //回溯一次start向前指一个位置
            start--;                          			
            //结点c是f的左孩子，则生成代码0
            if (HT[f].lch == c)  cd[start]='0';	
            //结点c是f的右孩子，则生成代码1
            else cd[start]='1';               		
            //继续向上回溯
            c=f; f=HT[f].parent;             		
        }
        //求出第i个字符的编码                                       		                 
        // 为第i 个字符编码分配空间
        HC[i]= new char [n-start];         	                
        //将求得的编码从临时空间cd复制到HC的当前行中
        strcpy(HC[i], &cd[start]);    
    }
    delete cd;                            	    //释放临时空间
} // CreatHuffanCode


void displayHuffmanTree(HuffmanTree* HT,int n){
    cout<<"weight\t"<<"parent\t"<<"lch\t"<<"rch\t"<<endl;
    for(int i=1;i<=2*n-1;i++){
        cout<<HT[i].weight<<"\t"<<HT[i].parent<<"\t"<<HT[i].lch<<"\t"<<HT[i].rch<<"\t"<<endl;
    }
}


void displayHuffmanCode(HuffmanCode* HC,int n){
    for(int i=1;i<=n;i++){
        cout<<HC[i]<<endl;
    }
}

int main()
{
    
    // int weight[]={70,50,20,40};
    int weight[]={5,25,3,6,10,11,36,4};
    int n=sizeof(weight)/sizeof(int);
    HuffmanTree* HT=nullptr;
    //HT存储了哈夫曼树
    CreatHuffmanTree(HT,weight,n);
    displayHuffmanTree(HT,n);
    cout<<endl;
    //
    HuffmanCode* HC=nullptr;
    CreatHuffmanCode(HT,HC,n);
    displayHuffmanCode(HC,n);

}   
