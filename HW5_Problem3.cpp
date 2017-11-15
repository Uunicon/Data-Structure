#include<iostream>
#include<string>
using namespace std;

#define MAX 10000
//�������ڵ�
typedef struct BiTNode
{
	char data;
	BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//��ջ�ṹ
struct Stack
{
	int stacksize;
	BiTNode *base; //ջ��
	BiTNode *top;  //ջ��
	BiTNode *s;    //ָ��̬�����ջ
};

//������ջ
Stack *Create_Stack(int n)
{
	Stack *t;
	t = new Stack;
	t->s = new BiTNode[n];
	t->stacksize = n;
	t->base = t->top = &(t->s[0]);
	return t;
}

//�ж϶�ջ�Ƿ�Ϊ��
bool StackIsEmpty(Stack *S)
{
	if (S->base == S->top)return true;
	else return false;
}

//ѹջ
void Push(Stack *t, BiTNode x)
{
	*(t->top) = x;
	cout << "push " << x.data << endl;
	t->top++;
}

//��ջ
BiTree Pop(Stack *t)
{
	return --t->top;
}

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

//�ǵݹ��������
void InOrderTraversal(BiTree &T)
{
	Stack *s;
	s = Create_Stack(MAX); //��������ʼ����ջ
	while (T||!StackIsEmpty(s))
	{
		while (T)    //һֱ���󲢽���;�ڵ�ѹ���ջ
		{
			Push(s, *T);
			T = T->lchild;
		}
		if (!StackIsEmpty(s))
		{
			T = Pop(s);   //��㵯����ջ
			cout << "pop" << endl << T->data << endl;   //��ӡ�ڵ�
			T = T->rchild;    //ת��������
		}
	}
}

int main()
{
	BiTNode *BiTree;
	CreateBiTree(BiTree);
	InOrderTraversal(BiTree);
	return 0;
}