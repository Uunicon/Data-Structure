#include<iostream>
using namespace std;
#define MaxVertexNum 100       // ��󶥵�����Ϊ100 
//--------����------------
struct QNode   //���н��
{
	int data;
	struct QNode *next;
};
struct QPtr   //����ͷ��βָ��
{
	QNode *front;
	QNode *rear;
}LQ;
int Q_n;
//��������
void CreateQueue(int n)
{
	QNode *L;
	LQ.front = new QNode;
	LQ.front->next = NULL;
	L = LQ.rear = LQ.front;
	Q_n = 0;

}//CreateQueue

 //����
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

//���
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
//-----ͼ���ڽӾ��󴢴��ʾ------


typedef int Vertex;            // �ö����±��ʾ����,Ϊ���� 
typedef int WeightType;        // �ߵ�Ȩֵ��Ϊ���� 
typedef int DataType;         // ����洢������������Ϊ���� 

// �ߵĶ���  
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      // �����<V1, V2>  �� ����� ��V1��V2��
};
typedef PtrToENode Edge;


// ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  // ������
	int Ne;  // ����   
	WeightType G[MaxVertexNum][MaxVertexNum]; // �ڽӾ��� 
	DataType Data[MaxVertexNum];      // �涥�������
	bool visited[MaxVertexNum];     //�涥���Ƿ񱻷��ʹ�
};
typedef PtrToGNode MGraph; // ���ڽӾ���洢��ͼ���� 


//����ͼ
MGraph CreateUDG(MGraph &G)
{
	Edge E;
	Vertex V, W;
	int k;
	int i, j;//��¼���붥����±�

	cin >> G->Nv;   // ���붥����� 
	cin >> G->Ne;   // ������� 

					// ��ʼ������ͼ ȫ����0
					// Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) 
	for (V = 0; V<=G->Nv; V++)
		for (W = 0; W<=G->Nv; W++)
			G->G[V][W] = 0;

	// ���붥������ 
	for (V = 0; V<G->Nv; V++)
		G->Data[V]=V;//�������ݳ�ʼ��Ϊ��Ӧ�±�
	for (V = 0; V < G->Nv; V++)
		G->visited[V] = false; //��ʼ����������Ϊδ����

	if (G->Ne != 0)
	{ // ����б� 
		E = new ENode; // �����߽�� 
      // ����ߣ���ʽΪ"��� �յ� "�������ڽӾ���
		for (k = 0; k<G->Ne; k++)
		{
			cin >> i >> j;
			G->G[i][j] = 1;
			G->G[j][i] = 1;
		}
	}
	return G;
}

//�����ڽӾ�����ͼ
MGraph CreatGraph(MGraph &G)
{
	return CreateUDG(G); 
}


// �ڽӾ���洢��ͼ - BFS
// IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣 
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W]!= 0 ? true : false;
}


void BFS(MGraph Graph,int x)
{   // ��SΪ��������ڽӾ���洢��ͼGraph����BFS����
	Vertex V, W;
	int i, j ,m;
    CreateQueue(MaxVertexNum); // �����ն���
		
	for(i=x;i<Graph->Nv;i++)  //�ҵ���һ�����
	{
		for (j = 0; j < Graph->Nv; j++)
			if (Graph->G[i][j] == 1)
				break;
		if (j <= Graph->Nv)break;
	}
	m = i;//�ǵ�һ�������±�
	EnQueue(x);
	Graph->visited[x] = true;
	cout << "{" << x;
	while (LQ.front != LQ.rear)
	{  //���в�Ϊ��
		V = DeQueue();  // ����V 
		for (W = i; W<Graph->Nv; W++) // ��ͼ�е�ÿ������W 
										  // ��W��V���ڽӵ㲢��δ���ʹ� 
		if (!Graph->visited[W] && IsEdge(Graph, V, W))
		{
			// ���ʶ���W 
			cout << " " << W;
			Graph->visited[W] = true; // ���W�ѷ��� 
			EnQueue(W); // W����� 
		}
		
	} // ���в�Ϊ��
		
	
}
// �ڽӾ���洢��ͼ - DFS
void DFS(MGraph Graph,int x,int n) //n�ǵݹ����
{
	int i,j;
	if (x == 0)//��x=0
	{
		for (i = 0; i<Graph->Nv; i++)  //�ҵ���һ�����
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
		G1->visited[V] = false; //��ʼ����������Ϊδ����
	ListComponents_BFS(G1);
	return 0;
}