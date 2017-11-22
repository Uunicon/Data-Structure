#include<iostream>
#include<string>
using namespace std;

//Link == 0��ָ�룬Thread == 1������ 
typedef enum PointerTag {Link,Thread};

//�����������ڵ�
typedef struct BiThrTNode
{
	char data;
	BiThrTNode *lchild, *rchild;
	PointerTag LTag, RTag;
} BiThrTNode, *BiThrTree;

//��ʼ������ָ��
BiThrTNode *pre = NULL;


//�ݹ�������
void CreateBiTree(BiThrTree &T)
{
	char data;
	cin >> data;
	if (data == '#')
		T = NULL;
	else
	{
		T = new BiThrTNode;
		T->data = data;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}//CreateBiTree

 //�����������
void InThreading(BiThrTree &T)
{
	if (T)
	{
		if (T->lchild) T->LTag = Link;
		if (T->rchild) T->RTag = Link;
		if (!T->lchild)
		{
			T->LTag = Thread;
			T->lchild = pre;
		}
		if (!T->rchild)
			T->RTag = Thread;
		if (pre && pre->RTag==Thread)
			pre->rchild = T;
		pre = T;
		if(T->LTag==Link) InThreading(T->lchild);
		if(T->RTag==Link) InThreading(T->rchild);
	}
}

//�������ӡ
void InPrintTree(BiThrTree &T, int n) //n��¼�ݹ����
{
	if (T)
	{
		if (T->RTag != 1 )
		  InPrintTree(T->rchild, n + 1);
		for (int i = 0; i < n; i++)cout << "     ";
		cout << T->data << T->LTag << T->RTag << endl;
		if (T->LTag != 1 )
		  InPrintTree(T->lchild, n + 1);
	}
}

//������������������
void Preorder_Thr(BiThrTree &T)
{
	BiThrTree p = T;
	cout << p->data;
	while (p->rchild)
	{
		if (p->LTag == Link)p = p->lchild;
		else p = p->rchild;
		cout << p->data;
	}
}

int main()
{
	BiThrTNode *BiThrTree;
	CreateBiTree(BiThrTree);
	InThreading(BiThrTree);
	InPrintTree(BiThrTree, 0);
	Preorder_Thr(BiThrTree);
	return 0;
}
