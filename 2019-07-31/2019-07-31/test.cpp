//#include <stdio.h>
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
////int main()
////{
////	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 }, *p; int i;
////	i = 8;
////	p = a + i;  //ָ��pָ������ĵھ�λ��aΪһ��char���͵����飬Ҳ��������Ԫ�صĵ�ַ��
////	printf("%s\n", p - 3); //p-3ָ���������λ�ĵ�ַ������ַ������һλ0��int����,����Ϊ'/0'��
////}
//
//int func()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; i++, j++)
//	{
//		k++;
//	}
//	return k;
//}
//int main()
//{
//	cout << (func());
//}

//for (i = 0, j = -1; j = 0; i++, j++)
//�ȼ���
//int i = 0, j = -1;
//while (j = 0)
//{
//	i++;
//	j++;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//			//itor��һ��ָ���һ��300���ڶ���ָ�������300��������ָ��500
//			//���ж��ڲ�������ֵ��һλ�ú�ѭ���ⲿ�ּ�1��ǰ��������Σ�ǰ��ֻɾȥ������300��
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << "";
//	}
//	return 0;
//}

////�ַ������ҳ�����������ִ�
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		string tmps;
//		string maxs;
//		int maxsize = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			while (s[i] >= '0'&&s[i] <= '9')
//			{
//				tmps += s[i];
//				i++;
//			}
//			if (maxsize < tmps.size())
//			{
//				maxs = tmps;
//				maxsize = tmps.size();
//			}
//			tmps.clear();
//		}
//		cout << maxs << endl;
//	}
//	return 0;
//}

//n��������ִ������ڵ���n/2����
//#include <vector> 
//#include <iostream> 
//#include <algorithm> 
//using namespace std;
//int main()
//{
//	int n;
//	vector <int> v;
//	while (cin >> n)
//		v.push_back(n);
//	sort(v.begin(), v.end());
//	cout << v[v.size() / 2 - 1] << endl;
//	return 0;
//}

//#include <vector> 
//#include <stdlib.h>
//#include <iostream> 
//using namespace std;
//int main()
//{
//	int n;
//	vector <int> v;
//	while (cin >> n)
//		v.push_back(n);
//	int count = 1;
//	int temp = v[0];
//	for (int i = 1; i < v.size(); ++i)
//	{
//		if (v[i] == temp)
//			count++;
//		else
//			count--;
//		//����������ٻ������ֵ�ظ�һ�Σ�v[i]������ǹ������
//		if (count == 0)
//		{
//			temp = v[i];
//			count++;
//		}
//	}
//	cout << temp << endl;
//	system("pause");
//	return 0;
//}

