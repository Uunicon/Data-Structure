#include<iostream>
using namespace std;
struct LNode {
	int data;
	struct LNode *next;
};

int num;//全局变量，存放双向循环链表内的元素数量
struct DuLNode
{
	int data;
	struct DuLNode *prior;
	struct DuLNode *next;
};

int Cnum;//全局变量，存放单向循环链表内的元素数量
struct CirLNode
{
	int data;
	struct CirLNode *next;
};

//--------------------------------------------------------------------------------------------------------
//单链表函数
//建立链表
LNode *CreateList_L(int n)
{
	LNode *Head, *p, *L;
	Head = new LNode;
	Head->next = NULL;
	L = Head;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		if (Head == L)
		{
			L->next = p; p->next = NULL;
			L = p;
		}
		else
		{
			p->next = L;
			Head->next = p;
			L = p;
		}
	}
	return Head;
}//CreateList

//查找结点
LNode *FindKth(int k, LNode *head)
{
	LNode *p = head;
	int i = 1;
	while (p != NULL&&i < k)
	{
		p = p->next;
		i++;
	}
	if (i == k)return p;
	else return NULL;
}//FindKth

//插入
LNode *Insert(int X, int i, LNode*h)
{
	LNode *p, *s;
	if (i == 1)
	{
		s = new LNode;
		s->data = X;
		s->next = h->next;
		h->next = s;
		for (p = h->next; p; p = p->next)
			cout << p->data << " ";
		return h;
	}
	p = FindKth(i - 1, h->next);
	if (p == NULL)
	{
		cout << "插入失败";
		return h;
	}
	else
	{
		s = new LNode;
		s->data = X;
		s->next = p->next;
		p->next = s;
		cout << "当前链表为：" << endl;
		for (p = h->next; p; p = p->next)
			cout << p->data << " ";
		cout << endl;
		return h;
	}
}//Insert

//删除
LNode *Delete(int i, LNode *head)
{
	LNode *p,*q;
	p = head;
	int j = 0;
	while (p->next&&j<i-1)
	{
		p = p->next; ++j;
	}
	if(!(p->next)||j>i-1)
	{
		cout << "删除失败" ;
		return head;
	}
	q = p->next; p->next = q->next;
	delete q;
	cout << "当前链表为：" << endl;
	for (p = head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;
	return head;
}

//链表的逆置
LNode *ReverseList_L(LNode *head)
{
	LNode *H_t, *p, *L, *q;
	H_t = new LNode;
	H_t->next = NULL;
	L = H_t;
	for (q = head->next; q; q = q->next)
	{
		p = new LNode;
		p->data = q->data;
		if (H_t == L)
		{
			L->next = p; p->next = NULL;
			L = p;
		}
		else
		{
			p->next = L;
			H_t->next = p;
			L = p;
		}
	}
	return H_t;
}

//删除链表内重复元素
LNode *DeleteRe(LNode *head)
{
	LNode *p = head;
	LNode *h1 = head;  //用于遍历目标链表内的所有元素
	LNode *s;        //指向待删除的节点
	p = p->next;    //存在头结点，将指针放在第一个元素处
	h1 = h1->next;
	int n = 1;  //n为当前链表内元素数量
	int j;
	while (p->next)
	{
		for (j = 0; j < n; j++) // 将下一个元素与当前链表内所有元素进行比较
		{
			if (h1->data == p->next->data) //相等则删去该节点
			{
				s = p->next;             //记下待删除的结点 
				if (p->next->next != NULL)
					p->next = p->next->next;
				else p->next = NULL;    //若该节点为最后一个节点，则next设为空 
				delete s;
				break;
			}
			h1 = h1->next;
		}
		if (j == n)
		{
			p = p->next;
			n++;
		}
		h1 = head->next;       //每次查找结束后，h1回到第一个元素的位置
	}
	for (p = head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;
	return head;
}//DeleteRe

//按值查找，返回下标
LNode *Find(int X, LNode *head)
{
	LNode *p = head;
	int i = 0;
	while (p->data != X)
	{
		p = p->next;
		i++;
		if (p == NULL)break;
	}
	if (p==NULL)
	{
		cout << "未找到" << endl;
		return head;
	}
	else
	{
		cout <<"该元素为第 "<<i<<" 个元素"<<endl;
		return head;
	}
}//Find

//统计元素个数
int Count(LNode *head)
{
	int i = 0;
	LNode *p = head;
	for (; p; p = p->next)
		i++;
	return i-1;
}

//--------------------------------------------------------------------------------------------------------

//双向循环链表函数
//建立链表
DuLNode *CreateList_DUL(int n)
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
DuLNode *Insert_DUL(int X, int i, DuLNode*h)
{
	DuLNode *p, *s;//s存放新建指针
	int t = i;           //存i用于判断是否为1
	if (i<1 || i>num + 1)  //若插入节点i不符合要求，输出-1
	{
		cout << "插入失败";
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
	cout << "当前链表为：" << endl;
	for (p = h, i = 0; i<num; p = p->next, i++)
		cout << p->data << " ";
	cout << endl;
	return h;
}

//给出位置，删除一个数
DuLNode *Delete_DUL(int i, DuLNode *head)
{
	DuLNode *p, *q;
	p = head;
	if (i<1 || i>num)  //若插入节点i不符合要求，输出-1
	{
		cout << "删除失败";
		return head;
	}
	for (int j = 1; j < i; j++) //将p移动到插入位置的后一节点
		p = p->next;
	if (p == head) head = p->next; //若删除第一个元素，则移动head
	p->next->prior = p->prior;
	p->prior->next = p->next;

	delete p;
	num--;
	cout << "当前链表为：" << endl;
	for (q = head, i = 0; i<num; q = q->next, i++)
		cout << q->data << " ";
	cout << endl;
	return head;
}
//按值查找，返回下标
DuLNode *Find_DUL(int X, DuLNode *head)
{
	DuLNode *p = head;
	int i;
	for (i = 1; i <= num; i++, p = p->next)
		if (p->data == X)
		{
			cout << "该元素为第 " << i << " 个元素" << endl;
			break;
		}
	if (i > num) cout << "未找到" << endl;
	return head;
}

//---------------------------------------------------------------------------------------------------------

//单项链表函数
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
	
	LNode *Head, *p;
	//单向链表
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;
	cout << endl;
	cout << "单向链表:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;

	
	int n;
	cout << "请输入创建的单链表的元素个数：";
	cin >> n;
	cout << endl;
	cout << "请输入各个元素，空格分隔，回车结束：" << endl;
	Head = CreateList_L(n);        //逆序创建链表
	cout << endl;
	cout << "当前链表为：" << endl;
	for (p = Head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;

	cout << endl;
	cout << "请输入插入数值的下标、插入的数值：";
	int i, X;
	cin >> i >> X;
	Head = Insert(X, i, Head);      //插入数值
	cout << endl;

	cout << "请输入待删除数的下标：";
	int d;
	cin >> d;
	Head = Delete(d, Head);           //删除数值
	cout << endl;

	cout << "逆置后的链表为：" << endl;
	Head = ReverseList_L(Head);
	for (p = Head->next; p; p = p->next)
		cout << p->data << " ";
	cout << endl;
	cout << endl;

	cout << "去重后的链表为：" << endl;
	Head = DeleteRe(Head);
	cout << endl;


	cout << "请输入待查找的数值：";
	int X1;
	cin >> X1;
	Head = Find(X1,Head);

	cout << endl;
	cout << "当前链表的元素个数为： ";
	cout << Count(Head) << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;

	cout << endl;
	cout << endl;
	cout << "双向循环链表:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;
	//双向循环链表
	DuLNode *DHead, *Dp;
	int Dn, Di;
	cout << "请输入创建的单链表的元素个数：";
	cin >> Dn;
	num = Dn;
	cout << endl;
	cout << "请输入各个元素，空格分隔，回车结束：" << endl;
	DHead = CreateList_DUL(Dn);
	cout << endl;
	cout << "当前链表为：" << endl;
	for (Dp = DHead, Di = 0; Di<num; Dp = Dp->next, Di++)
		cout << Dp->data << " ";

	cout << endl;
	int Dj, DX;
	cout << "请输入插入数值的下标、插入的数值：";
	cin >> Dj >> DX;
	DHead = Insert_DUL(DX, Dj, DHead);
	cout << endl;

	int Dd;
	cout << "请输入待删除数的下标：";
	cin >> Dd;
	DHead = Delete_DUL(Dd, DHead);
	cout << endl;

	int DX1;
	cout << "请输入待查找的数值：";
	cin >> DX1;
	DHead = Find_DUL(DX1, DHead);
	cout << "当前链表的元素个数为： ";
	cout << num << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;

	cout << endl;
	cout << endl;
	cout << "单向循环链表:" << endl;
	cout << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;
	//单向循环链表
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
	cout << "请输入待查找的数值：";
	cin >> CX1;
	CHead = Find_Cir(CX1, CHead);
	cout << "当前链表的元素个数为： ";
	cout << Cnum << endl;
	for (int i = 0; i < 100; i++) cout << "-";   //格式控制
	cout << endl;
	return 0;
}