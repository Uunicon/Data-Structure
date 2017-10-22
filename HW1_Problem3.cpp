#include <iostream>
using namespace std;
#define MAX 20000
int n;  //n为固定线性表元素个数
struct List
{
	int *Data;
	int last;
};

//建立空表 (输入数值，从小到大)
bool MakeEmpty(int n,List *p)
{
	p->Data = new int[n];
	p->last = 0;
	int *t = new int[n];  //临时存放数组
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		if (t[i] == 0)break; //输入0停止输入
		p->last++;
	}
	int i, j, temp;
	for (i = 0; i<p->last - 1; i++) //临时数组排序
		for (j = 0; j < p->last - 1 - i; j++)
		{
			if (t[j + 1] < t[j])
			{
				temp = t[j + 1]; t[j + 1] = t[j]; t[j] = temp;
			}
		}

	for (int i = 0; i < p->last; i++)//将排好序的数组放入线性表中
	{
		p->Data[i] = t[i];
	}
	return true;
}
//建立空表 （不输入数值）
bool Initial(int n, List*p)
{
	p->Data = new int[n];
	p->last = 0;
	return true;
}


//插入一个数
void Insert(int X, int i, List *p)
{
	int j;
	for (j = p->last; j >= i - 1; j--) //j为列表长度 i为插入数据所在位置
		p->Data[j + 1] = p->Data[j];   //先移动后面的数值
	p->Data[i - 1] = X;
	p->last++;
}

//有序合并两个线性表
void MergeList(List La, List Lb, List Lc)
{
	int *pa = La.Data;
	int *pb = Lb.Data;
	int *pc = Lc.Data;
	int *t=Lc.Data;
	int *pa_last = La.Data + La.last- 1;
	int *pb_last = Lb.Data + Lb.last- 1;
	while (pa <= pa_last&&pb <= pb_last)
	{
		if (*pa <= *pb)*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last)*pc++ = *pa++;
	while (pb <= pb_last)*pc++ = *pb++;
	for (int i = 0;t<pc; i++,t++)
	{
		cout << Lc.Data[i] << " ";
	}
}

int main()
{
	List La, Lb, Lc;
	MakeEmpty(MAX,&La);
	MakeEmpty(MAX,&Lb);
	Initial(MAX,&Lc);
	MergeList(La, Lb, Lc);
	return 0;
}

