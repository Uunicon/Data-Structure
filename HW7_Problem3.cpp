#include<iostream>
using namespace std;

#define MaxVertexNum 100       // ��󶥵�����Ϊ100 

typedef int Vertex;            // �ö����±��ʾ����,Ϊ���� 
typedef int WeightType;        // �ߵ�Ȩֵ��Ϊ���� 
typedef int DataType;         // ����洢������������Ϊ���� 

							  //--------����------------
struct QNode   //���н��
{
	int Node;
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
	a = s->Node;
	Q_n--;
	delete s;
	return a;
}

//���
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
//-------------�ڽӱ�-------

// �ڽӵ�Ķ��� 
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;        // �ڽӵ��±� 
	PtrToAdjVNode Next;    // ָ����һ���ڽӵ��ָ�� 
};

// �����ͷ���Ķ��� 
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;  // �߱�ͷָ�� 
	DataType Data;            // �涥������� 
	bool visited;

} AdjList[MaxVertexNum];    // AdjList���ڽӱ�����

// ͼ���Ķ��壨�ڽӱ�
typedef struct LGNode *LPtrToGNode;
struct LGNode {
	int Nv;     // ������ 
	int Ne;     // ����   
	AdjList G;  // �ڽӱ� 
};
typedef LPtrToGNode LGraph; // ���ڽӱ�ʽ�洢��ͼ���� 


//����ͼ
LGraph CreateUDG(LGraph G)
{
	Vertex V, W;
	int k;
	PtrToAdjVNode NewNode, NewNode1; //�ڽӱ��½����
	int i, j;//��¼���붥����±�

	cin >> G->Nv;   // ���붥����� 
	cin >> G->Ne;   // ������� 

	// ��ʼ���ڽӱ� ��ͷ 
	for (V = 0; V<G->Nv; V++)
	{
		G->G[V].FirstEdge = NULL;
		G->G[V].visited = false;
	}
		

	// ���붥������ 
	//�ڽӱ�
	for (V = 0; V<G->Nv; V++)
		G->G[V].Data = V;

	if (G->Ne != 0)
	{ // ����б� 

	   // ����ߣ���ʽΪ"��� �յ� "�������ڽӱ�
		for (k = 0; k<G->Ne; k++)
		{
			cin >> i >> j;
			//�� �ڽӱ� �ڲ����� V2(b)
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			if (G->G[i].FirstEdge == NULL)//��ͷ���Ϊ��
			{
				G->G[i].FirstEdge = NewNode;
				NewNode->Next = NULL;
			}
			else
			{
				NewNode->Next = G->G[i].FirstEdge;
				G->G[i].FirstEdge = NewNode;
			}
			//�� �ڽӱ� �ڲ����� V1(a)
			NewNode1 = new struct AdjVNode;
			NewNode1->AdjV = i;
			if (G->G[j].FirstEdge == NULL)//��ͷ���Ϊ��
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

// �ڽӱ�洢��ͼ - DFS
void DFS(LGraph Graph, Vertex V, int n) //n�ǵݹ����
{
	PtrToAdjVNode W;
	if (n == 0)
		cout << "{";
	else
		cout << " ";
	Graph->G[V].visited = true;
	cout << Graph->G[V].Data;
	for (W = Graph->G[V].FirstEdge; W; W = W->Next) // ��V��ÿ���ڽӵ�W->AdjV 
		if (!Graph->G[W->AdjV].visited)    // ��W->AdjVδ������ 
			DFS(Graph, W->AdjV, n+1);    //��ݹ����
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

//�ڽӱ�洢��ͼ - BFS

void BFS(LGraph G, int x)
{
	PtrToAdjVNode W;
	CreateQueue(MaxVertexNum);
	EnQueue(x);
	G->G[x].visited = true;
	cout << "{" << x;
	while (LQ.front != LQ.rear)
	{  //���в�Ϊ��
		x = DeQueue();  // ����V 
		for (W = G->G[x].FirstEdge; W; W = W->Next) // ��V��ÿ���ڽӵ�W->AdjV 
           // ��W��V���ڽӵ㲢��δ���ʹ� 
			if (!G->G[W->AdjV].visited)    // ��W->AdjVδ������ 
			{
				// ���ʶ���W 
				cout << " " << W->AdjV;
				G->G[W->AdjV].visited = true; // ���W�ѷ��� 
				EnQueue(W->AdjV); // W����� 
			}
	} // ���в�Ϊ��
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
		G2->G[V].visited = false; //��ʼ����������Ϊδ����
	cout << endl;
	ListComponents_BFS(G2);
	return 0;
}
