#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <time.h>
#include <windows.h>

#pragma warning(disable:4996)

//C语言实现三子棋小游戏
#define ROW 3
#define COL 3

#define P_CLR 'X'
#define C_CLR 'O'
#define INIT ' '

void InitBoard(char board[][COL], int row, int col);
void ShowBoard(char board[][COL], int row, int col);
//'X','O', 'F', 'N'
char Judge(char board[][COL], int row, int col); 
void ComputerMove(char board[][COL], int row, int col);
void Game();

#endif