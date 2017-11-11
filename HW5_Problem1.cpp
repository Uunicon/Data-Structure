#include<iostream>
#include<string>
using namespace std;
//�������ڵ�
typedef struct BiTNode
{
	char data;
	BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//���н��
struct QNode   
{
	BiTNode node;
	struct QNode *next;
};
//����ͷ��βָ��
struct QPtr   
{
	QNode *front;
	QNode *rear;
}LQ;
int Q_MAX=10000;    //����Ԫ�����ֵ
int Q_n;      //��ǰ����Ԫ�ظ���

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
void PreOrderTraverse(BiTree &T)
{
	if (T)
	{
		cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//�ݹ��������
void InOrderTraverse(BiTree &T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

//�ݹ�������
void PostOrderTraverse(BiTree &T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data;
	}
}

//��������
void CreateQueue(int n)
{
	QNode *p, *L;
	LQ.front = new QNode;
	LQ.front->next = NULL;
	L = LQ.rear = LQ.front;
	Q_n = 0;
}//CreateQueue

 //����
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

//���
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

//��α���
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

//��ӡ
void PostPrintTree(BiTree &T,int n) //n��¼�ݹ����
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