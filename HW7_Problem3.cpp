#include<iostream>
using namespace std;

#define MaxVertexNum 100       // 最大顶点数设为100 

typedef int Vertex;            // 用顶点下标表示顶点,为整型 
typedef int WeightType;        // 边的权值设为整型 
typedef int DataType;         // 顶点存储的数据类型设为整型 

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
//-------------邻接表-------

// 邻接点的定义 
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;        // 邻接点下标 
	PtrToAdjVNode Next;    // 指向下一个邻接点的指针 
};

// 顶点表头结点的定义 
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;  // 边表头指针 
	DataType Data;            // 存顶点的数据 
	bool visited;

} AdjList[MaxVertexNum];    // AdjList是邻接表类型

// 图结点的定义（邻接表）
typedef struct LGNode *LPtrToGNode;
struct LGNode {
	int Nv;     // 顶点数 
	int Ne;     // 边数   
	AdjList G;  // 邻接表 
};
typedef LPtrToGNode LGraph; // 以邻接表方式存储的图类型 


//无向图
LGraph CreateUDG(LGraph G)
{
	Vertex V, W;
	int k;
	PtrToAdjVNode NewNode, NewNode1; //邻接表新建结点
	int i, j;//记录输入顶点的下标

	cin >> G->Nv;   // 读入顶点个数 
	cin >> G->Ne;   // 读入边数 

	// 初始化邻接表 表头 
	for (V = 0; V<G->Nv; V++)
	{
		G->G[V].FirstEdge = NULL;
		G->G[V].visited = false;
	}
		

	// 读入顶点数据 
	//邻接表
	for (V = 0; V<G->Nv; V++)
		G->G[V].Data = V;

	if (G->Ne != 0)
	{ // 如果有边 

	   // 读入边，格式为"起点 终点 "，插入邻接表
		for (k = 0; k<G->Ne; k++)
		{
			cin >> i >> j;
			//在 邻接表 内插入结点 V2(b)
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			if (G->G[i].FirstEdge == NULL)//若头结点为空
			{
				G->G[i].FirstEdge = NewNode;
				NewNode->Next = NULL;
			}
			else
			{
				NewNode->Next = G->G[i].FirstEdge;
				G->G[i].FirstEdge = NewNode;
			}
			//在 邻接表 内插入结点 V1(a)
			NewNode1 = new struct AdjVNode;
			NewNode1->AdjV = i;
			if (G->G[j].FirstEdge == NULL)//若头结点为空
			{
				G->G[j].FirstEdge = NewNode1;
				NewNode1->Next = NULL;
			}
			else
			{
				NewNode1->Next = G->G[j].FirstEdge;
				G->G[j].FirstEdge = NewNode1;

			}
		}
	}
	return G;
}

// 邻接表存储的图 - DFS
void DFS(LGraph Graph, Vertex V, int n) //n记递归次数
{
	PtrToAdjVNode W;
	if (n == 0)
		cout << "{";
	else
		cout << " ";
	Graph->G[V].visited = true;
	cout << Graph->G[V].Data;
	for (W = Graph->G[V].FirstEdge; W; W = W->Next) // 对V的每个邻接点W->AdjV 
		if (!Graph->G[W->AdjV].visited)    // 若W->AdjV未被访问 
			DFS(Graph, W->AdjV, n+1);    //则递归访问
}

void ListComponents_DFS(LGraph &G)
{
	int i;
	for (i = 0; i<G->Nv; i++)
		if (!G->G[i].visited)
		{
			DFS(G, i, 0);
			cout << "}";
		}
}

//邻接表存储的图 - BFS

void BFS(LGraph G, int x)
{
	PtrToAdjVNode W;
	CreateQueue(MaxVertexNum);
	EnQueue(x);
	G->G[x].visited = true;
	cout << "{" << x;
	while (LQ.front != LQ.rear)
	{  //队列不为空
		x = DeQueue();  // 弹出V 
		for (W = G->G[x].FirstEdge; W; W = W->Next) // 对V的每个邻接点W->AdjV 
           // 若W是V的邻接点并且未访问过 
			if (!G->G[W->AdjV].visited)    // 若W->AdjV未被访问 
			{
				// 访问顶点W 
				cout << " " << W->AdjV;
				G->G[W->AdjV].visited = true; // 标记W已访问 
				EnQueue(W->AdjV); // W入队列 
			}
	} // 队列不为空
}

void ListComponents_BFS(LGraph &G)
{
	int i;
	for (i = 0; i<G->Nv; i++)
		if (!G->G[i].visited)
		{
			BFS(G, i);
			cout << "}";
		}
}


int main()
{
	LGNode GB;
	LGraph G2 = &GB;
	G2 = CreateUDG(G2);
	ListComponents_DFS(G2);
	for (int V = 0; V <= G2->Nv; V++)
		G2->G[V].visited = false; //初始化访问数组为未访问
	cout << endl;
	ListComponents_BFS(G2);
	return 0;
}
