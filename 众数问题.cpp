���⣺��һ����Ԫ����ɵı��У����ִ�������Ԫ�س�Ϊ��������дһ��Ѱ���������㷨

������
1�����������ݽ�������
2����ÿ�����ֳ��ֵĵ�һ��λ�ÿ�ʼ������������ֵĴ�������Ϊcount����������������MaxCount�����MaxCount������������λ��index.

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
		cin >> a[i];//��������
		ifs << a[i] << " " << "\n";
	}

	ofstream ofs("output.txt", ios::app);
	if (!ofs)
	{
		cout << "Could not open file!" << endl;
		exit(0);
	}

	while (i < n - 1)//����
	{
		int count = 1;
		int j;
		for (j = i; j < n - 1; j++)
		{
			if (a[j] == a[j + 1])//����������������ȣ�������+1
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
			MaxCount = count;//��ǰ�������
			index = j;//��ǰ�������λ��
		}
		++j;
		i = j;//λ�ú��Ƶ���һ��δ���ֵ�����
	}
	ofs << a[index] << " " << MaxCount << "\n";
	cout << a[index] << " " << MaxCount << endl;
	ifs.close();
	ofs.close();
	system("pause");
	return 0;
}