#include "omok.h"

int h = 10;
int w = 10;
char flag = 'K';

int is_right_cord(int x)
{
	if (x < h && x > 0)
		return 1;
	return 0; 
}

void get_cor(char **board, int *x, int *y)
{
	int flag = 1;
	do {
		if (flag == 'K') printf("Player1's turn: ");
		else printf("Player2's turn: ");
		printf("x y: "); scanf("%d %d", x, y);
		if (!is_right_cord(*x) || !is_right_cord(*y))
		{
			printf("out of coordination. do again\n");
			continue;
		}
		if (board[*y][*x] == '*')
			flag = 0;
		else{
			printf("Already exising coordination. do again\n");
			continue;
		}
	}while(flag);
	return ;
}

void put_star(char **board)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			board[i][j] = '*';
		}
	}
	board[0][0] = ' ';
	for (int i = 1 ; i < w; i++)
	{
		board[0][i] = '0' + i;
	}
	for (int i = 1; i < h; i++)
	{
		board[i][0] = '0' + i;
	}
	return ;
}

void print_star(char **board)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (i == 0 && j == 0)
				printf("  ");
			else if (i == 0)
				printf("%d ", j);
			else if (j == 0)
				printf("%d ", i);
			else
				printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	return ;
}

int main()
{
	int x, y;
	char **board = (char **)calloc(h, sizeof(char *));
	if (!board)
		return 1;
	for (int i = 0; i < h; i++){
		board[i] = (char *)calloc(w, sizeof(char));
		if (!board[i]){
			exit(0);
		}
	}
	put_star(board);
	while (1){
		print_star(board);
		get_cor(board, &x, &y);
		if (flag == 'K')
		{
			flag = 'O';
			board[y][x] = 'O';
		}
		else
		{
			flag = 'K';
			board[y][x] = 'X';
		}
	}
	return 0;
}

