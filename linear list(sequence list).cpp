#include <iostream>
using namespace std;

#define MAXSIZE 100
//线性表的顺序储存实现 以int型为例
struct List
{
	int Data[MAXSIZE];
	int last;           //用于存放最后一个数据对应的数量
};
List *PtrL;

//建立空的固定空间的线性表
List *MakeEmpty(List *p)
{
	p = new List;
	p->last = 0;
	return p;
}

//建立固定空间的线性表 (元素有序)
List *MakeEmptySeq(int n, List *p)
{
	p = new List;
	p->last = 0;
	int *t = new int[n];  //临时存放数组
	cout << "This is another list,please input int array. Intput 0 to stop:" << endl;
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
	return p;
}


//向表内插入一个数
void Insert(int X, int i, List *p)
{

	int j;
	if (p->last == MAXSIZE - 1)
	{
		cout << "表满" << endl; return;
	}
	if (i<1 || i>p->last + 2)
	{
		cout << "位置不合法" << endl; return;
	}
	for (j = p->last; j >= i - 1; j--) //j为列表长度 i为插入数据所在位置
		p->Data[j + 1] = p->Data[j];   //先移动后面的数值
	p->Data[i - 1] = X;
	p->last++;
	return;
}

//查找一个数，找到则返回标号i，未找到则返回NOT FIND
int Find(int X, List *p)
{
	int i = 0;
	while (i <= p->last && p->Data[i] != X) //若i小于last、未找到X，i++
		i++;
	if (i > p->last)return -1;
	else return i + 1;
}

//删除标号对应的数值
void Delete(int i, List *p)
{
	if (i < 0 || i > p->last)
	{
		cout << "Number " << i << " element dosen't exist" << endl;
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
}

//有序插入一个数
void OrderInsert(int X, List *p)
{
	int i = 0;
	while (i < p->last&&p->Data[i] < X)i++;
	for (int j = p->last - 1; j >= i; j--)
		p->Data[j + 1] = p->Data[j];
	p->Data[i] = X;
	cout << "The subscript of the number:";
	cout << i + 1 << endl; //输出插入数所在的位置
	p->last++;
}
//删除指定元素t
void Delete_num(int t, List *p)
{
	int i = 0, j = 0;
	for (j = 0; j < p->last; j++)
	{
		if (p->Data[j] == t)
		{
			for(int k=j;k<p->last-1;k++)
			p->Data[k] = p->Data[k+1];
			p->last--;
			break;
		}
	}
	cout << "Now,the array is:" << endl;
	for (j = 0; j < p->last; j++)cout << p->Data[j] << " ";
	cout << endl;
}
//删除所有指定元素t
void Delete_num_all(int t, List *p)
{
	int i = 0, j = 0;
	int *a = new int[p->last];
	for (j = 0; j < p->last; j++)
	{
		if (p->Data[j] != t)
		{
			a[i] = p->Data[j];
			i++;
		}
	}
	if (i == j)cout << "-1";
	else
	{
		for (j = 0; j < i; j++)cout << a[j] << " ";
	}
	cout << endl;
}
//有序合并两个线性表
void MergeList(List La, List Lb, List Lc)
{
	int *pa = La.Data;
	int *pb = Lb.Data;
	int *pc = Lc.Data;
	int *t = Lc.Data;
	int *pa_last = La.Data + La.last - 1;
	int *pb_last = Lb.Data + Lb.last - 1;
	while (pa <= pa_last&&pb <= pb_last)
	{
		if (*pa <= *pb)*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last)*pc++ = *pa++;
	while (pb <= pb_last)*pc++ = *pb++;
	cout << "The merged array is:" << endl;
	for (int i = 0; t<pc; i++, t++)
	{
		cout << Lc.Data[i] << " ";
	}
	cout << endl;
}
//删除重复元素
void Delete_rep(List *p)
{
	int k;
	int i = 1;
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

	void Inster(int X, int i, List *p);
	void Delete(int i, List *p);
	int Find(int X, List *p);

	PtrL = MakeEmpty(PtrL);              //建立空表
	int X, i = 1, t;                     //X为目标数，i为下标，t为判断条件

										 //插入数值
	do
	{
		cout << "Please input the target number you want to insert：  ";
		cin >> X;
		Insert(X, i, PtrL);
		i++;
		cout << "Insert  again  input  1 , otherwise  input  0 ：     ";
		cin >> t;
		cout << endl;
	} while (t);
	cout << endl;

	//输出当前表的内容
	cout << "Now,the list is:" << endl;
	for (int i = 0; i < PtrL->last; i++)
		cout << PtrL->Data[i] << "  ";
	cout << endl;
	cout << "The list has " << PtrL->last << " records" << endl;
	cout << endl;

	//查找数值
	cout << "Please input the target number you want to find :";
	int t1, r1;                          //t1: target number  r1:return
	cin >> t1;
	r1 = Find(t1, PtrL);
	if (r1 == -1)cout << "NOT FIND." << endl;
	else cout << "The subscript of the target number is " << r1 << endl; //测试查找函数，输入数值返回下标
	cout << endl;

	//删除数值
	cout << "Please input the subscript of the number you want to delete : ";
	int t2;
	cin >> t2;
	Delete(t2, PtrL);              //delete number
	cout << "Now,the list is:" << endl;
	for (int i = 0; i < PtrL->last; i++)
		cout << PtrL->Data[i] << "  ";
	cout << endl;
	cout << "The list has " << (PtrL->last)<< " records" << endl;

	//删除线性表
	delete PtrL;                   //delete PtrL

	//选做内容：

	//建立新的非降序顺序表
	List l1, l2,l3,l4,l5;
	List *La, *Lb, *Lc,*Ld,*le;
	La = &l1; Lb = &l2; Lc = &l3; Ld = &l4;
	cout << endl << endl;
	cout << "Ordered array :La" << endl;
	La = MakeEmptySeq(MAXSIZE, La);
	//插入一个数
	int X1;     //X1为目标数
	cout << endl;
	cout << "Please input the number you want to insert into La：";
	cin >> X1;
	OrderInsert(X1, La);
	cout << endl;

	//删除指定元素t
	int t11;
	cout << "Please input the number you want to delete from La：";
	cin >> t11;
	Delete_num(t11, La);
	//有序合并两表
	cout << "Please input array,Lb,then you'll get Lc which is La merged with Lb" << endl;
	Lb = MakeEmptySeq(MAXSIZE, Lb);
	Lc = MakeEmpty(Lc);
	MergeList(*La, *Lb, *Lc);
	//删除所有指定元素t
	cout << endl << "Delete all target numbers :" << endl;
	Ld = MakeEmptySeq(MAXSIZE, Ld);
	int t12;
	cout << "Please input the number you want to delete all from La：";
	cin >> t12;
	Delete_num_all(t12, Ld);
	cout << endl;

	//删除重复元素
	cout << endl << "Delete all repeated numbers :" << endl;
	Ld = MakeEmptySeq(MAXSIZE, Ld);
	Delete_rep(Ld);
	cout << endl;
	cout << "END"<<endl;
	return 0;
}
