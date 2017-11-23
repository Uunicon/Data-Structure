#include<iostream>
#include<string>
using namespace std;

//Link == 0：指针，Thread == 1：线索 
typedef enum PointerTag { Link, Thread };

//线索二叉树节点
typedef struct BiThrTNode
{
	char data;
	BiThrTNode *lchild, *rchild;
	PointerTag LTag, RTag;
} BiThrTNode, *BiThrTree;

//初始化先驱指针
BiThrTNode *pre = NULL;


//递归先序建立
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

 //中序线索化
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

//遍历中序线索二叉树
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
	int f = 0; //标志位，找到置为1，未找到为0
	BiThrTree p = T;
	if (!p->lchild && !p->rchild) //只有一个结点
	{
		if (p->data == x)cout << "succ is NULL" << endl << "prev is NULL" << endl;
		else cout << "Not found" << endl;
		return;
	}
	while (p->LTag == Link) p = p->lchild;
	if (p->data == x)   //若恰好为第一个结点
	{
		cout << "succ is " <<p->rchild->data<< p->rchild->RTag << endl;
		cout << "prev is NULL" << endl;   //前驱为NULL
		f = 1;
	}
	else     //不是第一个结点
	{ 
		while (p->rchild)
		{
			if (p->RTag == Link)
			{
				pre = p; //记录前驱
				p = p->rchild;
				while (p->LTag == Link)
				{
					pre = p;
					p = p->lchild;
				}
			}
			else { pre = p; p = p->rchild; }
			if (p->data == x) //若找到
			{
				if (p->rchild)  //若右孩子非空
					cout << "succ is " << p->rchild->data << p->rchild->RTag << endl;
				else cout << "succ is NULL" << endl;  //右孩子为空
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
