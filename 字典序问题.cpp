//�ֵ�������
//˼·���ַ�����Ӧ����ž������С����������ϵ�λ�ã�
//��һ����Ϊ�ַ������������У������Ե�i����ĸ��ͷ����Ϊk���ַ���������
//f��i��k�� = sumj = i + 1:26��f��j, k - 1����; 
//���ַ�����λ�ã���Ҫ�����ǰ���ж����ַ����������ҳ�����С�ڸ����ַ�������k�������ַ�����
//�ڶ������п�ͷ��ĸС�ڸ����ַ�����ͷ��ĸ���ҳ���Ϊk���ַ������������
//�п�ͷ��ĸ��ȳ�����ȵ��Ǻ�����ĸС���Ѹ��ַ�����ĸ�������ַ�����

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
}//��i����ĸ��ͷ����Ϊk������ 
int ca(char a[]){
	int i, j, count, n, length;
	int sum = 0;
	int k = strlen(a);
	for (i = 1; i<k; i++){
		for (int j = 1; j <= 26; j++){
			sum += f(j, i);
		}
	} // ���ַ�����λ�þ���С��k���ȵ�������
	int h = a[0] - 'a' + 1;
	for (int i = 1; i<h; i++){
		sum += f(i, k);
	}//����С�ڿ�ͷ��ĸ�ĳ���Ϊk��������

	count = h;
	for (i = 1; i<k; i++){
		n = a[i] - 'a' + 1;
		length = k - i;
		for (j = count + 1; j<n; j++){
			sum += f(j, length);
		}
		count = n;
	}//�ټ����ַ�������ĸ���������ĸ֮����ĸ��ͷ��k-i�����ַ��������� 
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
