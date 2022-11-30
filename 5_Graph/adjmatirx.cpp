#include<iostream>
#include <windows.h>
using namespace std;


//用两个数组分别存储顶点表和邻接矩阵
#define MaxInt 32767                    	//表示极大值，即∞
#define MVNum 100                       	//最大顶点数 
typedef int VerTexType;              	//假设顶点的数据类型为int型 
typedef int ArcType;                  	//假设边的权值类型为整型 

typedef struct{
  VerTexType vexs[MVNum];            		//顶点表 
  ArcType arcs[MVNum][MVNum];      	//邻接矩阵 
  int vexnum,arcnum;                		//图的当前点数和边数 
}AMGraph; 



void visit(int v){
  cout<<v+1<<endl;
}

//全局数组，标记节点是否访问过
bool visited[MVNum];

void DFS(AMGraph G,int v){
  //访问当前节点，并将visited数组相应的位置置为1
  visit(v);
  visited[v]=true;
  for(int w=0;w<G.vexnum;w++){
    //如果遍历到的w结点与v结点存在边，并且没有被访问过，就递归访问它
    if(G.arcs[v][w]!=0&&!visited[w]){
      DFS(G,w);
    }
  }
}

bool fun(AMGraph G,int v,int w){
  DFS(G,1);
  if(visited[w]){
    return true;
  }
  return false;
  // for(int i=0;i<G.vexnum;i++){
  //   if(visited[i]==false){
  //     return false;
  //   }
  // }
  // return true;
}

void creatGraph(AMGraph &G,int data[][6],int n){
  G.vexnum=n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){     
      G.arcs[i][j]=data[i][j];
      if(data[i][j]!=0){
        G.arcnum++;
      }
    }
    G.vexs[i]=i;
  }
  G.arcnum/=2;
}

int main()
{
  // int arcs[MVNum][MVNum];
  int data[][6]={
    {0,1,1,1,0,0},
    {1,0,0,0,1,0},
    {1,0,0,0,1,0},
    {1,0,0,0,0,1},
    {0,1,1,0,0,0},
    {0,0,0,1,0,0}
  };
  AMGraph G;
  //创建图G
  creatGraph(G,data,6);



  //DFS
  DFS(G,1);
  // for(int i=0;i<G.vexnum;i++){
  //   if(visited[i]==false){
  //     return false;
  //   }
  // }
  // return true;
  return 0;


}