#include<iostream>
using namespace std;

int num;//全局变量，存放双向循环链表内的元素数量
struct DuLNode 
{
	int data;
	struct DuLNode *prior;
	struct DuLNode *next;
};
//建立链表
DuLNode *CreateList_L(int n)
{
	DuLNode *Head, *p;
	Head = p = new DuLNode;
	cin >> Head->data;
	Head->next = Head;
	Head->prior = Head;
	for (int i = 1; i < n; i++)
	{
		p->next = new DuLNode;
		p->next->prior = p;
		p = p->next;
		cin >> p->data;
	}
	p->next = Head;
	Head->prior = p;
	return Head;
}//CreateList

 //给出位置，插入一个数
DuLNode *Insert(int X, int i, DuLNode*h)
{
	DuLNode *p, *s;//s存放新建指针
	int t = i;           //存i用于判断是否为1
	if (i<1 || i>num+1)  //若插入节点i不符合要求，输出-1
	{
		cout << "-1";
		return h;
	}
	if (i == num + 1) //若i恰好插入到最后一个节点之后，将它视为插到第一个节点之前
		i = i - num; 
	p = h;
	s = new DuLNode;
	s->data = X;
	for (int j = 1; j < i; j++) //将p移动到插入位置的后一节点
			p = p->next;
	p->prior->next = s;
	s->next = p;
	s->prior = p->prior;
	p->prior = s;
	num++;
	if (t == 1) h = s; //若插入点为1，则改变头结点
	for (p = h, i = 0; i<num; p = p->next, i++)
		cout << p->data << " ";
	return h;
}

//给出位置，删除一个数
DuLNode *Delete(int i, DuLNode *head)
{
	DuLNode *p, *q;
	p = head;
	if (i<1 || i>num)  //若插入节点i不符合要求，输出-1
	{
		cout << "-1";
		return head;
	}
	for (int j = 1; j < i; j++) //将p移动到插入位置的后一节点
		p = p->next;
	if (p == head) head = p->next; //若删除第一个元素，则移动head
	p->next->prior = p->prior;
	p->prior->next = p->next;
	
	delete p;
	num--;
	for (q = head, i = 0; i<num; q = q->next, i++)
		cout << q->data << " ";
	return head;
}

DuLNode *Find(int X, DuLNode *head)
{
	DuLNode *p = head;
	int i;
	for ( i = 1; i <= num; i++,p=p->next)
		if (p->data == X)
		{
			cout << i << endl;
			break;
		}
	if (i > num) cout << "-1" << endl;
	return head;
}

int main()
{
	DuLNode *Head, *p;
	int n,i;
	cin >> n;
	num = n;
	Head = CreateList_L(n);
	for (p = Head,i=0; i<num; p = p->next,i++)
		cout << p->data << " ";

	cout << endl;
	int j, X;
	cin >> j >> X;
	Head = Insert(X, j, Head);
	cout << endl;

	int d;
	cin >> d;
	Head = Delete(d, Head);
	cout << endl;

	int X1;
	cin >> X1;
	Head = Find(X1, Head);
	cout << num << endl;
	return 0;
}