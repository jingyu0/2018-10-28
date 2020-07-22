//集合划分问题
//算法设计：给定正整数n, m, 计算出n个元素的集合{1，2，3,...,n}可以划分为多少个不同的由m个非空集合组成的集合。
//数据输入：由文件input.txt提供输入数据。文件的第一行是元素个数n和非空子集数m。
//数据输出：将计算出的不同的由m个非空子集组成的集合数输出到output.txt。

//算法设计：
//假设F(n, m)表示为将n个元素的集合划分成由m个子集构成的集合的个数。
//可分为以下几种情况：

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int F(int n, int m)
{
	//1）若m = 1, f(n, m) = 1;
	//2)若n = m, f(n, m) = 1;
	if (m == 1 || n == m)
	{
		return 1;
	}
	//3)F(n,m)可以由下面两种情况构成
	//a. 向n - 1个元素划分成m个集合里添加一个新的元素，则m*F(n-1,m)种情况。
	//b.向n - 1个元素划分成m - 1个集合里添加一个由一个元素形成的独立的集合, 则有F(n-1,m-1)种方法。
	else
	{
		return F(n - 1, m - 1) + m*F(n - 1, m);
	}
}
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	ofstream ifs("input.txt", ios::app);
	if (!ifs)
	{
		cout << "Could not open file!" << endl;
		exit(0);
	}
	ifs << n << " " << m;
	ofstream ofs("output.txt", ios::app);
	if(!ofs)
	{
		cout << "Could not open file!" << endl;
		exit(0);
	}
	ofs << F(n, m)<<"\n";
	cout << F(n, m) << endl;
	ifs.close();
	ofs.close();
	system("pause");
	return 0;
}
