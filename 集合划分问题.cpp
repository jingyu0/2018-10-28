//���ϻ�������
//�㷨��ƣ�����������n, m, �����n��Ԫ�صļ���{1��2��3,...,n}���Ի���Ϊ���ٸ���ͬ����m���ǿռ�����ɵļ��ϡ�
//�������룺���ļ�input.txt�ṩ�������ݡ��ļ��ĵ�һ����Ԫ�ظ���n�ͷǿ��Ӽ���m��
//�����������������Ĳ�ͬ����m���ǿ��Ӽ���ɵļ����������output.txt��

//�㷨��ƣ�
//����F(n, m)��ʾΪ��n��Ԫ�صļ��ϻ��ֳ���m���Ӽ����ɵļ��ϵĸ�����
//�ɷ�Ϊ���¼��������

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int F(int n, int m)
{
	//1����m = 1, f(n, m) = 1;
	//2)��n = m, f(n, m) = 1;
	if (m == 1 || n == m)
	{
		return 1;
	}
	//3)F(n,m)���������������������
	//a. ��n - 1��Ԫ�ػ��ֳ�m�����������һ���µ�Ԫ�أ���m*F(n-1,m)�������
	//b.��n - 1��Ԫ�ػ��ֳ�m - 1�����������һ����һ��Ԫ���γɵĶ����ļ���, ����F(n-1,m-1)�ַ�����
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
