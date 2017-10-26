#include<iostream>
using namespace std;

int Cnum;//全局变量，存放单向循环链表内的元素数量
struct CirLNode
{
	int data;
	struct CirLNode *next;
};
//建立链表
CirLNode *CreateList_Cir(int n)
{
	CirLNode *Head, *p;
	Head = p = new CirLNode;
	cin >> Head->data;
	Head->next = Head;
	for (int i = 1; i < n; i++)
	{
		p->next = new CirLNode;
		p = p->next;
		cin >> p->data;
	}
	p->next = Head;
	return Head;
}//CreateList

 //给出位置，插入一个数
CirLNode *Insert_Cir(int X, int i, CirLNode*h)
{
	CirLNode *p, *s;//s存放新建指针
	int t = i;           //存i用于判断是否为1
	if (i<1 || i>Cnum + 1)  //若插入节点i不符合要求，输出-1
	{
		cout << "插入失败";
		return h;
	}
	if (i == 1) //若i恰好插入到第一个节点之前，将它视为插到最后一个节点之后
		i = i + Cnum;
	p = h;
	s = new CirLNode;
	s->data = X;
	for (int j = 1; j < i - 1; j++) //将p移动到插入位置的后一节点
		p = p->next;
	s->next = p->next;
	p->next = s;
	Cnum++;
	if (t == 1) h = s; //若插入点为1，则改变头结点
	cout << "当前链表为：" << endl;
	for (p = h, i = 0; i<Cnum; p = p->next, i++)
		cout << p->data << " ";
	cout << endl;
	return h;
}

//给出位置，删除一个数
CirLNode *Delete_Cir(int i, CirLNode *head)
{
	CirLNode *p, *q, *s;
	p = head;
	if (i<1 || i>Cnum)  //若插入节点i不符合要求，输出-1
	{
		cout << "删除失败";
		return head;
	}
	if (i == 1)
	{
		while (p->next != head)
			p = p->next;
		s = head;
		p->next = head->next;
		head = head->next;
		delete s;
	}
	else
	{
		for (int j = 1; j < i - 1; j++) //将p移动到删除位置的后一节点
			p = p->next;
		s = p->next;
		p->next = p->next->next;
		delete s;
	}
	Cnum--;
	cout << "当前链表为：" << endl;
	for (q = head, i = 0; i<Cnum; q = q->next, i++)
		cout << q->data << " ";
	cout << endl;
	return head;
}

// 按值查找，返回下标
CirLNode *Find_Cir(int X, CirLNode *head)
{
	CirLNode *p = head;
	int i;
	for (i = 1; i <= Cnum; i++, p = p->next)
		if (p->data == X)
		{
			cout << "该元素为第 " << i << " 个元素" << endl;
			break;
		}
	if (i > Cnum) cout << "未找到" << endl;
	return head;
}


int main()
{
	CirLNode *CHead, *Cp;
	int Cn, Ci;
	cout << "请输入创建的单链表的元素个数：";
	cin >> Cn;
	Cnum = Cn;
	cout << endl;
	cout << "请输入各个元素，空格分隔，回车结束：" << endl;
	CHead = CreateList_Cir(Cn);
	cout << endl;
	cout << "当前链表为：" << endl;
	for (Cp = CHead, Ci = 0; Ci<Cnum; Cp = Cp->next, Ci++)
		cout << Cp->data << " ";

	cout << endl;
	int Cj, CX;
	cout << "请输入插入数值的下标、插入的数值：";
	cin >> Cj >> CX;
	CHead = Insert_Cir(CX, Cj, CHead);
	cout << endl;

	int Cd;
	cout << "请输入待删除数的下标：";
	cin >> Cd;
	CHead = Delete_Cir(Cd, CHead);
	cout << endl;

	int CX1;
	cin >> CX1;
	cout << "请输入待查找的数值：";
	CHead = Find_Cir(CX1, CHead);
	cout << "当前链表的元素个数为： ";
	cout << Cnum << endl;
	return 0;
}