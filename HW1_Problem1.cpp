#include <iostream>
using namespace std;

int n;  //n为固定线性表元素个数
struct List
{
	int *Data;
	int last;         
};
List *PtrL;
//建立空表
List *MakeEmpty(int n)
{
	PtrL = new List;
	PtrL->Data = new int[n];
	PtrL->last = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> PtrL->Data[i];
		PtrL->last++;
	} 	//输出当前线性表
	for (int i = 0; i < PtrL->last; i++)
		cout << PtrL->Data[i] <<" ";
	cout<<endl; 
	return PtrL;
}
//插入一个数
void Insert(int X, int i, List *p)
{

	int j;
	if (p->last == n - 1)
	{
		cout << "-1" << endl; return;
	}
	if (i<1 || i>p->last + 2)
	{
		cout << "-1" << endl; return;
	}
	for (j = p->last; j >= i - 1; j--) //j为列表长度 i为插入数据所在位置
		p->Data[j + 1] = p->Data[j];   //先移动后面的数值
	p->Data[i - 1] = X;
	p->last++;
	for (int i = 0; i < p->last; i++)
		cout << p->Data[i]<<" ";
	cout << endl;
	return;
}

//删除标号对应的数值
void Delete(int i, List *p)
{
	if (i < 0 || i > p->last)
	{
		cout << "-1" << endl;
		return;
	}
	else
	{
		for (int j = i; j <= p->last; j++)
		{
			p->Data[j - 1] = p->Data[j];
		}
	}
	p->last--;
	for (int t = 0; t < p->last; t++)
		cout << p->Data[t]<<" ";
	cout << endl;
}

//查找一个数，找到则返回标号i，未找到则返回-1
int Find(int X, List *p)
{
	int i = 0;
	while (i <= p->last && p->Data[i] != X) //若i小于last、未找到X，i++
		i++;
	if (i > p->last)return -1;
	else return i + 1;
}

int main()
{
	List *MakeEmpty(int n);
	cin >> n;                //n为固定线性表元素个数
	PtrL = MakeEmpty(n);
	

	//插入一个数
	int X,i;     //X为目标数，i为下标
	cin >> i >> X;
	Insert(X, i, PtrL);
	//删除一个数
	int t2;
	cin >> t2;
	Delete(t2, PtrL);
	//查找一个数
	int t1;
	cin >> t1;
	cout<< Find(t1, PtrL);
	return 0;
}
