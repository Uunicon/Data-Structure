#include<iostream>
#include<string>
using namespace std;

//Link == 0��ָ�룬Thread == 1������ 
typedef enum PointerTag { Link, Thread };

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

 //����������
void InThreading(BiThrTree &T)
{
	if (T)
	{
		InThreading(T->lchild);
		if (!T->lchild)
		{
			T->LTag = Thread;
			T->lchild = pre;
		}
		if (!T->rchild)
			T->RTag = Thread;
		if (pre && pre->RTag == Thread)
			pre->rchild = T;
		pre = T;
		
		InThreading(T->rchild);
	}
}

//������������������
void Inorder_Thr(BiThrTree &T)
{
	BiThrTree p = T;
	while (p->LTag == Link) p = p->lchild;
	cout << p->data;
	while (p->rchild)
	{
		if (p->RTag == Link)
		{
			p = p->rchild;
			while (p->LTag == Link) 
			{
				p = p->lchild;
			}
		}
		else p = p->rchild;
		cout << p->data;
	}
}

void Find_Thr(BiThrTree &T,char x)
{
	int f = 0; //��־λ���ҵ���Ϊ1��δ�ҵ�Ϊ0
	BiThrTree p = T;
	if (!p->lchild && !p->rchild) //ֻ��һ�����
	{
		if (p->data == x)cout << "succ is NULL" << endl << "prev is NULL" << endl;
		else cout << "Not found" << endl;
		return;
	}
	while (p->LTag == Link) p = p->lchild;
	if (p->data == x)   //��ǡ��Ϊ��һ�����
	{
		cout << "succ is " <<p->rchild->data<< p->rchild->RTag << endl;
		cout << "prev is NULL" << endl;   //ǰ��ΪNULL
		f = 1;
	}
	else     //���ǵ�һ�����
	{ 
		while (p->rchild)
		{
			if (p->RTag == Link)
			{
				pre = p; //��¼ǰ��
				p = p->rchild;
				while (p->LTag == Link)
				{
					pre = p;
					p = p->lchild;
				}
			}
			else { pre = p; p = p->rchild; }
			if (p->data == x) //���ҵ�
			{
				if (p->rchild)  //���Һ��ӷǿ�
					cout << "succ is " << p->rchild->data << p->rchild->RTag << endl;
				else cout << "succ is NULL" << endl;  //�Һ���Ϊ��
				cout << "prev is " << pre->data << pre->LTag<<endl;
				f = 1;
			}

		}
	}
	if (f == 0)cout << "Not found" << endl;
}

int main()
{
	char find;
	BiThrTNode *BiThrTree;
	CreateBiTree(BiThrTree);
	cin >> find;
	InThreading(BiThrTree);
	Inorder_Thr(BiThrTree);
	cout << endl;
	Find_Thr(BiThrTree, find);
	return 0;
}
