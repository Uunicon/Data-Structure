#include<iostream>
using namespace std;

#define MaxVertexNum 100       // 最大顶点数设为100 

typedef int Vertex;            // 用顶点下标表示顶点,为整型 
typedef int WeightType;        // 边的权值设为整型 
typedef int DataType;         // 顶点存储的数据类型设为字符型 

// 边的定义  
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      // 有向边<V1, V2>  
	WeightType Weight;  // 权重 
};
typedef PtrToENode Edge;
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

//--------队列------------
struct QNode   //队列结点
{
	int Node;
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
	a = s->Node;
	Q_n--;
	delete s;
	return a;
}

//入队
void EnQueue(int x)
{
	QNode *p;
	p = new QNode;
	p->Node = x;
	LQ.rear->next = p;
	LQ.rear = p;
	LQ.rear->next = NULL;
	Q_n++;
}
					
//有向网
LGraph CreateDN(LGraph Graph)
{
	Edge E;
	Vertex V;
	int k;
	PtrToAdjVNode NewNode; //邻接表新建结点
	DataType a, b; //记录输入顶点
	WeightType c;

	cin >> Graph->Nv;   // 读入顶点个数 
	cin >> Graph->Ne;   // 读入边数 

	// 初始化邻接表 表头 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// 读入顶点数据 
	//邻接表
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].Data = V;

	if (Graph->Ne != 0)
	{ // 如果有边 

		E = new ENode; // 建立边结点 

					   // 读入边，格式为"起点 终点 "，插入邻接矩阵
		for (k = 0; k<Graph->Ne; k++)
		{
			cin >> a >> b >> c;
	

			//在 邻接表 内插入结点
			NewNode = new struct AdjVNode;
			NewNode->AdjV = b - 1;
			NewNode->Weight = c;
			if (Graph->G[a-1].FirstEdge == NULL)//若头结点为空
			{
				Graph->G[a - 1].FirstEdge = NewNode;
				NewNode->Next = NULL;
			}
			else
			{
				NewNode->Next = Graph->G[a - 1].FirstEdge;
				Graph->G[a - 1].FirstEdge = NewNode;
			}
		}
	}
	return Graph;
}

// 邻接表存储 - 拓扑排序算法 

void TopSort(LGraph Graph)
{ // 对Graph进行拓扑排序
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
	CreateQueue(Graph->Nv);

	// 初始化Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		Indegree[V] = 0;

	// 遍历图，得到Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; // 对有向边<V, W->AdjV>累计终点的入度

	// 将所有入度为0的顶点入列 
	for (V = 0; V<Graph->Nv; V++)
		if (Indegree[V] == 0)
			EnQueue(V);

	// 下面进入拓扑排序 
	cnt = 0;
	while (LQ.front != LQ.rear) 
	{
		V = DeQueue(); // 弹出一个入度为0的顶点 
		cnt++;
	    // 对V的每个邻接点W->AdjV 
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)// 若删除V使得W->AdjV入度为0 
				EnQueue(W->AdjV); // 则该顶点入列 
	} // while结束

	if (cnt != Graph->Nv)
		cout<<"0"; // 说明图中有回路
	else
		cout << "1";
}

int main()
{
	LGNode GB;
	LGraph G2 = &GB;
	G2 = CreateDN(G2);
	TopSort(G2);
	return 0;
}