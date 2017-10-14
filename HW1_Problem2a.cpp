#include <iostream>
using namespace std;

int n;  //n为固定线性表元素个数
struct List
{
	int *Data;
	int last;
};
List *PtrL;

List *MakeEmpty(int n)
{
	PtrL = new List;
	PtrL->Data = new int[n];
	PtrL->last = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> PtrL->Data[i];
		PtrL->last++;
	}
	return PtrL;
}
//删除所有此数值
void Delete(List *p)
{
	int k;
	int i=1;
	int *a = new int[p->last]; //a[n]存放结果 
	a[0] = p->Data[0];         //将第一个元素放入a[0] 
	for (int j = 1; j < p->last; j++) //j=1 从第2个元素开始比较 
	{
		for (k = 0; k < i; k++)
		{
			if (p->Data[j] == a[k])break; //如果Data[j]与其前的元素相等，则跳过Data[j] 
		}
		if (k == i)  //如果没有找到相等元素 则将Data[j]放入a[i]中 
		{
			a[i] = p->Data[j];
			i++;
		}
	}
	for (int k = 0; k < i; k++)
		cout << a[k] << " ";
	cout << endl;
}


int main()
{
	List *MakeEmpty(int n);
	cin >> n;                //n为固定线性表元素个数
	PtrL = MakeEmpty(n);

	//删除重复元素
	Delete(PtrL);

	return 0;
}
