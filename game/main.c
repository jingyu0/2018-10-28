#include "game.h"

void Menu()
{
	printf("##########################\n");
	printf("##  ��ӭ�����ҵ�������  ##\n");
	printf("##########################\n");
	printf("##  1. Play    2. Exit  ##\n");
	printf("##########################\n");
	printf("Please Select# ");
}

int main()
{
	int select = 0;
	int quit = 0;
	while (!quit)
	{
		Menu();
		scanf("%d", &select);

		switch (select){
		case 1:
			Game();
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("select error!\n");
			break;
		}
	}
	printf("ByeBye!\n");
	system("pause");
	return 0;
}