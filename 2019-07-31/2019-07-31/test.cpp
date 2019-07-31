//#include <stdio.h>
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
////int main()
////{
////	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 }, *p; int i;
////	i = 8;
////	p = a + i;  //指针p指向数组的第九位；a为一个char类型的数组，也是数组首元素的地址。
////	printf("%s\n", p - 3); //p-3指向数组第六位的地址，输出字符。最后一位0是int类型,解析为'/0'。
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
//等价于
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
//			//itor第一次指向第一个300，第二次指向第三个300，第三次指向500
//			//在判断内部给它赋值下一位置后，循环外部又加1。前后加了两次，前后只删去了两个300。
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << "";
//	}
//	return 0;
//}

////字符串中找出连续最长的数字串
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

//n个数里出现次数大于等于n/2的数
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
//		//过半的数至少会和相邻值重复一次，v[i]保存的是过半的数
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

