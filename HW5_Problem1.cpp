#include<iostream>
#include<string>
using namespace std;
//二叉树节点
typedef struct BiTNode
{
	char data;
	BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//队列结点
struct QNode   
{
	BiTNode node;
	struct QNode *next;
};
//队列头、尾指针
struct QPtr   
{
	QNode *front;
	QNode *rear;
}LQ;
int Q_MAX=10000;    //队列元素最大值
int Q_n;      //当前队列元素个数

//递归先序建立
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

//递归先序遍历
void PreOrderTraverse(BiTree &T)
{
	if (T)
	{
		cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//递归中序遍历
void InOrderTraverse(BiTree &T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

//递归后序遍历
void PostOrderTraverse(BiTree &T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data;
	}
}

//建立队列
void CreateQueue(int n)
{
	QNode *p, *L;
	LQ.front = new QNode;
	LQ.front->next = NULL;
	L = LQ.rear = LQ.front;
	Q_n = 0;
}//CreateQueue

 //出队
BiTNode DeQueue()
{
	QNode *s;
	BiTNode t;
	s = LQ.front->next;
	t = s->node;
	if (Q_n == 1)
		LQ.rear = LQ.front;
	else
		LQ.front->next = LQ.front->next->next;
	Q_n--;
	delete s;
	return t;
}

//入队
void EnQueue(BiTNode x)
{
	QNode *p;
	p = new QNode;
	p->node = x;
	LQ.rear->next = p;
	LQ.rear = p;
	LQ.rear->next = NULL;
	Q_n++;
}

//层次遍历
void LevelOrderTraversal(BiTree &T)
{
	BiTNode NT;
	if (!T)return;
	CreateQueue(Q_MAX);
	EnQueue(*T);
	while (LQ.rear != LQ.front)
	{
		NT = DeQueue();
		cout << NT.data;
		if (NT.lchild) EnQueue(*NT.lchild);
		if (NT.rchild) EnQueue(*NT.rchild);
	}
}

//打印
void PostPrintTree(BiTree &T,int n) //n记录递归次数
{
	if (T)
	{
		PostPrintTree(T->rchild,n+1);
		for (int i = 0; i < n; i++)cout << "     ";
		cout << T->data << endl;
		PostPrintTree(T->lchild,n+1);
	}
}

int main()
{
	BiTNode *BiTree;
	CreateBiTree(BiTree);
	PreOrderTraverse(BiTree);
	cout << endl;
	InOrderTraverse(BiTree);
	cout << endl;
	PostOrderTraverse(BiTree);
	cout << endl;
	LevelOrderTraversal(BiTree);
	cout << endl;
	PostPrintTree(BiTree, 0);
	return 0;
}