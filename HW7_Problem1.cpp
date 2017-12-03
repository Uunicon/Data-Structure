#include<iostream>
using namespace std;

#define MaxVertexNum 100       // ��󶥵�����Ϊ100 

typedef int Vertex;            // �ö����±��ʾ����,Ϊ���� 
typedef int WeightType;        // �ߵ�Ȩֵ��Ϊ���� 
typedef char DataType;         // ����洢������������Ϊ�ַ��� 
typedef enum { DG = 1, DN, UDG, UDN } Graphkind;  //{����ͼ��������������ͼ��������}


//-----ͼ���ڽӾ��󴢴��ʾ------

// �ߵĶ���  
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      // �����<V1, V2>  �� ����� ��V1��V2��
	WeightType Weight;  // Ȩ�� 
};
typedef PtrToENode Edge;

// ͼ���Ķ��壨�ڽӾ���
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  // ������
	int Ne;  // ����   
	WeightType G[MaxVertexNum][MaxVertexNum]; // �ڽӾ��� 
	DataType Data[MaxVertexNum];      // �涥������� 
	Graphkind kind;  //��¼ͼ����
};
typedef PtrToGNode MGraph; // ���ڽӾ���洢��ͼ���� 

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

//ȷ�������� �ڽӾ��� �е��±�
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
	PtrToAdjVNode T; //ָ���ڽӱ��ڽ��
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

//����ͼ
MGraph CreateDG(MGraph &G, LGraph Graph)
{
	Edge E;
	Vertex V,W;
	int k;
	PtrToAdjVNode NewNode; //�ڽӱ��½����
	DataType a, b; //��¼���붥��
	int i, j;//��¼���붥����±�

	cin >> G->Nv;   // ���붥����� 
	cin >> G->Ne;   // ������� 

	Graph->Nv = G->Nv;
	Graph->Ne = G->Ne;
    // ��ʼ���ڽӾ��� ȫ����0
	// Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = 0;

	// ��ʼ���ڽӱ� ��ͷ 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// ���붥������ 
	//�ڽӾ���
	for (V = 0; V<G->Nv; V++)
		cin >> G->Data[V];
	//�ڽӱ�
	for (V = 0; V<Graph->Nv; V++)
		 Graph->G[V].Data = G->Data[V] ;



	if (G->Ne != 0) 
	{ // ����б� 

		E = new ENode; // �����߽��  

	    // ����ߣ���ʽΪ"��� �յ� "�������ڽӾ���
		for (k = 0; k<G->Ne; k++) 
		{
			cin >> a >> b;  
			i = LocateVex(G, a);
			j = LocateVex(G, b);
            G->G[i][j] = 1;

			//�� �ڽӱ� �ڲ�����
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			if(Graph->G[i].FirstEdge==NULL)//��ͷ���Ϊ��
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

//������
MGraph CreateDN(MGraph &G,LGraph Graph)
{
	Edge E;
	Vertex V, W;
	int k;
	PtrToAdjVNode NewNode; //�ڽӱ��½����
	DataType a, b; //��¼���붥��
	WeightType c;
	int i, j;//��¼���붥����±�

	cin >> G->Nv;   // ���붥����� 
	cin >> G->Ne;   // ������� 

	Graph->Nv = G->Nv;
	Graph->Ne = G->Ne;
	// ��ʼ���ڽӾ��� ȫ����0
	// Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = 0;

	// ��ʼ���ڽӱ� ��ͷ 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// ���붥������ 
	//�ڽӾ���
	for (V = 0; V<G->Nv; V++)
		cin >> G->Data[V];
	//�ڽӱ�
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].Data = G->Data[V];

	if (G->Ne != 0)
	{ // ����б� 

		E = new ENode; // �����߽�� 

					   // ����ߣ���ʽΪ"��� �յ� "�������ڽӾ���
		for (k = 0; k<G->Ne; k++)
		{
			cin >> a >> b >> c;
			i = LocateVex(G, a);
			j = LocateVex(G, b);
			G->G[i][j] = c;

			//�� �ڽӱ� �ڲ�����
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			NewNode->Weight = c;
			if (Graph->G[i].FirstEdge == NULL)//��ͷ���Ϊ��
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

//����ͼ
MGraph CreateUDG(MGraph &G,LGraph Graph)
{
	Edge E;
	Vertex V, W;
	int k;
	PtrToAdjVNode NewNode,NewNode1; //�ڽӱ��½����
	DataType a, b; //��¼���붥��
	int i, j;//��¼���붥����±�

	cin >> G->Nv;   // ���붥����� 
	cin >> G->Ne;   // ������� 

	Graph->Nv = G->Nv;
	Graph->Ne = G->Ne;
	// ��ʼ���ڽӾ��� ȫ����0
	// Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = 0;

	// ��ʼ���ڽӱ� ��ͷ 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// ���붥������ 
	//�ڽӾ���
	for (V = 0; V<G->Nv; V++)
		cin >> G->Data[V];
	//�ڽӱ�
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].Data = G->Data[V];


	if (G->Ne != 0)
	{ // ����б� 

		E = new ENode; // �����߽�� 

					   // ����ߣ���ʽΪ"��� �յ� "�������ڽӾ���
		for (k = 0; k<G->Ne; k++)
		{
			cin >> a >> b;
			i = LocateVex(G, a);
			j = LocateVex(G, b);
			G->G[i][j] = 1;
			G->G[j][i] = 1;
			//�� �ڽӱ� �ڲ����� V2(b)
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			if (Graph->G[i].FirstEdge == NULL)//��ͷ���Ϊ��
			{
				Graph->G[i].FirstEdge = NewNode;
				NewNode->Next = NULL;
			}
			else
			{
				NewNode->Next = Graph->G[i].FirstEdge;
				Graph->G[i].FirstEdge = NewNode;
			}
			//�� �ڽӱ� �ڲ����� V1(a)
			NewNode1 = new struct AdjVNode;
			NewNode1->AdjV = i;
			if (Graph->G[j].FirstEdge == NULL)//��ͷ���Ϊ��
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

//������
MGraph CreateUDN(MGraph &G, LGraph Graph)
{
	Edge E;
	Vertex V, W;
	int k;
	PtrToAdjVNode NewNode, NewNode1; //�ڽӱ��½����
	DataType a, b; //��¼���붥��
	WeightType c;
	int i, j;//��¼���붥����±�

	cin >> G->Nv;   // ���붥����� 
	cin >> G->Ne;   // ������� 

	Graph->Nv = G->Nv;
	Graph->Ne = G->Ne;
	// ��ʼ���ڽӾ��� ȫ����0
	// Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = 0;

	// ��ʼ���ڽӱ� ��ͷ 
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	// ���붥������ 
	//�ڽӾ���
	for (V = 0; V<G->Nv; V++)
		cin >> G->Data[V];
	//�ڽӱ�
	for (V = 0; V<Graph->Nv; V++)
		Graph->G[V].Data = G->Data[V];

	if (G->Ne != 0)
	{ // ����б� 

		E = new ENode; // �����߽�� 

					   // ����ߣ���ʽΪ"��� �յ� "�������ڽӾ���
		for (k = 0; k<G->Ne; k++)
		{
			cin >> a >> b >> c;
			i = LocateVex(G, a);
			j = LocateVex(G, b);
			G->G[i][j] = c;
			G->G[j][i] = c;
			//�� �ڽӱ� �ڲ����� V2(b)
			NewNode = new struct AdjVNode;
			NewNode->AdjV = j;
			NewNode->Weight = c;
			if (Graph->G[i].FirstEdge == NULL)//��ͷ���Ϊ��
			{
				Graph->G[i].FirstEdge = NewNode;
				NewNode->Next = NULL;
			}
			else
			{
				NewNode->Next = Graph->G[i].FirstEdge;
				Graph->G[i].FirstEdge = NewNode;
				
			}
			//�� �ڽӱ� �ڲ����� V1(a)
			NewNode1 = new struct AdjVNode;
			NewNode1->AdjV = i;
			NewNode1->Weight = c;
			if (Graph->G[j].FirstEdge == NULL)//��ͷ���Ϊ��
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

//���� �ڽӾ���,�ڽӱ� ����ͼ
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
	GNode GA;// ͼ��㣨�ڽӾ���
	LGNode GB;
	MGraph G1 = &GA;
	LGraph G2 = &GB;
	G1 = CreatGraph(G1,G2);

	return 0;
}





