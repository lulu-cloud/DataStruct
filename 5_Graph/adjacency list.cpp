#include<iostream>
#include <windows.h>
#include<stack>
#include<queue>
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

void visit(int v){
  cout<<v+1<<endl;
}

//全局数组，标记节点是否访问过
bool visited[MVNum];

void DFS(ALGraph G,int v){
    //访问当前节点
    visit(v);
    visited[v]=true;
    //指向第一个边所连接的结点
    
    ArcNode* p=G.adjlist[v].firstarc;
    while(p!=NULL){
        //w表示与当前结点相连的结点位置
        int w=p->adjvex;
        if(!visited[w]){
            //w未被访问，递归访问
            DFS(G,w);
        }
        //w访问过了，指向下一个连接的结点
        p=p->nextarc;
    }
    return;
}

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


void DFS_2(ALGraph G,int v){
    //非递归遍历
    ArcNode* p=NULL;
    stack<int>s;
    visit(v);
    visited[v]=true;
    s.push(v);
    while(!s.empty()){
        int k=s.top();
        p=G.adjlist[k].firstarc;
        while(p!=NULL&&visited[p->adjvex]){
            p=p->nextarc;
        }
        if(p==NULL){
            //出栈表示当前节点所有的邻接结点都被访问过了
            s.pop();
        }
        else{
            //入栈表示当前邻接点没被访问，就访问它，并且入栈
            visit(p->adjvex);
            visited[p->adjvex]=true;
            s.push(p->adjvex);
        }
    }
}

int FirstAdjVex(ALGraph G,int u){
    return G.adjlist[u].firstarc->adjvex;
}

int NextAdjVex(ALGraph G,int u,int w){
    ArcNode* p=G.adjlist[u].firstarc;
    while(p!=NULL&&p->adjvex!=w){
        p=p->nextarc;
    }
    if(p->nextarc){
        return p->nextarc->adjvex;
    }
    return -1;
}

void BFS (ALGraph G, int v){ 
    //按广度优先非递归遍历连通图G 
    visit(v); visited[v] = true;     		//访问第v个顶点
    queue<int>q;
    q.push(v);  //当前节点进队
    // cout<<v<<endl;
    // visited[v]=true;
    while(!q.empty()){   		//队列非空 
       int u=q.front();
       q.pop();        			//队头元素出队并置为u 
       for(int w = FirstAdjVex(G, u); w>=0; w = NextAdjVex(G, u, w)) {
            if(!visited[w]){               	//w为u的尚未访问的邻接顶点 
                    visit(w); visited[w] = true;	q.push(w); //w进队 
                }//end if end for
        }
    }//end while 
}//end BFS 


int main()
{
    int data[][6]={
        {0,1,1,1,0,0},
        {1,0,0,0,1,0},
        {1,0,0,0,1,0},
        {1,0,0,0,0,1},
        {0,1,1,0,0,0},
        {0,0,0,1,0,0}
  };
  ALGraph G;
  //创建图G
  creatGraph(G,data,6);

  //DFS
//   DFS_2(G,1);

    BFS(G,1);
  return 0;
}