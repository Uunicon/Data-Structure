#include<iostream>
using namespace std;

#define MaxVertexNum 100       // ��󶥵�����Ϊ100 
#define INFINITY 65535         //ͼ����ͨ��Ϊ�����

typedef int Vertex;            // �ö����±��ʾ����,Ϊ���� 
typedef int WeightType;        // �ߵ�Ȩֵ��Ϊ���� 
typedef int DataType;         // ����洢������������Ϊ�ַ��� 


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
};
typedef PtrToGNode MGraph; // ���ڽӾ���洢��ͼ���� 


//������
MGraph CreateUDN(MGraph &G)
{
	Edge E;
	Vertex V, W;
	int k;
	DataType a, b; //��¼���붥��
	WeightType c;

	cin >> G->Nv;   // ���붥����� 
	cin >> G->Ne;   // ������� 

	// ��ʼ���ڽӾ��� ȫ����infinity
	// Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) 
	for (V = 0; V<G->Nv; V++)
		for (W = 0; W<G->Nv; W++)
			G->G[V][W] = INFINITY;

	// ���붥������ 
	//�ڽӾ���
	for (V = 0; V<G->Nv; V++)
		G->Data[V]= V + 1;

	if (G->Ne != 0)
	{ // ����б� 

		E = new ENode; // �����߽�� 

					   // ����ߣ���ʽΪ"��� �յ� "�������ڽӾ���
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
	//Ĭ���±�=0�ĵ�Ϊ��һ���� ��Ӧ��ֵΪ1
	for (j = 0; j < G->Nv; j++)  //���������ʼ��
		closedge[j] = { G->Data[0],G->G[0][j]};
	closedge[0].lowest = 0;  //��ʼU = {u}

	for (i = 1; i < G->Nv; i++)
	{
		int min = INFINITY;
		for (k = 0; k < G->Nv; k++)
			if (closedge[k].lowest > 0 && closedge[k].lowest < min)
			{
				min = closedge[k].lowest;
				V = k; //����Сֵ�±�
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
	GNode GA;// ͼ��㣨�ڽӾ���;
	MGraph G1 = &GA;
	G1 = CreateUDN(G1);
	MiniSpanTree_PRIM(G1);
	return 0;
}
