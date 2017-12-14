#include<iostream>
using namespace std;
#define MaxVertexNum 100       // 最大顶点数设为100 
//--------队列------------
struct QNode   //队列结点
{
	int data;
	struct QNode *next;
};
struct QPtr   //队列头、尾指针
{
	QNode *front;
	QNode *rear;
}LQ;
int Q_n;
//建立队列
void CreateQueue(int n)
{
	QNode *L;
	LQ.front = new QNode;
	LQ.front->next = NULL;
	L = LQ.rear = LQ.front;
	Q_n = 0;

}//CreateQueue

 //出队
int DeQueue()
{
	QNode *s;
	int a;
	s = LQ.front->next;
	if (Q_n == 1)
		LQ.rear = LQ.front;
	else
		LQ.front->next = LQ.front->next->next;
	a=s->data;
	Q_n--;
	delete s;
	return a;
}

//入队
void EnQueue(int x)
{
	QNode *p;
	p = new QNode;
	p->data = x;
	LQ.rear->next = p;
	LQ.rear = p;
	LQ.rear->next = NULL;
	Q_n++;

}
//-----图的邻接矩阵储存表示------


typedef int Vertex;            // 用顶点下标表示顶点,为整型 
typedef int WeightType;        // 边的权值设为整型 
typedef int DataType;         // 顶点存储的数据类型设为整型 

// 边的定义  
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      // 有向边<V1, V2>  或 无向边 （V1，V2）
};
typedef PtrToENode Edge;


// 图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  // 顶点数
	int Ne;  // 边数   
	WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵 
	DataType Data[MaxVertexNum];      // 存顶点的数据
	bool visited[MaxVertexNum];     //存顶点是否被访问过
};
typedef PtrToGNode MGraph; // 以邻接矩阵存储的图类型 


//无向图
MGraph CreateUDG(MGraph &G)
{
	Edge E;
	Vertex V, W;
	int k;
	int i, j;//记录输入顶点的下标

	cin >> G->Nv;   // 读入顶点个数 
	cin >> G->Ne;   // 读入边数 

					// 初始化无向图 全部置0
					// 默认顶点编号从0开始，到(Graph->Nv - 1) 
	for (V = 0; V<=G->Nv; V++)
		for (W = 0; W<=G->Nv; W++)
			G->G[V][W] = 0;

	// 读入顶点数据 
	for (V = 0; V<G->Nv; V++)
		G->Data[V]=V;//顶点数据初始化为对应下标
	for (V = 0; V < G->Nv; V++)
		G->visited[V] = false; //初始化访问数组为未访问

	if (G->Ne != 0)
	{ // 如果有边 
		E = new ENode; // 建立边结点 
      // 读入边，格式为"起点 终点 "，插入邻接矩阵
		for (k = 0; k<G->Ne; k++)
		{
			cin >> i >> j;
			G->G[i][j] = 1;
			G->G[j][i] = 1;
		}
	}
	return G;
}

//采用邻接矩阵构造图
MGraph CreatGraph(MGraph &G)
{
	return CreateUDG(G); 
}


// 邻接矩阵存储的图 - BFS
// IsEdge(Graph, V, W)检查<V, W>是否图Graph中的一条边，即W是否V的邻接点。 
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W]!= 0 ? true : false;
}


void BFS(MGraph Graph,int x)
{   // 以S为出发点对邻接矩阵存储的图Graph进行BFS搜索
	Vertex V, W;
	int i, j ,m;
    CreateQueue(MaxVertexNum); // 创建空队列
		
	for(i=x;i<Graph->Nv;i++)  //找到第一个结点
	{
		for (j = 0; j < Graph->Nv; j++)
			if (Graph->G[i][j] == 1)
				break;
		if (j <= Graph->Nv)break;
	}
	m = i;//记第一个顶点下标
	EnQueue(x);
	Graph->visited[x] = true;
	cout << "{" << x;
	while (LQ.front != LQ.rear)
	{  //队列不为空
		V = DeQueue();  // 弹出V 
		for (W = i; W<Graph->Nv; W++) // 对图中的每个顶点W 
										  // 若W是V的邻接点并且未访问过 
		if (!Graph->visited[W] && IsEdge(Graph, V, W))
		{
			// 访问顶点W 
			cout << " " << W;
			Graph->visited[W] = true; // 标记W已访问 
			EnQueue(W); // W入队列 
		}
		
	} // 队列不为空
		
	
}
// 邻接矩阵存储的图 - DFS
void DFS(MGraph Graph,int x,int n) //n记递归次数
{
	int i,j;
	if (x == 0)//若x=0
	{
		for (i = 0; i<Graph->Nv; i++)  //找到第一个结点
		{
			for (j = 0; j < Graph->Nv; j++)
				if (Graph->G[i][j] == 1)
					break;
			if (j <= Graph->Nv)break;
		}
		x = i;
	}
	if (n == 0)
		cout << "{";
	else
		cout << " ";
	Graph->visited[x] = true;
	cout << x;
	for (j = 0; j < Graph->Nv; j++)
	{
		if (Graph->G[x][j] == 1 && !Graph->visited[j])
			DFS(Graph, j, n+1);
	}
}

void ListComponents_DFS(MGraph &G)
{
	int i;
    for(i = 0; i<G->Nv; i++)
		if (!G->visited[i])
		{
			DFS(G, i, 0);
			cout << "}";
		}
}

void ListComponents_BFS(MGraph &G)
{
	int i;
	for (i = 0; i<G->Nv; i++)
		if (!G->visited[i])
		{
			BFS(G, i);
			cout << "}";
		}
}

int main()
{
	int V;
	GNode G;
	MGraph G1 = &G;
	G1 = CreatGraph(G1);
	ListComponents_DFS(G1);
	cout << endl;
	for (V = 0; V <= G1->Nv; V++)
		G1->visited[V] = false; //初始化访问数组为未访问
	ListComponents_BFS(G1);
	return 0;
}