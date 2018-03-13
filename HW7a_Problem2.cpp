#include<iostream>
using namespace std;

#define MaxVertexNum 100       // 最大顶点数设为100 
#define INFINITY 2147483647

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

//有向网
MGraph CreateDN(MGraph &G,int nv ,int ne)
{
	Edge E;
	Vertex V, W;
	int k;
	DataType a, b; //记录输入顶点
	WeightType c;

	G->Nv=nv;   // 读入顶点个数 
	G->Ne=ne;   // 读入边数 

	// 初始化邻接矩阵 全部置0
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
		}
	}
	return G;
}

// 邻接矩阵存储 - 有权图的单源最短路算法

Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{ // 返回未被收录顶点中dist最小者
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V<Graph->Nv; V++) {
		if (collected[V] == false && dist[V]<MinDist) {
			// 若V未被收录，且dist[V]更小 
			MinDist = dist[V]; // 更新最小距离 
			MinV = V; //更新对应顶点 
		}
	}
	if (MinDist < INFINITY) //若找到最小dist 
		return MinV; // 返回对应的顶点下标
	else return -1;  // 若这样的顶点不存在，返回错误标记
}

void Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	// 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 
	for (V = 0; V<Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V]<INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	// 先将起点收入集合 
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		// V = 未被收录顶点中dist最小者
		V = FindMinDist(Graph, dist, collected);
		if (V == -1) // 若这样的V不存在 
			break;      // 算法结束
		collected[V] = true;  // 收录V
		for (W = 0; W<Graph->Nv; W++) //对图中的每个顶点W 
									  // 若W是V的邻接点并且未被收录 
			if (collected[W] == false && Graph->G[V][W]<INFINITY) {
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; // 更新dist[W] 
					path[W] = V; // 更新S到W的路径 
				}
			}
	} // while结束
	for (int i = 0; i < Graph->Nv; i++)
		cout << dist[i] << " ";
	cout << endl;
}

int main()
{
	GNode GA;// 图结点（邻接矩阵）
	MGraph G1 = &GA;
	int nv, ne, s;
	cin >> nv >> ne >> s;
	int dis[MaxVertexNum];
	int path[MaxVertexNum];
	G1 = CreateDN(G1,nv,ne);
	Dijkstra(G1,dis,path,s-1);
	return 0;
}