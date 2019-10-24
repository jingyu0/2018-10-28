#include "game.h"

//yes -> 1, no -> 0
static int IsFull(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			if (board[i][j] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
static int Guess()
{
	int data = rand() % 2;
	printf("������������< 0:���棬1: ����># ");
	int x = 0;
	scanf("%d", &x);
	if (x == data){
		printf("��¶��ˣ�������!\n");
		return 1;
	}
	printf("��´��ˣ��������ߣ�\n");
	return 2;
}
void InitBoard(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			board[i][j] = INIT;
		}
	}
}

void ShowBoard(char board[][COL], int row, int col)
{
	printf("  | 1 | 2 | 3 |\n");
	printf("---------------\n");
	int i = 0;
	for (; i < row; i++){
		int j = 0;
		printf("%d |", i+1);
		for (; j < col; j++){
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		printf("---------------\n");
	}
	//printf("-------------\n");
}

//'X','O', 'F', 'N'
char Judge(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++){
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' '){
			return board[i][0];
		}
	}
	for (i=0; i < col; i++){
		if (board[0][i] == board[1][i] && \
			board[1][i] == board[2][i] && \
			board[0][i] != ' '){
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && \
		board[1][1] != ' '){
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && \
		board[1][1] != ' '){
		return board[1][1];
	}
	if (IsFull(board, row, col)){
		return 'F';
	}
	return 'N';
}

void ComputerMove(char board[][COL], int row, int col)
{
	while (1){
		Sleep(rand()%500+100);
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' '){
			board[x][y] = C_CLR;
			break;
		}
	}
	printf("���������ˣ������ˣ�\n");
}

void Game()
{
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	int x = 0;
	int y = 0;
	char win = ' ';
	srand((unsigned long)time(NULL));
	int step = Guess();//first == 1,player else == 2 computer
	do{
		ShowBoard(board, ROW, COL);
		switch (step){
		case 1:
		{
				  while (1){
					  printf("�������������λ��<x, y># ");
					  scanf("%d %d", &x, &y); //[1, 3]
					  if (x <= 0 || x > 3 || y <= 0 || y > 3){
						  printf("�������λ���������������룡\n");
						  continue;
					  }
					  if (board[x - 1][y - 1] != ' '){
						  printf("�������λ���Ѿ���ռ�ã����������룡\n");
						  continue;
					  }
					  board[x - 1][y - 1] = P_CLR;
					  printf("�������ˣ��ȵȵ���!\n");
					  break;
				  }
				  step = 2;
		}
			break;
		case 2:
			ComputerMove(board, ROW, COL);
			step = 1;
			break;
		default:
			break;
		}
		win = Judge(board, ROW, COL); //'X','O', 'F', 'N'
		if (win != 'N'){
			break;
		}
	} while (1);
	ShowBoard(board, ROW, COL);

	if (win == P_CLR){
		printf("��ϲ�㣬��Ӯ��!\n");
	}
	else if (win == C_CLR){
		printf("������˼������Ӯ�ˣ�\n");
	}
	else{
		printf("������ƽ��!\n");
	}
}