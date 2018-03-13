#include<iostream>
using namespace std;

#define MaxVertexNum 100       // ��󶥵�����Ϊ100 

typedef int Vertex;            // �ö����±��ʾ����,Ϊ���� 
typedef int WeightType;        // �ߵ�Ȩֵ��Ϊ���� 
typedef int DataType;         // ����洢������������Ϊ�ַ��� 

// �ߵĶ���  
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      // �����<V1, V2>  
	WeightType Weight;  // Ȩ�� 
};
typedef PtrToENode Edge;
//-----ͼ���ڽӱ����ʾ------

 // �ڽӵ�Ķ��� 
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;        // �ڽӵ��±� 
	WeightType Weight;  // ��Ȩ��
	PtrToAdjVNode Next;    // ָ����һ���ڽӵ��ָ�� 
};

// �����ͷ���Ķ��� 
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;  // �߱�ͷָ�� 
	DataType Data;            // �涥������� 

} AdjList[MaxVertexNum];    // AdjList���ڽӱ�����

// ͼ���Ķ��壨�ڽӱ�
typedef struct LGNode *LPtrToGNode;
struct LGNode {
	int Nv;     // ������ 
	int Ne;     // ����   
	AdjList G;  // �ڽӱ� 
};
typedef LPtrToGNode LGraph; // ���ڽӱ�ʽ�洢��ͼ���� 

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
					
//������
LGraph CreateDN(LGraph Graph)
{
	Edge E;
	Vertex V;
	int k;
	PtrToAdjVNode NewNode; //�ڽӱ��½����
	DataType a, b; //��¼���붥��
	WeightType c;

	cin >> Graph->Nv;   // ���붥����� 
	cin >> Graph->Ne;   // ������� 

	// ��ʼ���ڽӱ� ��ͷ 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// ���붥������ 
	//�ڽӱ�
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].Data = V;

	if (Graph->Ne != 0)
	{ // ����б� 

		E = new ENode; // �����߽�� 

					   // ����ߣ���ʽΪ"��� �յ� "�������ڽӾ���
		for (k = 0; k<Graph->Ne; k++)
		{
			cin >> a >> b >> c;
	

			//�� �ڽӱ� �ڲ�����
			NewNode = new struct AdjVNode;
			NewNode->AdjV = b - 1;
			NewNode->Weight = c;
			if (Graph->G[a-1].FirstEdge == NULL)//��ͷ���Ϊ��
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

// �ڽӱ�洢 - ���������㷨 

void TopSort(LGraph Graph)
{ // ��Graph������������
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
	CreateQueue(Graph->Nv);

	// ��ʼ��Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		Indegree[V] = 0;

	// ����ͼ���õ�Indegree[] 
	for (V = 0; V<Graph->Nv; V++)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++; // �������<V, W->AdjV>�ۼ��յ�����

	// ���������Ϊ0�Ķ������� 
	for (V = 0; V<Graph->Nv; V++)
		if (Indegree[V] == 0)
			EnQueue(V);

	// ��������������� 
	cnt = 0;
	while (LQ.front != LQ.rear) 
	{
		V = DeQueue(); // ����һ�����Ϊ0�Ķ��� 
		cnt++;
	    // ��V��ÿ���ڽӵ�W->AdjV 
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)// ��ɾ��Vʹ��W->AdjV���Ϊ0 
				EnQueue(W->AdjV); // ��ö������� 
	} // while����

	if (cnt != Graph->Nv)
		cout<<"0"; // ˵��ͼ���л�·
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