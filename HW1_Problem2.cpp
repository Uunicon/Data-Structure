#include <iostream>
using namespace std;
#define MAX 10000
int n;  //n为固定线性表元素个数
struct List
{
	int *Data;
	int last;
};
List *PtrL;
//建立空表 (从小到大)
List *MakeEmpty(int n)
{
	PtrL = new List;
	PtrL->Data = new int[n];
	PtrL->last = 0;
	int *t = new int[n];  //临时存放数组
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		if (t[i] == 0)break; //输入0停止输入
		PtrL->last++;
	} 
	int i, j,temp;
	for(i=0;i<PtrL->last-1;i++) //临时数组排序
		for (j = 0; j < PtrL->last - 1 - i; j++)
		{
			if (t[j + 1] < t[j])
			{
				temp = t[j + 1]; t[j + 1] = t[j]; t[j] = temp;
			}
		}

	for (int i = 0; i < PtrL->last; i++)//将排好序的数组放入线性表中
	{
		PtrL->Data[i] = t[i];
	}
	return PtrL;
}
//插入一个数
void OrderInsert(int X,List *p)
{
	int i = 0;
	while (i < p->last&&p->Data[i] < X)i++;
	for (int j = p->last - 1; j >= i; j--)
		p->Data[j + 1] = p->Data[j];
	p->Data[i] = X;
	cout << i+1<<endl; //输出插入数所在的位置
	p->last++;
}

//删除标号对应的数值
void OrderDelete(int X, List *p)
{
	int i = 0;
	while (i < p->last&&p->Data[i] != X)i++;
	if (i > p->last-1) { cout << "-1" << endl; return; }
	else
	{
		for (int j = i; j <p->last; j++)
			p->Data[j] = p->Data[j+1];
	}
	cout << i + 1 << endl; //输出删除数所在的位置
	p->last--;
}


int main()
{
	List *MakeEmpty(int n);              
	PtrL = MakeEmpty(MAX);


	//插入一个数
	int X;     //X为目标数
	cin >> X;
	OrderInsert(X, PtrL);
	//删除一个数
	int t2;
	cin >> t2;
	OrderDelete(t2, PtrL);
	for (int i = 0; i < PtrL->last; i++)
	{
		cout << PtrL->Data[i] << " ";
	}
	return 0;
}
