////组队竞赛，关键在最大中间值的选择，为了尽可能大，只需先去除最小值，在剩下的两两一组中尽可能总值大的中间值
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		long long sum = 0;
//		vector<int> v(3 * n);
//		for (int i = 0; i < 3 * n; i++)
//			cin >> v[i];
//		sort(v.begin(), v.end());
//		//为得到最大平均值，取次大的作为中值
//		//将参赛选手的水平进行排序，取[0,n-1]n个数作为最小值，剩下的两个一组，取其中的大的做最大值，
//		//次大的(下标为n,n+2,...,3*n-2)做中间值，并把他们加起来。
//		for (int j = 0; j <= 3 * n - 2; j += 2)
//		{
//			sum += v[j];
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

////删除公共字符
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int hashtable[256] = { 0 };
//	
//	for (int i = 0; i < str2.size(); i++)
//	{
//		// 使用哈希映射思想先将str2中字符出现的次数统计。
//		hashtable[str2[i]]++;
//	}
//	// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在    
//	// str2中没有出现过，则将他+=到ret。    
//	// 这里最好不要str1.erases(i),因为边遍历，边erase，容易出错。  
//	string ret;
//	for (int j = 0; j < str1.size(); j++)
//	{
//		if (hashtable[str1[j]] == 0)//说明这个字符在str2中没有出现过
//			ret += str1[j];
//	}
//	cout << ret << endl;
//	return 0;
//}

////排列子序列
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> v(n);
//		for (int i = 0; i < n; i++)
//			cin >> v[i];
//		int ret = 1;
//		for (int i = 1; i < n - 1; i++)
//		{
//			//找出波峰波谷
//			if ((v[i]>v[i - 1] && v[i]>v[i + 1])
//				|| (v[i] < v[i - 1] && v[i] < v[i + 1]))
//			{
//				ret++;
//				//一个划分区间至少需要划分为2个排序子序列,
//				if (i != n - 3)
//					i++;
//			}
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}


//倒置字符串
//
//第二思路是一个比较讨巧的思路，直接利用cin >> s接收输入，遇到空格就结束了，
//自然就分割开了每个单词，其次将每次接收到的单词拼接到之前串的前面就逆置过来了。
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1,s2;
	cin >> s2;
	while (cin >> s1)
	{
		s2 = s1 + " " + s2;
	}
	cout << s2 << endl;
	return 0;
}

//法二：先将整个字符串逆置过来，再遍历字符串，找出每个单词，对单词逆置。
//这里我们使用了stl算法中的 reverse，所以这里使用迭代器遍历string。
#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std;
int main()
{
	string s;
	// 注意这里要使用getline，cin>>s遇到空格就接收结束了    
	getline(cin, s);
	// 翻转整个句子    
	reverse(s.begin(), s.end());
	// 翻转单词    
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;

		reverse(start, end);
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	system("pause");
	return 0;
}
