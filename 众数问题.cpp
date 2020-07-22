问题：在一个由元素组成的表中，出现次数最多的元素称为众数，试写一个寻找众数的算法

方法：
1）对输入数据进行排序
2）从每个数字出现的第一个位置开始计数，计算出现的次数，记为count，如果大于最大众数MaxCount则更新MaxCount，并记下索引位置index.

#include <iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

int main()
{
	int n;
	int i = 0;
	int MaxCount = 1;
	int index = 0;
	ofstream ifs("input.txt", ios::app);
	cin >> n;
	ifs << n << "\n";
	int* a = new int[n];

	if (!ifs)
	{
		cout << "Could not open file!" << endl;
		exit(0);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];//输入数据
		ifs << a[i] << " " << "\n";
	}

	ofstream ofs("output.txt", ios::app);
	if (!ofs)
	{
		cout << "Could not open file!" << endl;
		exit(0);
	}

	while (i < n - 1)//遍历
	{
		int count = 1;
		int j;
		for (j = i; j < n - 1; j++)
		{
			if (a[j] == a[j + 1])//存在连续两个数相等，则众数+1
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (MaxCount < count)
		{
			MaxCount = count;//当前最大众数
			index = j;//当前众数标记位置
		}
		++j;
		i = j;//位置后移到下一个未出现的数字
	}
	ofs << a[index] << " " << MaxCount << "\n";
	cout << a[index] << " " << MaxCount << endl;
	ifs.close();
	ofs.close();
	system("pause");
	return 0;
}