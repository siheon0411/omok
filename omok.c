#include <stdio.h>
#include <stdlib.h>

void get_cor(int *x, int *y)
{
	printf("x y: "); scanf("%d %d", x, y);
	
	return ;
}

void put_star(char **board, int h, int w)
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

void print_star(char **board, int h, int w)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	return ;
}

int main()
{
	int x, y;
	char flag = 'K';
	int h = 10;
	int w = 10;
	char **board = (char **)calloc(h, sizeof(char *));
	if (!board)
		return 1;
	for (int i = 0; i < h; i++){
		board[i] = (char *)calloc(w, sizeof(char));
		if (!board[i]){
			exit(0);
		}
	}
	put_star(board, h, w);
	while (1){
		print_star(board, h, w);
		get_cor(&x, &y);
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

