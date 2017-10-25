#include<iostream>
using namespace std;
struct LNode {
	int data;
	struct LNode *next;
};
//建立链表，头插法，逆序建立 
LNode *CreateList_L(int n)
{
	LNode *Head, *p, *L;
	Head = new LNode;
	Head->next = NULL;
	L = Head;
	for (int i = 0; i < n; i++)  //尾插法顺序建立链表 
	{
		p = new LNode;
		cin >> p->data;
		L->next = p; p->next = NULL;
		L = p;
	}
	return Head;
}//CreateList

 //删除链表中所有指定元素 
LNode *Delete(int X, LNode *head)
{
	LNode *p = head;
	LNode *s;
	int i = 0;
	while (p->next != NULL)   //下一个元素非空 
	{
		if (p->next->data != X) p = p->next;  //下一个元素值不等于目标值 
		else            //p->next->data ==X 下一个元素值等于目标值 
		{
			s = p->next;  //记下待删除的结点 
			if(p->next->next!=NULL)
				p->next = p->next->next;
			else p->next = NULL; //若该节点为最后一个节点，则next设为空 
			delete s;
			i++;  //记录重复元素的数量 
		}
	}
	if (i == 0)  //未找到输出-1 
	{
		cout << "-1" << endl;
		return head;
	}
	else   //找到输出所有元素 
	{
		for (p = head->next; p; p = p->next)
			cout << p->data << " ";
		cout << endl;
		return head;
	}
}//Delete

int main()
{
	LNode *Head, *p;
	int n;
	cin >> n;
	Head = CreateList_L(n);
	int X;
	cin >> X;  //输入待查找的数 
	Head = Delete(X,Head);
	return 0;
}
