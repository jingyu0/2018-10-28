#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
using namespace std;
////int fun(int a)
////{
////	a ^= (1 << 5) - 1;
////	return a;
////}
////void func(char **m)
////{
////	++m;
////	cout << *m << endl;
////}
//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x&(x - 1);
//	}
//	cout << count << endl;
//	return count;
//}
//int main()
//{
//	/*static char *a[] = { "marning", "afternoon", "evening" };
//	char **p;
//	p = a;
//	func(p);*/
//	//int n = 21;
//	//fun(n);
//	func(9999);
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class MyClass{
//public:
//	MyClass(int i = 0){ cout << 1; }
//	MyClass(const MyClass&x){ cout << 2; }
//	MyClass& operator=(const MyClass& x){ cout << 3; return *this; }
//	~MyClass(){ cout << 4; }
//};
//int main()
//{
//	MyClass obj1(1),obj2(2),obj3(obj1);
//	system("pause");
//	return 0;
//}

////另类加法
//class UnusualAdd {
//public:
//	int addAB(int A, int B) {
//		// write code here
//		//A是进位，B是结果。
//		while (A)
//		{
//			int temp = B;
//			B = A^B;//异或表示不考虑进位时的结果
//			A = (A&temp) << 1;//右移一位表示进位值
//		}
//		//当进位值为0时，结果单为B。
//		return B;
//	}
//};

//struct A{
//	void foo(){ printf("foo"); }
//	virtual void bar(){ printf("bar"); }
//	A(){ bar(); }
//};
//struct B :A{
//	void foo(){ printf("b_foo"); }
//	void bar(){ printf("b_bar"); }
//};
//int main()
//{
//	A*p = new B;
//	p->foo();
//	p->bar();
//	system("pause");
//	return 0;
//}
////输出barfoob_bar

//class Printer{
//public:
//	Printer(std::string name){ std::cout << name << endl;}
//};
//class Container{
//public:
//	Container() :b("b"), a("a"){}
//	Printer a;
//	Printer b;
//};
//
//int main()
//{
//	Container c;
//	system("pause");
//	return 0;
//}

////C++ 井字棋
//class Board {
//public:
//	bool checkWon(vector<vector<int> > a) {
//		if (a[0][0] + a[1][1] + a[2][2] == 3) return true;
//		if (a[0][2] + a[1][1] + a[2][0] == 3) return true;
//		for (int i = 0; i<3; i++){
//			if (a[i][0] + a[i][1] + a[i][2] == 3) return true;
//			if (a[0][i] + a[1][i] + a[2][i] == 3) return true;
//		}
//		return false;
//	}
//};

//密码强度等级
//输入：38$@NoNoNo
//输出：VERY_SECURE
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string password;
	while (getline(cin, password))
	{
		int score = 0;
		//密码长度得分
		if (password.size() <= 4){
			score += 5;
		}
		else if (password.size() >= 8){
			score += 25;
		}
		else{
			score += 10;
		}
		//字母、数字、符号统计
		int Alpha = 0, alpha = 0, number = 0, number_count = 0, ch = 0, ch_count = 0;
		for (int i = 0; i<password.size(); i++)
		{
			if (password[i] >= 'a' && password[i] <= 'z'){
				alpha = 1;
			}
			else if (password[i] >= 'A' && password[i] <= 'Z'){
				Alpha = 1;
			}
			else if (isdigit(password[i])){
				number = 1;
				number_count++;
			}
			else{
				ch = 1;
				ch_count++;
			}
		}
		//字母得分
		if ((alpha == 1 && Alpha == 0) || (alpha == 0 && Alpha == 1)){
			score += 10;
		}
		else if (alpha == 1 && Alpha == 1){
			score += 20;
		}
		//数字得分
		if (number_count>1){
			score += 20;
		}
		else if (number){
			score += 10;
		}
		//符号得分
		if (ch_count>1){
			score += 25;
		}
		else if (ch){
			score += 10;
		}
		//奖励得分
		if (Alpha && alpha && number && ch){
			score += 5;
		}
		else if ((Alpha || alpha) && number && ch){
			score += 3;
		}
		else if ((Alpha || alpha) && number){
			score += 2;
		}
		if (score >= 90){
			cout << "VERY_SECURE" << endl;
		}
		else if (score >= 80){
			cout << "SECURE" << endl;
		}
		else if (score >= 70){
			cout << "VERY_STRONG" << endl;
		}
		else if (score >= 60){
			cout << "STRONG" << endl;
		}
		else if (score >= 50){
			cout << "AVERAGE" << endl;
		}
		else if (score >= 25){
			cout << "WEAK" << endl;
		}
		else{
			cout << "VERY_WEAK" << endl;
		}
	}
	return 0;
}
