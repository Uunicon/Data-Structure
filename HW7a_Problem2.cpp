#include<iostream>
using namespace std;

#define MaxVertexNum 100       // ��󶥵�����Ϊ100 
#define INFINITY 2147483647

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
MGraph CreateDN(MGraph &G,int nv ,int ne)
{
	Edge E;
	Vertex V, W;
	int k;
	DataType a, b; //��¼���붥��
	WeightType c;

	G->Nv=nv;   // ���붥����� 
	G->Ne=ne;   // ������� 

	// ��ʼ���ڽӾ��� ȫ����0
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
		}
	}
	return G;
}

// �ڽӾ���洢 - ��Ȩͼ�ĵ�Դ���·�㷨

Vertex FindMinDist(MGraph Graph, int dist[], int collected[])
{ // ����δ����¼������dist��С��
	Vertex MinV, V;
	int MinDist = INFINITY;

	for (V = 0; V<Graph->Nv; V++) {
		if (collected[V] == false && dist[V]<MinDist) {
			// ��Vδ����¼����dist[V]��С 
			MinDist = dist[V]; // ������С���� 
			MinV = V; //���¶�Ӧ���� 
		}
	}
	if (MinDist < INFINITY) //���ҵ���Сdist 
		return MinV; // ���ض�Ӧ�Ķ����±�
	else return -1;  // �������Ķ��㲻���ڣ����ش�����
}

void Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;

	// ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ 
	for (V = 0; V<Graph->Nv; V++) {
		dist[V] = Graph->G[S][V];
		if (dist[V]<INFINITY)
			path[V] = S;
		else
			path[V] = -1;
		collected[V] = false;
	}
	// �Ƚ�������뼯�� 
	dist[S] = 0;
	collected[S] = true;

	while (1) {
		// V = δ����¼������dist��С��
		V = FindMinDist(Graph, dist, collected);
		if (V == -1) // ��������V������ 
			break;      // �㷨����
		collected[V] = true;  // ��¼V
		for (W = 0; W<Graph->Nv; W++) //��ͼ�е�ÿ������W 
									  // ��W��V���ڽӵ㲢��δ����¼ 
			if (collected[W] == false && Graph->G[V][W]<INFINITY) {
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W]; // ����dist[W] 
					path[W] = V; // ����S��W��·�� 
				}
			}
	} // while����
	for (int i = 0; i < Graph->Nv; i++)
		cout << dist[i] << " ";
	cout << endl;
}

int main()
{
	GNode GA;// ͼ��㣨�ڽӾ���
	MGraph G1 = &GA;
	int nv, ne, s;
	cin >> nv >> ne >> s;
	int dis[MaxVertexNum];
	int path[MaxVertexNum];
	G1 = CreateDN(G1,nv,ne);
	Dijkstra(G1,dis,path,s-1);
	return 0;
}