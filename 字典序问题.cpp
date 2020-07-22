//字典序问题
//思路：字符串对应的序号就是其从小到大排列组合的位置，
//第一，因为字符串是升序排列，所以以第i个字母开头长度为k的字符串的数量
//f（i，k） = sumj = i + 1:26（f（j, k - 1））; 
//求字符串的位置，需要求出其前面有多少字符串，首先找出长度小于给出字符串长度k的所有字符串，
//第二，所有开头字母小于给出字符串开头字母并且长度为k的字符串数量，最后还
//有开头字母相等长度相等但是后面字母小于已给字符串字母的所有字符串。

#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

int f(int i, int k){
	int j;
	int sum = 0;
	if (k == 1){
		return 1;
	}
	else{
		for (j = i + 1; j <= 26; j++){
			sum += f(j, k - 1);
		}
	}
	return sum;
}//第i个字母开头长度为k的数量 
int ca(char a[]){
	int i, j, count, n, length;
	int sum = 0;
	int k = strlen(a);
	for (i = 1; i<k; i++){
		for (int j = 1; j <= 26; j++){
			sum += f(j, i);
		}
	} // 该字符串的位置就是小于k长度的数量，
	int h = a[0] - 'a' + 1;
	for (int i = 1; i<h; i++){
		sum += f(i, k);
	}//加上小于开头字母的长度为k的数量，

	count = h;
	for (i = 1; i<k; i++){
		n = a[i] - 'a' + 1;
		length = k - i;
		for (j = count + 1; j<n; j++){
			sum += f(j, length);
		}
		count = n;
	}//再加上字符串中字母与其后面字母之间字母开头的k-i长度字符串的数量 
	return sum + 1;
}
int main()
{
	int n;
	char a[30];
	long long x;
	scanf("%d", &n);
	getchar();
	while (n--){
		x = 0;
		gets(a);
		x = ca(a);
		printf("%d\n", x);
	}
	system("pause");
	return 0;
}
