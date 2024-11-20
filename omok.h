#include <stdio.h>
#include <stdlib.h>

typedef struct cord_list
{
	struct cord_list *prev;
	struct cord_list *next;
	int x;
	int y;
} cord_list;

