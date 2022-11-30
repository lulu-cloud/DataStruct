#include<iostream>
#include <windows.h>
#include<stack>
using namespace std;

typedef int VerTexType;
typedef int OtherInfo;

#define MVNum 100                        	//最大顶点数 

typedef struct ArcNode{                		//边结点 
    int adjvex;                          		//该边所指向的顶点的位置 
    struct ArcNode * nextarc;         	//指向下一条边的指针 
    OtherInfo info;                      	              //和边相关的信息 
}ArcNode; 

typedef struct VNode{ 
    VerTexType data;                    	//顶点信息 
    ArcNode* firstarc;                	//指向第一条依附该顶点的边的指针 
}VNode, AdjList[MVNum];             	//AdjList表示邻接表类型 

typedef struct{ 
    AdjList adjlist;                 		//邻接表 
    int vexnum, arcnum;              		//图的当前顶点数和边数 
}ALGraph; 

void creatGraph(ALGraph &G,int data[][6],int n){
    G.vexnum=n;
    //建立顶点表
    for(int i=0;i<n;i++){
        G.adjlist[i].data=i;
        G.adjlist[i].firstarc=NULL;
    }
    //建立边表
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(data[i][j]!=0){
                G.arcnum++;
                //装填node
                ArcNode* node=new ArcNode;
                node->adjvex=j;
                // node->nextarc=NULL;
                //头插法
                node->nextarc=G.adjlist[i].firstarc;
                G.adjlist[i].firstarc=node;
                
                // //对称插入
                // node->nextarc=G.adjlist[j].firstarc;
                // G.adjlist[j].firstarc=node;
            }
        }
    }
    G.arcnum/=2;
}



bool TopologicalSort(ALGraph G,int indegree[]){ 
    stack<int>s;     		
    for(int i=0;i<G.vexnum;i++){
        if(indegree[i]==0){
            s.push(i);
        }
     }
    int count=0;
    while(!s.empty()){
        int i=s.top();
        s.pop();
        cout<<i<<endl;
        count++;
        for(ArcNode* p=G.adjlist[i].firstarc;p;p=p->nextarc){
            int v=p->adjvex;
            if(!(--indegree[v])){
                s.push(v);
            }//end if		
	    }//end for
    }//end while
    if(count<G.vexnum){ 
        return false;
    }
    return true;              			
}//end 

void creat_indegree(int data[][6],int len,int indegree[]){
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(data[i][j]!=0){
                indegree[j]++;
            }
        }
    }
}

int main()
{
    int data[][6]={
        {0,0,1,0,1,1},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,0,1},
        {0,0,0,1,0,1},
        {0,0,0,0,0,0}
    };
    ALGraph G;
    //创建图G
    creatGraph(G,data,6);
    int indegree[]={0,0,0,0,0,0};
    creat_indegree(data,6,indegree);
    if(TopologicalSort(G,indegree)){
        cout<<"拓扑排序成功"<<endl;
    }
    else{
        cout<<"拓扑排序失败"<<endl;
    }
    return 0;
}