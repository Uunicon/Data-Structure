#include<iostream>
#include<string>
using namespace std;
//�������ڵ�
typedef struct BiTNode
{
	char data;
	BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int leaf=0;
int node=0;
int depth=0;

//�ݹ�������
void CreateBiTree(BiTree &T)
{
	char data;
	cin >> data;
	if (data == '#')
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = data;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}//CreateBiTree

 //�ݹ��������
void CountTree(BiTree &T,int n)
{
	if (T)
	{
		node++;
		if (!T->lchild && !T->rchild) leaf++;
		CountTree(T->lchild,n+1);
		CountTree(T->rchild,n+1);
	}
}

int GetTreeDeep(BiTree &T)   //��������������
{
	if (T == NULL)
		return 0;
	else {
		int a = GetTreeDeep(T->lchild);
		int b = GetTreeDeep(T->rchild);
		return (a>b) ? (a + 1) : (b + 1);
	}
}

//��ӡ
void InPrintTree(BiTree &T, int n) //n��¼�ݹ����
{
	if (T)
	{
		InPrintTree(T->rchild, n + 1);
		for (int i = 0; i < n; i++)cout << "     ";
		cout << T->data << endl;
		InPrintTree(T->lchild, n + 1);
	}
}

void CopyTree(BiTree &T, BiTree &T2)
{
	if (T)
	{
		T2 = new BiTNode;
		T2->data = T->data;
		T2->lchild = T2->rchild = NULL;
		CopyTree(T->lchild, T2->rchild);
		CopyTree(T->rchild, T2->lchild);
	}
}

int main()
{
	BiTNode *BiTree;
	BiTNode *BiTree2;
	CreateBiTree(BiTree);
	CountTree(BiTree,depth);
	depth = GetTreeDeep(BiTree);
	cout << leaf << endl << node << endl << depth << endl;
	InPrintTree(BiTree, 0);
	CopyTree(BiTree, BiTree2);
	InPrintTree(BiTree2, 0);
	return 0;
}