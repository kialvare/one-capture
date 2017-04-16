#ifndef THING_H
# define THING_H
# define SQUARE_BLUE 0
# define SQUARE_RED 1

typedef struct board_s
{
	int 	width;
	int 	height;
	int 	**squares;
}	board_t;

typedef struct level_s
{
	board_t *board;
	int moves;
} level_t;

#endif
