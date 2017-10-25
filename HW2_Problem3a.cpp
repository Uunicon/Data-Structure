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
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		L->next = p; p->next = NULL;
		L = p;
	}
	return Head;
}//CreateList

 //删除链表内重复元素
LNode *Delete(LNode *head)
{
	LNode *p = head;
	LNode *h1 = head;  //用于遍历目标链表内的所有元素
	LNode *s;        //指向待删除的节点
	p = p->next;    //存在头结点，将指针放在第一个元素处
	h1 = h1->next;
	int n=1;  //n为当前链表内元素数量
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
	
}//Delete

int main()
{
	LNode *Head, *p;
	int n;
	cin >> n; //建立链表元素数量
	Head = CreateList_L(n);
	Head = Delete(Head);
	return 0;
}