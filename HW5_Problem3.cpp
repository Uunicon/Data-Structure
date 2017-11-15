#include<iostream>
#include<string>
using namespace std;

#define MAX 10000
//二叉树节点
typedef struct BiTNode
{
	char data;
	BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//堆栈结构
struct Stack
{
	int stacksize;
	BiTNode *base; //栈底
	BiTNode *top;  //栈顶
	BiTNode *s;    //指向动态申请的栈
};

//建立堆栈
Stack *Create_Stack(int n)
{
	Stack *t;
	t = new Stack;
	t->s = new BiTNode[n];
	t->stacksize = n;
	t->base = t->top = &(t->s[0]);
	return t;
}

//判断堆栈是否为空
bool StackIsEmpty(Stack *S)
{
	if (S->base == S->top)return true;
	else return false;
}

//压栈
void Push(Stack *t, BiTNode x)
{
	*(t->top) = x;
	cout << "push " << x.data << endl;
	t->top++;
}

//出栈
BiTree Pop(Stack *t)
{
	return --t->top;
}

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

//非递归中序遍历
void InOrderTraversal(BiTree &T)
{
	Stack *s;
	s = Create_Stack(MAX); //创建并初始化堆栈
	while (T||!StackIsEmpty(s))
	{
		while (T)    //一直向左并将沿途节点压入堆栈
		{
			Push(s, *T);
			T = T->lchild;
		}
		if (!StackIsEmpty(s))
		{
			T = Pop(s);   //结点弹出堆栈
			cout << "pop" << endl << T->data << endl;   //打印节点
			T = T->rchild;    //转到右子树
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