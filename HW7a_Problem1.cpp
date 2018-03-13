#include<iostream>
using namespace std;

#define MaxVertexNum 100       // 最大顶点数设为100 
#define INFINITY 65535         //图不联通边为无穷大

typedef int Vertex;            // 用顶点下标表示顶点,为整型 
typedef int WeightType;        // 边的权值设为整型 
typedef int DataType;         // 顶点存储的数据类型设为字符型 


//-----图的邻接矩阵储存表示------

// 边的定义  
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      // 有向边<V1, V2>  或 无向边 （V1，V2）
	WeightType Weight;  // 权重 
};
typedef PtrToENode Edge;

// 图结点的定义（邻接矩阵）
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  // 顶点数
	int Ne;  // 边数   
	WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵 
	DataType Data[MaxVertexNum];      // 存顶点的数据 
};
typedef PtrToGNode MGraph; // 以邻接矩阵存储的图类型 


//无向网
MGraph CreateUDN(MGraph &G)
{
	Edge E;
	Vertex V, W;
	int k;
	DataType a, b; //记录输入顶点
	WeightType c;

	cin >> G->Nv;   // 读入顶点个数 
	cin >> G->Ne;   // 读入边数 

	// 初始化邻接矩阵 全部置infinity
	// 默认顶点编号从0开始，到(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = INFINITY;

	// 读入顶点数据 
	//邻接矩阵
	for (V = 0; V<G->Nv; V++)
		G->Data[V]= V + 1;

	if (G->Ne != 0)
	{ // 如果有边 

		E = new ENode; // 建立边结点 

					   // 读入边，格式为"起点 终点 "，插入邻接矩阵
		for (k = 0; k<G->Ne; k++)
		{
			cin >> a >> b >> c;
			G->G[a-1][b-1] = c;
			G->G[b-1][a-1] = c;
		}
	}
	return G;
}

void MiniSpanTree_PRIM(MGraph &G)
{
	struct {
		Vertex adjvex;
		WeightType lowest;
	}closedge[MaxVertexNum];
	int i,j,k,V;
	int total=0;
	//默认下标=0的点为第一个点 对应数值为1
	for (j = 0; j < G->Nv; j++)  //辅助数组初始化
		closedge[j] = { G->Data[0],G->G[0][j]};
	closedge[0].lowest = 0;  //初始U = {u}

	for (i = 1; i < G->Nv; i++)
	{
		int min = INFINITY;
		for (k = 0; k < G->Nv; k++)
			if (closedge[k].lowest > 0 && closedge[k].lowest < min)
			{
				min = closedge[k].lowest;
				V = k; //记最小值下标
			}
		total = total + min;
		closedge[V].lowest = 0;
		for (j = 0; j < G->Nv; j++)
			if (G->G[V][j] < closedge[j].lowest)
				closedge[j] = { G->Data[V],G->G[V][j] };
	}
	if (total >= INFINITY) total = -1;
	cout << total << endl;
}

int main()
{
	GNode GA;// 图结点（邻接矩阵）;
	MGraph G1 = &GA;
	G1 = CreateUDN(G1);
	MiniSpanTree_PRIM(G1);
	return 0;
}
