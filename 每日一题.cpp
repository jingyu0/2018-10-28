////组队竞赛
//#include<stdlib.h>
//#include<iostream> 
//#include<algorithm> 
//#include<vector> 
//using namespace std; 
//int main() 
//{    
//	// IO型OJ可能会有多组测试用例，所以这里要持续接收输入多组测试用例。    
//	int n;   
//	while (cin >> n)    
//	{        
//		long long sum = 0;        
//		vector<int> a;        
//		a.resize(3*n);        
//		for (int i = 0; i < (3 * n); i++)        
//		{            
//			cin >> a[i];        
//		}                
//		/*        排序，然后取下标为3n - 2，3n - 4 ，3n - 4... n+2，n位置的元素累加即可，        
//		相当下标为[0,n-1]的n个数做每组的最左边的数，剩下的2个数据两个为一组，        
//		大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来        */        
//		std::sort(a.begin(), a.end());        
//		for (int i = n; i <= 3 * n - 2; i += 2) 
//		{
//			sum += a[i];
//		}       
//		cout << sum << endl;
//		system("pause");
//	}
//}
//
////删除公共字符
//#include<iostream> 
//#include<string> 
//using namespace std;
//
//int main()
//{
//	// 注意这里不能使用cin接收，因为cin遇到空格就结束了。    
//	// oj中IO输入字符串最好使用getline。    
//	string str1, str2;
//	//cin>>str1;    
//	//cin>>str2;    
//	getline(cin, str1);
//	getline(cin, str2);
//
//	// 使用哈希映射思想先str2统计字符出现的次数    
//	int hashtable[256] = { 0 };
//	for (size_t i = 0; i < str2.size(); ++i)
//	{
//		hashtable[str2[i]]++;
//	}
//	// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在    
//	// str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i)    
//	// 因为边遍历，边erase，容易出错。    
//	string ret;
//	for (size_t i = 0; i < str1.size(); ++i)
//	{
//		if (hashtable[str1[i]] == 0)
//			ret += str1[i];
//	}
//
//	cout << ret << endl;
//	return 0;
//}

////排列子序列
//#include<iostream> 
//#include<vector>
#include<stdlib.h>
//using namespace std; 
//int main() 
//{
//	int n;    
//	cin >> n;    
//	vector<int> v;    
//	v.resize(n);    
//	for (int i = 0; i < n; ++i)        
//		cin >> v[i];
//	int ret = 1;
//	for (int i = 1; i<n - 1; i++)
//	{
//		//找出波峰波谷        
//		if ((v[i - 1] < v[i] && v[i] > v[i + 1]) || (v[i - 1] > v[i] && v[i] < v[i + 1]))
//		{
//			ret++;
//			// 处理特例     
//			if (i != n - 3)
//				i++;
//		}
//	}
//	cout << ret << endl;
//	system("pause");
//}

//字符串逆置【法一】
//先将整个字符串逆置过来，再遍历字符串，找出每个单词，对单词逆置。
//这里我们使用了stl算法中的 reverse，所以这里使用迭代器遍历string。
//#include <iostream> 
//#include <string> 
//#include <algorithm> 
//using namespace std;
//int main()
//{
//	string s;
//	// 注意这里要使用getline，cin>>s遇到空格就接收结束了    
//	getline(cin, s);
//	// 翻转整个句子    
//	reverse(s.begin(), s.end());
//	// 翻转单词    
//	auto start = s.begin();
//	while (start != s.end())
//	{
//		auto end = start;
//		while (end != s.end() && *end != ' ')
//			end++;
//
//		reverse(start, end);
//		if (end != s.end())            
//			start = end + 1;        
//		else            
//			start = end;
//	}
//	cout << s << endl;
//	system("pause");
//	return 0;
//}
//
////法二
//#include <iostream> 
//#include <string> 
//using namespace std; 
//// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出 
//int main() 
//{    
//	string s1, s2;    
//	cin >> s2;    
//	while (cin >> s1)        
//		s2 = s1  + " " + s2;    
//	cout << s2 << endl;    
//	return 0; 
//}

////Fibcount数列记步数
//#include <iostream>
//#include<algorithm>
//#include<math.h>
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//
//	int one = 0;
//	int two = 1;
//	while (1) {
//		if (N >= one && N <= two) {
//			cout << min(two - N, N - one) << endl;
//			break;
//		}
//		//执行数的转化（赋新的两数）
//		int sum = one + two;//前两个数的和赋给的三个数
//		one = two;
//		two = sum;
//	}
//	system("pause");
//	return 0;
//}
//	

////合法括号序列判断
//class Parenthesis {
//public:
//	bool chkParenthesis(string A, int n) {
//		// write code here
//		if (n % 2 != 0)
//			return false;
//		int lnum = 0;
//		int rnum = 0;
//		int num = 0;
//		for (int i = 0; i<n; i++)
//		{
//			if (A[i] == '(')
//				lnum++;
//			else if (A[i] == ')')
//				rnum++;
//			else
//				return false;
//			num = lnum - rnum;
//			if (num<0)
//				return false;
//		}
//		return num == 0;
//	}
//};

//两种排序方式
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isdict(vector<string> str, int n)
{
	vector<string> res;
	res = str;
	sort(res.begin(), res.end()); //默认sort容器就是根据字符串的字典序排序
	for (int i = 0; i<n; ++i){
		if (str[i] != res[i]){
			return false;
			break;
		}
	}
	return true;
}
bool compare(string a, string b){
	return a.size()<b.size();//按照升序来排序，若是按照降序，则为return a.size()>b.size()
}
bool islen(vector<string> str, int n){
	vector<string> res;
	res = str;
	sort(res.begin(), res.end(), compare); //自己定义一个sort容器，根据每个字符串的长度来排序
	for (int i = 0; i<n; ++i){
		if (str[i] != res[i]){
			return false;
			break;
		}
	}
	return true;
}
int main(){
	int n;
	string s;
	vector<string> str;
	cin >> n;
	for (int i = 0; i<n; ++i){
		cin >> s;
		str.push_back(s);
	}
	if (isdict(str, n) && islen(str, n))
		cout << "both";
	if ((isdict(str, n) == 0) && (islen(str, n) == 0))
		cout << "none";
	if ((isdict(str, n) == 1) && (islen(str, n) == 0))
		cout << "lexicographically";
	if ((isdict(str, n) == 0) && (islen(str, n) == 1))
		cout << "lengths";
	system("pause");
	return 0;
}