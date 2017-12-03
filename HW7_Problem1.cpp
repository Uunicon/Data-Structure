#include<iostream>
using namespace std;

#define MaxVertexNum 100       // 最大顶点数设为100 

typedef int Vertex;            // 用顶点下标表示顶点,为整型 
typedef int WeightType;        // 边的权值设为整型 
typedef char DataType;         // 顶点存储的数据类型设为字符型 
typedef enum { DG = 1, DN, UDG, UDN } Graphkind;  //{有向图，有向网，无向图，无向网}


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
	Graphkind kind;  //记录图类型
};
typedef PtrToGNode MGraph; // 以邻接矩阵存储的图类型 

//-----图的邻接表储存表示------

// 邻接点的定义 
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;        // 邻接点下标 
	WeightType Weight;  // 边权重 
	PtrToAdjVNode Next;    // 指向下一个邻接点的指针 
};

// 顶点表头结点的定义 
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;  // 边表头指针 
	DataType Data;            // 存顶点的数据 

} AdjList[MaxVertexNum];    // AdjList是邻接表类型

// 图结点的定义（邻接表）
typedef struct LGNode *LPtrToGNode;
struct LGNode {
	int Nv;     // 顶点数 
	int Ne;     // 边数   
	AdjList G;  // 邻接表 
};
typedef LPtrToGNode LGraph; // 以邻接表方式存储的图类型 

//确定顶点在 邻接矩阵 中的下标
int LocateVex(MGraph G, char u)
{
	int i;
	for (i = 0; i < G->Nv; i++)
	{
		if (u == G->Data[i]) return i;
	}
	return 0;
}

void PrintGraph(MGraph &G)
{
	Vertex V, W;
	for (V = 0; V < G->Nv; V++)
		cout << G->Data[V] << " ";
	cout << endl;

	for (V = 0; V < G->Nv; V++)
	{
		for (W = 0; W < G->Nv; W++)
			cout << "   " << G->G[V][W];
		cout << endl;
	}

}

void PrintLGraph(MGraph &G,LGraph &G2)
{
	Vertex V, W;
	PtrToAdjVNode T; //指向邻接表内结点
	for (V = 0; V < G2->Nv; V++)
	{
		cout << G2->G[V].Data << "-->";
		if (G2->G[V].FirstEdge)
		{
			T = G2->G[V].FirstEdge;
			while (T)
			{
				cout << T->AdjV;
				if (G->kind==DN||G->kind==UDN)
					cout << "," << T->Weight;
				cout << " ";
				T = T->Next;
			}

		}
		cout << endl;
	}
}

//有向图
MGraph CreateDG(MGraph &G, LGraph Graph)
{
	Edge E;
	Vertex V,W;
	int k;
	PtrToAdjVNode NewNode; //邻接表新建结点
	DataType a, b; //记录输入顶点
	int i, j;//记录输入顶点的下标

	cin >> G->Nv;   // 读入顶点个数 
	cin >> G->Ne;   // 读入边数 

	Graph->Nv = G->Nv;
	Graph->Ne = G->Ne;
    // 初始化邻接矩阵 全部置0
	// 默认顶点编号从0开始，到(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = 0;

	// 初始化邻接表 表头 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// 读入顶点数据 
	//邻接矩阵
	for (V = 0; V<G->Nv; V++)
		cin >> G->Data[V];
	//邻接表
	for (V = 0; V<Graph->Nv; V++)
		 Graph->G[V].Data = G->Data[V] ;



	if (G->Ne != 0) 
	{ // 如果有边 

		E = new ENode; // 建立边结点  

	    // 读入边，格式为"起点 终点 "，插入邻接矩阵
		for (k = 0; k<G->Ne; k++) 
		{
			cin >> a >> b;  
			i = LocateVex(G, a);
			j = LocateVex(G, b);
            G->G[i][j] = 1;

			//在 邻接表 内插入结点
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			if(Graph->G[i].FirstEdge==NULL)//若头结点为空
			{
				Graph->G[i].FirstEdge = NewNode;
				NewNode->Next = NULL;
			}
			else 
			{
				NewNode->Next = Graph->G[i].FirstEdge;
				Graph->G[i].FirstEdge = NewNode;
			}
		}
	}


	PrintGraph(G);
	PrintLGraph(G,Graph);
	return G;
}

//有向网
MGraph CreateDN(MGraph &G,LGraph Graph)
{
	Edge E;
	Vertex V, W;
	int k;
	PtrToAdjVNode NewNode; //邻接表新建结点
	DataType a, b; //记录输入顶点
	WeightType c;
	int i, j;//记录输入顶点的下标

	cin >> G->Nv;   // 读入顶点个数 
	cin >> G->Ne;   // 读入边数 

	Graph->Nv = G->Nv;
	Graph->Ne = G->Ne;
	// 初始化邻接矩阵 全部置0
	// 默认顶点编号从0开始，到(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = 0;

	// 初始化邻接表 表头 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// 读入顶点数据 
	//邻接矩阵
	for (V = 0; V<G->Nv; V++)
		cin >> G->Data[V];
	//邻接表
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].Data = G->Data[V];

	if (G->Ne != 0)
	{ // 如果有边 

		E = new ENode; // 建立边结点 

					   // 读入边，格式为"起点 终点 "，插入邻接矩阵
		for (k = 0; k<G->Ne; k++)
		{
			cin >> a >> b >> c;
			i = LocateVex(G, a);
			j = LocateVex(G, b);
			G->G[i][j] = c;

			//在 邻接表 内插入结点
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			NewNode->Weight = c;
			if (Graph->G[i].FirstEdge == NULL)//若头结点为空
			{
				Graph->G[i].FirstEdge = NewNode;
				NewNode->Next = NULL;
			}
			else
			{
				NewNode->Next = Graph->G[i].FirstEdge;
				Graph->G[i].FirstEdge = NewNode;
			}
		}
	}
	PrintGraph(G);
	PrintLGraph(G,Graph);
	return G;
}

//无向图
MGraph CreateUDG(MGraph &G,LGraph Graph)
{
	Edge E;
	Vertex V, W;
	int k;
	PtrToAdjVNode NewNode,NewNode1; //邻接表新建结点
	DataType a, b; //记录输入顶点
	int i, j;//记录输入顶点的下标

	cin >> G->Nv;   // 读入顶点个数 
	cin >> G->Ne;   // 读入边数 

	Graph->Nv = G->Nv;
	Graph->Ne = G->Ne;
	// 初始化邻接矩阵 全部置0
	// 默认顶点编号从0开始，到(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = 0;

	// 初始化邻接表 表头 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// 读入顶点数据 
	//邻接矩阵
	for (V = 0; V<G->Nv; V++)
		cin >> G->Data[V];
	//邻接表
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].Data = G->Data[V];


	if (G->Ne != 0)
	{ // 如果有边 

		E = new ENode; // 建立边结点 

					   // 读入边，格式为"起点 终点 "，插入邻接矩阵
		for (k = 0; k<G->Ne; k++)
		{
			cin >> a >> b;
			i = LocateVex(G, a);
			j = LocateVex(G, b);
			G->G[i][j] = 1;
			G->G[j][i] = 1;
			//在 邻接表 内插入结点 V2(b)
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			if (Graph->G[i].FirstEdge == NULL)//若头结点为空
			{
				Graph->G[i].FirstEdge = NewNode;
				NewNode->Next = NULL;
			}
			else
			{
				NewNode->Next = Graph->G[i].FirstEdge;
				Graph->G[i].FirstEdge = NewNode;
			}
			//在 邻接表 内插入结点 V1(a)
			NewNode1 = new struct AdjVNode;
			NewNode1->AdjV = i;
			if (Graph->G[j].FirstEdge == NULL)//若头结点为空
			{
				Graph->G[j].FirstEdge = NewNode1;
				NewNode1->Next = NULL;
			}
			else
			{
				NewNode1->Next = Graph->G[j].FirstEdge;
				Graph->G[j].FirstEdge = NewNode1;
				
			}
		}
	}
	PrintGraph(G);
	PrintLGraph(G,Graph);
	return G;
}

//无向网
MGraph CreateUDN(MGraph &G, LGraph Graph)
{
	Edge E;
	Vertex V, W;
	int k;
	PtrToAdjVNode NewNode, NewNode1; //邻接表新建结点
	DataType a, b; //记录输入顶点
	WeightType c;
	int i, j;//记录输入顶点的下标

	cin >> G->Nv;   // 读入顶点个数 
	cin >> G->Ne;   // 读入边数 

	Graph->Nv = G->Nv;
	Graph->Ne = G->Ne;
	// 初始化邻接矩阵 全部置0
	// 默认顶点编号从0开始，到(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = 0;

	// 初始化邻接表 表头 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// 读入顶点数据 
	//邻接矩阵
	for (V = 0; V<G->Nv; V++)
		cin >> G->Data[V];
	//邻接表
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].Data = G->Data[V];

	if (G->Ne != 0)
	{ // 如果有边 

		E = new ENode; // 建立边结点 

					   // 读入边，格式为"起点 终点 "，插入邻接矩阵
		for (k = 0; k<G->Ne; k++)
		{
			cin >> a >> b >> c;
			i = LocateVex(G, a);
			j = LocateVex(G, b);
			G->G[i][j] = c;
			G->G[j][i] = c;
			//在 邻接表 内插入结点 V2(b)
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			NewNode->Weight = c;
			if (Graph->G[i].FirstEdge == NULL)//若头结点为空
			{
				Graph->G[i].FirstEdge = NewNode;
				NewNode->Next = NULL;
			}
			else
			{
				NewNode->Next = Graph->G[i].FirstEdge;
				Graph->G[i].FirstEdge = NewNode;
				
			}
			//在 邻接表 内插入结点 V1(a)
			NewNode1 = new struct AdjVNode;
			NewNode1->AdjV = i;
			NewNode1->Weight = c;
			if (Graph->G[j].FirstEdge == NULL)//若头结点为空
			{
				Graph->G[j].FirstEdge = NewNode1;
				NewNode1->Next = NULL;
			}
			else
			{
				NewNode1->Next = Graph->G[j].FirstEdge;
				Graph->G[j].FirstEdge = NewNode1;
				
			}
		}
	}
	PrintGraph(G);
	PrintLGraph(G,Graph);
	return G;
}

//采用 邻接矩阵,邻接表 构造图
MGraph CreatGraph(MGraph &G,LGraph &G2)
{
	int n;
	cin >> n;
	G->kind = (Graphkind)n;
	switch (G->kind)
	{
	case  DG:return CreateDG(G,G2); break;
	case  DN:return CreateDN(G,G2); break;
	case UDG:return CreateUDG(G,G2); break;
	case UDN:return CreateUDN(G,G2); break;
	}
}



int main()
{
	GNode GA;// 图结点（邻接矩阵）
	LGNode GB;
	MGraph G1 = &GA;
	LGraph G2 = &GB;
	G1 = CreatGraph(G1,G2);

	return 0;
}





