////��Ӿ���
//#include<stdlib.h>
//#include<iostream> 
//#include<algorithm> 
//#include<vector> 
//using namespace std; 
//int main() 
//{    
//	// IO��OJ���ܻ��ж��������������������Ҫ������������������������    
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
//		/*        ����Ȼ��ȡ�±�Ϊ3n - 2��3n - 4 ��3n - 4... n+2��nλ�õ�Ԫ���ۼӼ��ɣ�        
//		�൱�±�Ϊ[0,n-1]��n������ÿ�������ߵ�����ʣ�µ�2����������Ϊһ�飬        
//		���ֵ�����ұߵ������δ�����м�ֵ��������ǰ�����δ��ֵ������        */        
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
////ɾ�������ַ�
//#include<iostream> 
//#include<string> 
//using namespace std;
//
//int main()
//{
//	// ע�����ﲻ��ʹ��cin���գ���Ϊcin�����ո�ͽ����ˡ�    
//	// oj��IO�����ַ������ʹ��getline��    
//	string str1, str2;
//	//cin>>str1;    
//	//cin>>str2;    
//	getline(cin, str1);
//	getline(cin, str2);
//
//	// ʹ�ù�ϣӳ��˼����str2ͳ���ַ����ֵĴ���    
//	int hashtable[256] = { 0 };
//	for (size_t i = 0; i < str2.size(); ++i)
//	{
//		hashtable[str2[i]]++;
//	}
//	// ����str1��str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ���    
//	// str2��û�г��ֹ�������+=��ret��ע��������ò�Ҫstr1.erases(i)    
//	// ��Ϊ�߱�������erase�����׳���    
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

////����������
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
//		//�ҳ����岨��        
//		if ((v[i - 1] < v[i] && v[i] > v[i + 1]) || (v[i - 1] > v[i] && v[i] < v[i + 1]))
//		{
//			ret++;
//			// ��������     
//			if (i != n - 3)
//				i++;
//		}
//	}
//	cout << ret << endl;
//	system("pause");
//}

//�ַ������á���һ��
//�Ƚ������ַ������ù������ٱ����ַ������ҳ�ÿ�����ʣ��Ե������á�
//��������ʹ����stl�㷨�е� reverse����������ʹ�õ���������string��
//#include <iostream> 
//#include <string> 
//#include <algorithm> 
//using namespace std;
//int main()
//{
//	string s;
//	// ע������Ҫʹ��getline��cin>>s�����ո�ͽ��ս�����    
//	getline(cin, s);
//	// ��ת��������    
//	reverse(s.begin(), s.end());
//	// ��ת����    
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
////����
//#include <iostream> 
//#include <string> 
//using namespace std; 
//// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢����������� 
//int main() 
//{    
//	string s1, s2;    
//	cin >> s2;    
//	while (cin >> s1)        
//		s2 = s1  + " " + s2;    
//	cout << s2 << endl;    
//	return 0; 
//}

////Fibcount���мǲ���
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
//		//ִ������ת�������µ�������
//		int sum = one + two;//ǰ�������ĺ͸�����������
//		one = two;
//		two = sum;
//	}
//	system("pause");
//	return 0;
//}
//	

////�Ϸ����������ж�
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

//��������ʽ
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isdict(vector<string> str, int n)
{
	vector<string> res;
	res = str;
	sort(res.begin(), res.end()); //Ĭ��sort�������Ǹ����ַ������ֵ�������
	for (int i = 0; i<n; ++i){
		if (str[i] != res[i]){
			return false;
			break;
		}
	}
	return true;
}
bool compare(string a, string b){
	return a.size()<b.size();//�����������������ǰ��ս�����Ϊreturn a.size()>b.size()
}
bool islen(vector<string> str, int n){
	vector<string> res;
	res = str;
	sort(res.begin(), res.end(), compare); //�Լ�����һ��sort����������ÿ���ַ����ĳ���������
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